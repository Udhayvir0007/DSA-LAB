#include <stdio.h>
void ip_Array(int n, int arr[]){
    for(int i=0; i<n; i++){
        printf("Enter %dth element:",i+1);
        scanf("%d", &arr[i]);
    }
    
}
void  arrange(int n,int arr[]){
    int mid = n/2;
    int pos[mid], neg[mid], psv=0, ngv=0;
    for (int i=0; i<n; i++){
        if(arr[i]>=0){
        pos[psv++]= arr[i];
    }
        else if(arr[i]<0){
            neg[ngv++]= arr[i];
        }    
    }
    psv=0, ngv=0;
    for (int i=0; i+1<n; i=+2){
        
            arr[i]= pos[psv++];
            arr[i+1]=neg[ngv++];
}

    
}

int main(){
    int n;
    printf("What size of array u want:");
    scanf("%d", &n);
    int arr[n];
   
    ip_Array(n, arr);
    // assuming the ideal case 
    arrange(n, arr);

    // printing the new array
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
    
}