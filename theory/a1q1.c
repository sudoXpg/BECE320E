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
    char *word = malloc(MAX_LIMIT * sizeof(char));
    char *new_str = malloc(MAX_LIMIT * sizeof(char));


    if(!str || !word || !new_str){
        printf("mem fault \n");
        return MEMFAULT;
    }

    printf("Enter the input string : ");
    fgets(str, MAX_LIMIT, stdin);

    printf("Enter word to remove : ");
    fgets(word, MAX_LIMIT, stdin);

    int EOL_str = EOL_index(str);
    int EOL_word = EOL_index(word);

    str[EOL_str] = '\0';
    word[EOL_word] = '\0';

    //printf("%s\n%s\n",str,word);

    int start_index = 0;
    int flag = 0;

    int str_len = strlen_fxn(str);
    int word_len = strlen_fxn(word);

    for(int i=0;str[i]!='\0';i++){
        if(str[i]==word[0]){
            start_index=i;
            for(int j=0;word[j]!='\0';j++){
                if(i+j>str_len) break;

                if(str[i+j]!=word[j]){
                    flag=-1;
                    break;
                }
                flag = 1;
            }
            if(flag==1){
                break;
            }
        }
    }

    int new_str_index = 0;

    for(int i=0;str[i]!='\0';i++){
        if(i>start_index-1 && i <(start_index+word_len)) continue;
        new_str[new_str_index] = str[i];
        new_str_index++;
    }

    printf("%s\n%s\n",str,new_str);
    
    free(str);
    free(word);
    free(new_str);

    return 0;

}