#include <stdio.h>

int get_length(char *str){
    int length = 0;

    while (str[length] != '\0'){
        length ++;
    }
    return length;
}

int main(){
    char *str = "python";
    printf("The length of the string is %d\n", get_length(str));
}

