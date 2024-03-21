#include <stdio.h>

void change_a(int *p_a){
    *p_a = 10;
}
int main(){
    int aa = 5;
    int *p_aa = &aa;
    change_a(p_aa);
    printf("%d\n", aa);
}