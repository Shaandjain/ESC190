#include <stdio.h>
#include <string.h>
#include <ctype.h>

int my_atoi(char *str){
    int i = 0;
    int num = 0;
 
    while (*str != '\0'){
        if(isdigit(*str)){
            num = num * 10 + (*str - '\0');
        }
        str++;
    }
    return num;
}



int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("%d\n", my_atoi(str));
    return 0;
}


