#include <stdio.h>

int f(int *p_a) {
    *p_a = 43;    
}
// the function f takes and address and puts 43 in that address
//analogous to passing a list in Python 

int main(){
    int aa = 43;
    printf("%d\n", aa);
}