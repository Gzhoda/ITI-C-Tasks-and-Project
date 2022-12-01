#include<stdio.h>
void min(int *arr,int *mini){
    for(int i=0;i<4;i++){
        if(arr[i]<*mini){
            *mini = arr[i]; 
        }
    }

}

void max(int *arr,int *maxi){
    for(int i=0;i<4;i++){
        if(arr[i]>*maxi){
            *maxi = arr[i]; 
        }
    }

}

void main(){
    int arr[4],maxi=0,mini=100000;
    for(int i=0;i<4;i++){
        scanf("%d",&arr[i]);
    }
    max(arr,&maxi);
    min(arr,&mini);
    printf("The maximum number is : %d\n",maxi);
    printf("The minimum number is : %d\n",mini);
}