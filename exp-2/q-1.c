#include <stdio.h>
void insert(int arr[], int *n, int pos, int val){
    for (int i=*n; i>=pos; i--){
        arr[i]= arr[i-1];
    }
    arr[pos-1]= val;
    (*n)++;

    for(int i=0; i<*n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void delete(int arr[], int *n, int val){
    int idx;
    for (int i=0; i<*n; i++){
        if(arr[i]== val){
            idx =i;
            break;
        }
    }
    for (int i=idx; i<*n; i++){
        int key=arr[i+1];
        arr[i+1]= arr[i];
        arr[i]= key;

    }
    (*n)--;
    for(int i=0; i<*n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int n=5;
    int arr[5]={23,45,12,13,46};
    int val = 89;
    int pos= 3;
    // insert(arr, &n, pos,val);
    delete(arr, &n, 23);

}