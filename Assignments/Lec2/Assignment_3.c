#include<stdio.h>
#include<string.h>
void main(){
int arr[3];
int max=0;
for (int i=0;i<3;i++){
    printf("Enter Your number : ");
    scanf("%d",&arr[i]);
    if(max<arr[i]){
        max=arr[i];
    }
}
printf("The maximum number is : %d",max);

}