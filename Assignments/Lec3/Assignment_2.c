#include<stdio.h>
#include<string.h>
void main(){
    char pass[50]="RTX3060TI";
    char ID[50]="546812";
    char user_N[50]="Damian";
    char Checker[50];
    int counter=0;
    printf("Enter Your ID : ");
    fflush(stdin);
    scanf("%[^\n]%*c",Checker);
    if(strcmp(ID, Checker)){
        printf("You Are not Registered\n");
    }
            
    else{
        printf("Enter your Password : ");
        while(counter!=3){
        
            fflush(stdin);
        scanf("%[^\n]%*c",Checker);
       if(strcmp(pass, Checker)){
        printf("You have entered the wrong Password\n");
        printf("Try Again : ");
        counter++;
        
        
    }
    else{
        printf("Welcome %s\n",user_N);
    break;
    }
    }
    }


}