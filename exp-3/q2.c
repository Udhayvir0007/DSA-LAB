#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
int max_diff(int arr[], int n){
    int curr_profit= 0;
    int max_profit=0;
    int min_price =INT_MAX;
    bool is_profit =false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]<min_price) min_price= arr[i];
        else{
        curr_profit = arr[i]- min_price;
        if(curr_profit>max_profit){
            max_profit= curr_profit;
            is_profit=true;
        }
    }
        
        
    }
    if(!is_profit){
        return 0;
    }
    return max_profit;
    
}
int main (){
    int a[]={23,43,12,1,2,56,78,90};
    int size = sizeof(a)/sizeof(a[0]);
    int profit= max_diff(a,size);
    printf("%d", profit);
}