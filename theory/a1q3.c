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


    int max_size = 0;
    int min_size = 100;
    int tmp=0;

    int max_end_index=0;
    int min_end_index=0;
    
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' ' || str[i]=='\0'){
            if(max_size<tmp){
                max_size=tmp;
                max_end_index=i;
            }
            if(min_size>tmp && tmp>1){
                min_size=tmp;
                min_end_index=i;
            }
            tmp=0;
        }
        else
            tmp++;
    }

    if(max_size<tmp){
        max_size=tmp;
        max_end_index=strlen_fxn(str);
    }
    if(min_size>tmp){
        min_size=tmp;
        min_end_index=strlen_fxn(str);
    }


    //printf("%d\n%d\n",min_size,max_size);

    int max_start_index = max_end_index-max_size;
    int min_start_index = min_end_index-min_size;

    printf("max size string is : ");
    for(int i=0;str[i]!='\0';i++){
        if(i>max_start_index-1 && i<max_end_index){
            printf("%c",str[i]);
        }
    }

    printf("\n");

    printf("min size string is : ");
    for(int i=0;str[i]!='\0';i++){
        if(i>min_start_index-1 && i<min_end_index){
            printf("%c",str[i]);
        }
    }
    

    printf("\n");
    free(str);


    return 0;
}