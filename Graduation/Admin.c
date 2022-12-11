#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"
#include "Admin.h"
#include <string.h>
#include <math.h>
#include <time.h>




void Create_acc(account* Total_acc, u32 counter){
    u8 flag_ID=0;
    printf("Enter the Data you need: \n");
    while(1){
    printf("Full Name:    ");
    fflush(stdin);
    scanf("%[^\n]%*c", Total_acc[counter].Full_name);
    u8 spaces = 0,flag =0 , i=0;
        while(1){
            
            if(Total_acc[counter].Full_name[i]=='\0'){
                if(spaces < 3 )
                flag=1;
                break;
            }
            if(Total_acc[counter].Full_name[i]==' ' && Total_acc[counter].Full_name[i+1] != ' ')
                spaces++;
        i++;
        }

        if (flag!=1)
            break;
        printf("The Full Name you entered is invalid\n");
    }
    printf("Full Address:    ");
    fflush(stdin);
    scanf("%[^\n]%*c",Total_acc[counter].Full_Address);
    
    //age
    u8 age_flag= 0;
    while(age_flag==0){
    printf("Age:    ");
    scanf("%d",&Total_acc[counter].age);
    age_flag=1;
    if(Total_acc[counter].age<0 || Total_acc[counter].age>100)
    {printf("Invalid Input \n");
    age_flag=0;
    }
    }

    fflush(stdout);

    for(int i =0 ;i<15;i++){
        Total_acc[counter].National_ID[i]='~';
    }
    do{
    printf("National ID:    ");
    fflush(stdin);
    scanf("%[^\n]%*c",Total_acc[counter].National_ID);
    for(int i =0 ;i<14;i++){
        if(Total_acc[counter].National_ID[i]=='~'||(Total_acc[counter].National_ID[i]<48 && Total_acc[counter].National_ID[i]>57)){
            flag_ID=0;
        }
        else{flag_ID=1;}
    }
    if(flag_ID==0)printf("You have entered a wrong ID");
    }while(flag_ID==0);

//guardian ID if < 21

    if(Total_acc[counter].age<21){
        for(int i =0 ;i<15;i++){
        Total_acc[counter].Gurdain_ID[i]='~';
    }
    flag_ID=0;
    do{
    fflush(stdout);
    printf("Guardian National ID:    ");
    fflush(stdin);
    scanf("%[^\n]%*c",Total_acc[counter].Gurdain_ID);

    for(int i =0 ;i<14;i++){
    if(Total_acc[counter].Gurdain_ID[i]=='~'||(Total_acc[counter].Gurdain_ID[i]<48 && Total_acc[counter].Gurdain_ID[i]>57)){
            flag_ID=0;
        }
        else{flag_ID=1;}
    }
     if(flag_ID==0)printf("You have entered a wrong ID");
    }while(flag_ID==0);
    }

    fflush(stdout);
    printf("Balance:    ");
    fflush(stdin);
    scanf("%d",&Total_acc[counter].Balance);

    // The accounts get incremented with counter from 1000000000
    Total_acc[counter].Acc_Status=1;
    Total_acc[counter].Bank_acc_ID = 1000000000 + counter;
    

    // Password
     int i = 0;
    int randomizer = 0;
    srand((unsigned int)(time(NULL)));
    u8 numbers[] = "0123456789";
    u8 letter[] = "abcdefghijklmnoqprstuvwyzx";
    u8 LETTER[] = "ABCDEFGHIJKLMNOQPRSTUYWVZX";
    u8 symbols[] = "!@#$^&*?";
    randomizer = rand() % 4;
  
    // Iterate over the range [0, N]
    for (int i = 0; i < 15; i++) {
  
        if (randomizer == 1) {
            Total_acc[counter].pass[i] = numbers[rand() % 10];
            randomizer = rand() % 4;
           
        }
        else if (randomizer == 2) {
            Total_acc[counter].pass[i] = symbols[rand() % 8];
            randomizer = rand() % 4;
            
        }
        else if (randomizer == 3) {
            Total_acc[counter].pass[i] = LETTER[rand() % 26];
            randomizer = rand() % 4;
            
        }
        else {
            Total_acc[counter].pass[i] = letter[rand() % 26];
            randomizer = rand() % 4;
            
        }
    }
    
printf("Your generated Account password is : %s\n",Total_acc[counter].pass);
printf("Your generated Account ID is : %d\n",Total_acc[counter].Bank_acc_ID);
}

void Exist_acc(u16 counter, account* Total_acc){
    printf("If You wish to do a transaction press 1\n");
    printf("To change the account status press 2\n");
    printf("To withdraw press 3\n");
    printf("To deposit press 4\n");
    printf("to exit press 0\n");
    u8 check, flag=0,counter1=0;
    scanf("%d",&check);
    u32 ID;
    u32 Balancere;
    u8 state;
    u32 BalanceW;
    u32 BalanceD;   
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
        if(flag==0)
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
        printf("To change the Account status to Active/Closed/Restricted enter 1/2/3 respectively\n");
        scanf("%d",&state);
        switch(state){
        case 1:
        Total_acc[counter].Acc_Status=1;
        break;
        case 2:
        Total_acc[counter].Acc_Status=2;
        break;
        case 3:
        Total_acc[counter].Acc_Status=3;
        break;
        default:
        printf("You entered an invalid Input for the account status\n");
        break;
        }
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
        
        printf("Enter the amount of cash you wish to withdraw\n");
        scanf("%d",&BalanceD);
        Total_acc[counter].Balance+=BalanceW;
        printf("Transaction Successful\n");
        break;
        case 0:
        break;
        default:
        printf("You entered a wrong Input");
        break;
    }
}
