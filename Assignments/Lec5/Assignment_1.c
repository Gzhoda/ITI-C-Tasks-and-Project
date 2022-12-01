#include<stdio.h>
#include <time.h>
#include <stdlib.h>

void main(){

    int ARR[10];
    
    int max=0,min=1010000;

    for (int i=0;i<10;i++){
        printf("Enter your number\n");
        scanf("%d",&ARR[i]);
        if(max<ARR[i]){
            max=ARR[i];
        }
        
        if(min>ARR[i]){
            min=ARR[i];
        }

        }

        printf("The Highest Grade is = %d\n",max);
printf("The Lowest Grade is = %d\n",min);
        
                
}