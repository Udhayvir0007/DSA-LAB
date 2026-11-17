#include <stdio.h>
#include <time.h>


void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}




int main() {
    int a[5]={19,2,1223,4,50};
    clock_t start_at= clock();
    bubbleSort(a,5);
    clock_t end_at= clock();
    double time_1 = ((double)(end_at-start_at))/CLOCKS_PER_SEC;
    printf("By bubble sort array: \n");
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);
    printf("\n");
    printf("took %f ticks to execute...\n ", time_1);
    
    int b[5]={34,12,32,89,43};
    clock_t start_at_2= clock();
    insertionSort(a,5);
    clock_t end_at_2= clock();
    double time_2 = ((double)(end_at_2-start_at_2))/CLOCKS_PER_SEC;
    printf("By insertion sort array: \n");
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);
    printf("\n");
    printf("took %f ticks to execute...\n ", time_2);

    return 0;
}