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



void reverse_str(char *str, int start_index, int end_index){
    while (start_index < end_index) {
        char temp = str[start_index];
        str[start_index] = str[end_index];
        str[end_index] = temp;
        start_index++;
        end_index--;
    }
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

    int start_index=0;
    int len = 0;


    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i + 1] == '\0') {
            int end_index = (str[i + 1] == '\0') ? i : i - 1;
            reverse_str(str, start_index, end_index);
            start_index = i + 1;
            len = 0;
        }
        else
            len++;
    }


    printf("Modified string is : %s\n",str);

    return 0;
}