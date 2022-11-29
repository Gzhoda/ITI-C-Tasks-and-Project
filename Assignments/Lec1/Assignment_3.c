#include <stdio.h>
void XOR(int x, int y){
    printf("%d  ^  %d =  %d\n", x,y,x^y);
}
void OR(int x, int y){
    printf("%d  |  %d =  %d\n", x,y,x|y);
}
void add(int x, int y){
    printf("%d  +  %d =  %d\n", x,y,x+y);
}
void AND(int x, int y){
    printf("%d  &  %d =  %d\n", x,y, x & y );
}
void subtract(int x, int y){
    printf("%d  -  %d =  %d\n", x,y,x-y);
}

void main(){
    int x,y;
    printf("Enter the first number\n");
    scanf("%d",&x);
    printf("Enter the Second number\n");
    scanf("%d",&y);
    add(x,y);
    subtract(x,y);
    AND(x,y);
    OR(x,y);
    XOR(x,y);
}