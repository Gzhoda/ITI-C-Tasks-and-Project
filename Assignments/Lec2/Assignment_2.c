#include<stdio.h>
#include<string.h>
void main(){
    char pass[50]="RTX3060TI";
    char ID[50]="546812";
    char user_N[50]="Damian";
    char Checker[50];
    printf("Enter Your ID : ");
    fflush(stdin);
    scanf("%[^\n]%*c",Checker);
    if(strcmp(ID, Checker)){
        printf("You have entered the wrong ID");
    }
    else{
        printf("Enter your Password : ");
            fflush(stdin);
        scanf("%[^\n]%*c",Checker);
       if(strcmp(pass, Checker)){
        printf("You have entered the wrong Password\n");
    }
    else{
        printf("%s",user_N);

    }
    }


}