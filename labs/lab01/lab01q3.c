#include <stdio.h>

void change_arr(char arr[]){
    arr[0] = 'a';
}

int main(){
    char arr[100];
    change_arr(arr);
    printf("%c\n", arr[0]);
}