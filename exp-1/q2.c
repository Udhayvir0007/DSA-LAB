#include <stdio.h>

void ip_Array(int n, int arr[]) {
    for(int i = 0; i < n; i++) {
        printf("Enter %dth element: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void findSubsets(int n, int arr[], int target, int index, int current_subset[], int subset_size, int current_sum) {

    if (index == n) {
        
        if (current_sum == target && subset_size > 0) {
            printf("[ ");
            for (int i = 0; i < subset_size; i++) {
                printf("%d ", current_subset[i]);
            }
            printf("]\n");
        }
        return;
    }

   
    current_subset[subset_size] = arr[index];
    findSubsets(n, arr, target, index + 1, current_subset, subset_size + 1, current_sum + arr[index]);

 
    findSubsets(n, arr, target, index + 1, current_subset, subset_size, current_sum);
}

int main() {
    int n, target;
    
    printf("What size of array u want: ");
    scanf("%d", &n);
    
    printf("Target: ");
    scanf("%d", &target);
    
    int arr[n];
    ip_Array(n, arr);
   
    int current_subset[n]; 
    
    printf("Subsets that equal %d are:\n", target);
    

    findSubsets(n, arr, target, 0, current_subset, 0, 0);

    return 0;
}