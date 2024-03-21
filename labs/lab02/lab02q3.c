#include <stdio.h>
#include <string.h>

// Recursive function to compare two strings character by character
int my_strcmp_rec(char *s1, char *s2) {
    // Base case: both strings are empty, so they are equal
    if (*s1 == '\0' && *s2 == '\0') {
        return 1;
    }
    // If the current characters are equal, recursively compare the remaining characters
    if (*s1 == *s2) {
        return my_strcmp_rec(s1 + 1, s2 + 1);
    }
    // If the current characters are not equal, the strings are not equal
    return 0;
}
int main () {
    char str1[50] = "Hello";
    char str2[] = "hello";
    
    printf("%d\n", my_strcmp_rec(str1, str2));
    
    return 0;
}
