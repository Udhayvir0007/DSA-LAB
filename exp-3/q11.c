#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int find (int arr[], int n) {
    
    for (int i = 0; i < n; i++) {
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
            swap(&arr[i], &arr[arr[i] - 1]);
        }
    }
    for (int i = 0; i < n; i++) {
       if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    
  
    return n + 1;
}

int main() {
    int arr[] = {2,3,1,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int missing = find(arr, n);
    
    printf("%d\n", missing);
    
    return 0;
}