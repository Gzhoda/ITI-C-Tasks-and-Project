#include<stdio.h>
#include <time.h>
#include <stdlib.h>

void main(){
    int ClassA[10];
    int ClassB[10];
    int ClassC[10];
    srand(time(NULL));
    int pass=0,fail=0,max=0,min=101,sum=0;

    for (int i=0;i<10;i++){
        ClassA[i] = rand()%101;
        ClassB[i] = rand()%101;
        ClassC[i] = rand()%101;
        if(max<ClassA[i]){
            max=ClassA[i];
        }
        else if(max<ClassB[i]){
            max=ClassB[i];
        }
        else if(max<ClassC[i]){
            max=ClassC[i];
        }
        if(min>ClassA[i]){
            min=ClassA[i];
        }
        else if(min>ClassB[i]){
            min=ClassB[i];
        }
        else if(min>ClassC[i]){
            min=ClassC[i];
        }
        if(ClassB[i]>=50){
            pass++;
        }
        else{
            fail++;
        }
         if(ClassA[i]>=50){
            pass++;
        }
        else{
            fail++;
        }
         if(ClassC[i]>=50){
            pass++;
        }
        else{
            fail++;
        }
        sum+=ClassA[i]+ClassB[i]+ClassC[i];
        }
        int avg = sum/30;
        printf("The Highest Grade is = %d\n",max);
printf("The Lowest Grade is = %d\n",min);
        printf("The Average of all Grades is = %d\n",avg);
        printf("The Number of passed Students are  ->  %d\n",pass);
        printf("The Number of Failed Students are  ->  %d",fail);
                
}