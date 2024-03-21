#include <stdio.h>
#include <string.h>

int main() {
    char str1[50] = "Hello";
    char str2[] = " World!";
    int i, j;

    for (i = 0; str1[i] != '\0'; i++);

    for (j = 0; str2[j] != '\0'; j++) {
        str1[i + j] = str2[j];
    }
    str1[i + j] = '\0';

    printf("%s\n", str1);

}








