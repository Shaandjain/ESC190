#include <stdio.h>

int main(){
    // Kernighan and Richie (K&R) style: the curly braces goes 
    // on the next line after the function head

    // declare a variable
    // we can also initalize it here

    int b;  //b is an int, and it is not initialized
            //can have any value
            //almost in 100% of the cases, you want to initialize your variables
    // double, char (e.g, '@'), int *, char *
    //printf("Hello, world!\n");

    char *s1 = "hi!";    //put "hi!", followed by a null character '\0' in memory
                        //stores the address of h in s1

    // %s: string (i.e, the sequence of characters at the given address, until the null character)
    // %d: integer (d stands for decimal)
    // %ld: long decimal (long int, stores more bits than int)
    // %c: character
    // %f: float
    // %lf: double

    printf("%s\n", s1);
    // printf("%ld\n", s1);    //prints 8, because s1 is a pointer

    printf("The string is: %s, the address is %ld\n", s1, s1);

    int a = 43;
    printf("The integer is : %d\n", a);
    return 0;
}