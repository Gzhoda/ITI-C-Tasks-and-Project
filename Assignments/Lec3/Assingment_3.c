#include <stdio.h>
void main(){
    int spaces,astrisc=1,Scale;
    printf("The scale of the triangle \n");
    scanf("%d",&Scale);
   spaces  =  Scale;
    for(int i=0;i<Scale;i++){
        for(int j=0;j<spaces;j++){
            printf(" ");
        }
        for(int j =0;j<astrisc;j++){
            printf("*");
        }
        astrisc+=2;
        spaces--;
        printf("\n");
    }
}