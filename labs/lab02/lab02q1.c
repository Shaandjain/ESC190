#include <stdio.h>
#include <stdlib.h>

void getInput(char **str, int *length){
    printf("Enter the length of the string: ");
    scanf("%d", length);

    *str = (char *) malloc(sizeof(char) * (*length + 1));
    printf("Enter the string character by character: ");
    for(int i = 0; i < *length; i++) {
        scanf(" %c", (*str + i)); 
    }
    *(*str + *length) = '\0';
}

int main(){
    char *str;
    int length;
    getInput(&str, &length); 
    printf("You entered: %s\n", str);
    free(str);
    return 0;
}


