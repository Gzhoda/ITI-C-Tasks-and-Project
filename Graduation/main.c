#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include <string.h>
#include "Admin.h"
#include "Client.h"


account arr[SIZE];
 // The accounts get incremented with counter from 1000000000
u8 Curr_user[SIZE]="Ahmedon";
u8 Curr_pass[SIZE]="RTX3060";





void main(){

    account* vac[SIZE];
    u8 username[SIZE];
    u8 sml =1;

    u8 pass[SIZE];
    u8 password_CH[15];
    u8 check=0; //main loop
    u8 cho=1;  //admin

    u8 ret;
    u8 flagp=1;
    u8 flagU;
    int flag=0;
    u32 ID,ID2;
while(1){
    printf("Welcome to the ITI Bank for the Special\n");
    printf("To enter the Admin window Please press 1\n");
    printf("To enter The client window please press 2\n");
    printf("To Exit the Program please press 0\n");
    check=0;
    scanf("%d",&check);
    if (check == 1){
        while(1){
        //check username and password
        printf("Enter Your Username: ");
        fflush(stdin);
        scanf("%[^\n]%*c",username);
        printf("Enter The Password: ");
        fflush(stdin);
        scanf("%[^\n]%*c",pass);
        flagU = strcmp(username,Curr_user);
        if(flagU==1){
            printf("The username is Wrong\n");
        }
        u8 flagP = strcmp(pass,Curr_pass);
        if(flagP==1){
            printf("The Password is Wrong\n");
        }
        else{break;}
        }

        // The Admin Window Enterance

        while (1)
        {
            printf("Welcome to the ADMIN Window, Here is your options\n");
            printf("To create an account Please press 1: \n");
            printf("To Open an existing account Please press 2: \n");
            printf("To Exit the system, Please press 0: \n");
            fflush(stdin);
            scanf("%d",&cho);
            switch(cho){
                case 1:
                    for(int i=0;i<SIZE;i++){
                        if(vac[i]==NULL){
                            Create_acc(arr, i);
                            vac[i]=&arr[i];
                            break;
                        }
                    }
                break;
                case 2:

                //The bank accounts start from 1000000000
                printf("Enter the Bank ID of the Existing customer \n");
                
                scanf("%d",&ID);
                printf("You have entered %d\n\n",ID);
                //scanf("%d",&ID2);
                for(u16 i = 0;i<SIZE;i++){
                    if(ID==arr[i].Bank_acc_ID && arr[i].Acc_Status==1){

                        Exist_acc(i, arr);
                        flag=0;
                        
                    }
                    else
                        flag=1;
                }
                if(flag==1){
                    printf("You entered a wrong bank ID or the account you selected is not active\n");
                }

                break;
                case 0:
                printf("You have Chosen to close the Admin Window \n ");
                break;
                default:
                printf("You entered a wrong option\n");
                break;
            }
            if(cho == 0)break;
        }
    }

        //The customer Window Enterance
        else if(check==2){

        printf("Welcome to the customer window \n");
        //entering password for Customer
        while(1){
        printf("Enter your Password\n");
        fflush(stdin);
        scanf("%s",password_CH);
        for (int i =0;i<SIZE;i++){
            if(!strcmp(password_CH, arr[i].pass)){
                flagp=0;
                printf("Welcome %s\n",arr[i].Full_name);
                ret=Cust_actions(i, arr);
                break;
            }
        }
        if(flagp == 1){
            printf("Invalid Password\n");
        }
        if(ret==1)break;
        }
        }
        else if(check ==0){          //leave program
        printf("Thank you for using the ITI bank\n");
        printf("have a wanderful day\n");
        printf("%c \n",sml);
        break;
        }
        else{
        printf("You entered a wrong option\n");
        }
    }
}
