#include <stdio.h>

void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz){
    for (int i = 0; i < arr1_sz - arr2_sz + 1; i++){
        int equal = 1;
        for (int j = 0; j < arr2_sz; j++){
            if (arr1[i+j] != arr2[j]){
                equal = 0;
                break;
            }
        }
        if (equal == 1){
            for (int j = 0; j < arr2_sz; j++){
                arr1[i+j] = 0;
            }
        }
    }
}

int main(){
    int arr1[] = {5,6,7,8,6,7};
    int arr2[] = {6,7};
    seq_replace(arr1, 6, arr2, 2);
    for (int i = 0; i < 6; i++){
        printf("%d\n", arr1[i]);
    }
}

