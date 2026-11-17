#include <stdio.h>
#include <limits.h>
int sec_larg(int arr[], int n){
    int l1= INT_MIN, l2= INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>l1 ){
            int key = l1;
            l1=arr[i];
            l2= key;
        }
        else if(arr[i]>l2 && arr[i]!=l1){
            l2 =arr[i];
        }
    }
    return l2;
    
}
int sec_lmin(int arr[], int n){
    int l1= INT_MAX, l2= INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<l1 ){
            int key = l1;
            l1=arr[i];
            l2= key;
        }
        else if(arr[i]<l2 && arr[i]!=l1){
            l2 =arr[i];
        }
    }
    return l2;
    
}
int main(){

    int n=5;
    int arr[5]= {1,2,16,3,1};
    printf("%d", sec_larg(arr, 5));
}