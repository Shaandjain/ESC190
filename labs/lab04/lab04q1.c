#include <stdio.h>

void segfault()
{
    char a[5] = "EngSci";
    printf("%c", a[100000]); // segmentation fault
}

int main() {
    FILE *fp = fopen("a.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    char c;
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }

    return 0;
}




