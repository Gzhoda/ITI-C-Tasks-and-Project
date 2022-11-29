#include <stdio.h>
void main(){
    int spaces=5,astrisc=1;
    for(int i=0;i<6;i++){
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