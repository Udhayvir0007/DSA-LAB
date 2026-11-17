#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotate(int arr[], int k, int n) {
    k = k % n;  

    reverse(arr, 0, k - 1);       
    reverse(arr, k, n - 1);       
    reverse(arr, 0, n - 1);       

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    rotate(arr, 2, 5);
    return 0;
}