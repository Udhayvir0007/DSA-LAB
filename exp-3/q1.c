#include <stdio.h>

int nth_larg (int* arr, int size, int n) {
    int top_n[n];
    for (int i = 0; i < n; i++) {
        top_n[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        int current = arr[i];
        for (int j = 0; j < n; j++) {
            if (current > top_n[j]) {
                for (int k = n - 1; k > j; k--) {
                    top_n[k] = top_n[k - 1];
                }
                top_n[j] = current;
                break; 
            }
        }
    }
    return top_n[n - 1];
}

int main() {
    int arr[] = {2,3,1,45,67,23,45};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n = 3;
    int result = nth_larg(arr, size, n); 
    printf("%d", result) ;
    return 0;
}

