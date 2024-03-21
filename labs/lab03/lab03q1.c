#include <stdio.h>

void set_int1(int x)
{
    x = 42;
}

void set_int2(int *p_x)
{
    *p_x = 42;
}

int main()
{
    int x = 0;
    set_int1(x);
    printf("x = %d\n", x);
    set_int2(&x);
    printf("x = %d\n", x);
    return 0;
}

//the first function has no effect since it does not point
//to any memory address. The second function has an effect
//since it points to the memory address of x.

