#include <stdio.h>

//Q0: Make sure that you can run and compile a Hello World program in VS Code

int main() {
    printf("Hello, World!\n");
    return 0;
}

//Q1

int linear_search(int *a, int sz, int elem) {
    for (int i = 0; i < sz; i++) {
        if (a[i] == elem) {
            return i;
        }
    }
    return -1;
}

// Q2

void reverse_arr(int *arr, int sz) {
    int start = 0;
    int end = sz - 1;
    
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        start++;
        end--;
    }
}


