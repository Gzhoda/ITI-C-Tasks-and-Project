#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "Client.h"
#include <string.h>
#include <math.h>
#include <time.h>


u8 Cust_actions(u16 counter, account* Total_acc){
 printf("If You wish to do a transaction press 1\n");
    printf("To change Account Password press 2\n");
    printf("To withdraw press 3\n");
    printf("To deposit press 4\n");
    printf("to exit press 0\n");
    u8 check, flag=0,counter1=0;
    u32 ID;
    u32 Balancere;
    u32 BalanceW;
    u8 state[15];
    u32 BalanceD;
    u8 flag_L =0;
    scanf("%d",&check);
    switch(check){
        case 1:
        printf("Enter The second ID You wish to do the transaction with\n");
        scanf("%d",&ID);
        while(1){
        for (u16 i=0;i<SIZE;i++){
            if(ID==Total_acc[i].Bank_acc_ID && Total_acc[i].Acc_Status==1)
            {
                counter1=i;
                flag=0;
                break;
            }
            flag=1;
        }
        if(flag==1)
        break;
            printf("You have entered a wrong ID or not an exciting one or the account is not an active one\n");
        }
        printf("Enter the amount of money you would like to transfer\n");
        while(1){
        scanf("%d",&Balancere);
        if(Balancere> Total_acc[counter].Balance){printf("Insuffecient Funds\n");continue;}
        else{
            Total_acc[counter].Balance-=Balancere;
            Total_acc[counter1].Balance+=Balancere;
            printf("Transaction Successful\n");
        }
        }
        break;
        case 2:
        printf("To change the Account password enter your new password \n");
        
        fflush(stdin);
        scanf("%[^\n]%*c",Total_acc[counter].pass);
        printf("You have changed your password");
        break;
        case 3:
        printf("Enter the amount of cash you wish to withdraw\n");
        scanf("%d",&BalanceW);
        if(Total_acc[counter].Balance<BalanceW){
            printf("Inssufecient Funds\n");
            break;
        }
        else{
            Total_acc[counter].Balance-=BalanceW;
            printf("Transaction Successful\n");
        }
        break;
        case 4:
        
        printf("Enter the amount of cash you wish to Deposit\n");
        scanf("%d",&BalanceD);
        Total_acc[counter].Balance+=BalanceW;
        printf("Transaction Successful\n");
        break;
        case 0:
        flag_L =1;
        break;
        default:
        printf("You entered a wrong Input");
        break;
    }
    return flag_L;
    }