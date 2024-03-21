#include <stdio.h>

void insertionSort(int arr[], int n) {
    int i = 1;
    while (i < n){
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1]= arr[j];
            arr[j] = temp;
            j -=1;
        }
        i += 1;
    }
}


int main (){
    int arr[] = {1,3,2,5,4};
    insertionSort(arr, 5);
    for (int i = 0; i < 5; i++){
        printf("%d\n", arr[i]);
    }
}

