#include<stdio.h>
void main(){
    int x=1,y=2,z=3;
    int* q;
    int* p;
    int* r;
    int*temp;
    
    q=&x; p=&y; r=&z;
    printf("x = %d   ,   y = %d   ,   z = %d\n", x,y,z);
    printf("q = %d   ,   p = %d   ,   r = %d\n", q,p,r);
    printf("*q = %d   ,   *p = %d   ,   *r = %d\n", *q,*p,*r);
    printf("Swapping Pointers\n");
    temp =r;
    r=p;
    p=q;
    q=temp;
     printf("x = %d   ,   y = %d   ,   z = %d\n", x,y,z);
    printf("q = %d   ,   p = %d   ,   r = %d\n", q,p,r);
    printf("*q = %d   ,   *p = %d   ,   *r = %d\n", *q,*p,*r);
    

}