#include<stdio.h>
void main(){
    int arr[10];
    int Searcher;
    printf("Enter Your 10 numbers\n");
    for (int i=0;i<10;i++){
        
        scanf("%d",&arr[i]);
    }
    int flag=0;
    printf("Enter the number you wish to search for ");
    scanf("%d",&Searcher);
    for(int i=0;i<10;i++){
        if(arr[i]==Searcher){
            printf("The number is Found and its location is the %d",i+1);
            flag=1;
            break;
        }
        
    }
    if(flag==0){printf("The number is not found\n");}
}