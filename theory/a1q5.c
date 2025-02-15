#include <stdio.h>
#include <stdlib.h>

#define MAX_LIMIT 1000
#define MEMFAULT -1
#define CONVERT_INDEX 32


int EOL_index(const char *s){
    int len=0;
    while(s[len]!='\n' && s[len]!='\0'){
        len++;
    }
    return len;
}

char capitalise(char c){
    char c1 = c;
    if(c1>='a' && c1<='z'){
        c1 = c1 - CONVERT_INDEX;
    }

    return c1;
}

int main(void){

    char *str = malloc(MAX_LIMIT * sizeof(char));
    if(!str){
        printf("mem fault \n");
        return MEMFAULT;
    }

    printf("Enter the input string : ");
    fgets(str, MAX_LIMIT, stdin);

    int EOL_str = EOL_index(str);
    str[EOL_str] = '\0';

    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' '){
            str[i+1] = capitalise(str[i+1]);
        }
    }

    printf("Modified string : %s\n",str);
    
    return 0;
}