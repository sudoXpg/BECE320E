#include <stdio.h>
#include <stdlib.h>

#define MAX_LIMIT 1000
#define MEMFAULT -1


int EOL_index(const char *s){
    int len=0;
    while(s[len]!='\n' && s[len]!='\0'){
        len++;
    }
    return len;
}

int strlen_fxn(const char *s){
    int len=0;
    while(s[len]!='\0'){
        len++;
    }
    return len;
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

    int words=0;

    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' ' || str[i]=='\0'){
            words++;
        }
    }

    printf("Number of Words : %d\n",words);

    return 0;    

}