#include <stdio.h>

void main(){
    int arr[3];
    for(int i=0;i<3;i++){
        printf("Enter your %d Num ", i);
        scanf("%d",&arr[i]);
    }
    for(int i=3;i>0;i--){
        printf("your %d Num is ", i);
        printf("%d\n",arr[i-1]);
    }
}