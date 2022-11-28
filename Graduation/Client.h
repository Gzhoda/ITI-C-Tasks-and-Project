#ifndef Client_H_
#define Client_H_
Cust_actions(account* acc){
 printf("If You wish to do a transaction press 1\n");
    printf("To change the account status press 2\n");
    printf("To withdraw press 3\n");
    printf("To deposit press 4\n");
    printf("to exit press 0\n");
    u8 check, flag=0,counter=0;
    scanf("%d",check);
    switch(check){
        case 1:
        u32 ID;
        printf("Enter The second ID You wish to do the transaction with\n");
        scanf("%d",&ID);
        while(1){
        for (int i=0;i<SIZE;i++){
            if(ID==Total_acc[i]->Bank_acc_ID && Total_acc[i]->Acc_Status==1)
            {
                counter=i;
                flag=0;
                break;
            }
            flag=1
        }
        if(flag!=0)
        break;
            printf("You have entered a wrong ID or not an exciting one or the account is not an active one\n");
        }
        u32 Balancere;
        printf("Enter the amount of money you would like to transfer\n");
        while(1){
        scanf("%d",&Balancere);
        if(Balancere> acc->Balance){printf("Insuffecient Funds\n");continue;}
        else{
            acc->Balance-=Balancere;
            Total_acc->Balance+=Balancere;
            printf("Transaction Successful\n");
        }
        }
        break;
        case 2:
        printf("To change the Account status to Active/Closed/Restricted enter 1/2/3 respectively\n");
        u8 state;
        scanf("%d",&state);
        switch(state){
        case 1:
        acc->Acc_Status=1;
        break;
        case 2:
        acc->Acc_Status=2;
        break;
        case 3:
        acc->Acc_Status=3;
        break;
        default:
        printf("You entered an invalid Input for the account status\n");
        break;
        }
        break;
        case 3:
        u32 BalanceW;
        printf("Enter the amount of cash you wish to withdraw\n");
        scanf("%d",&BalanceW);
        if(acc->Balance<BalanceW){
            printf("Inssufecient Funds\n");
            break;
        }
        else{
            acc->Balance-=BalanceW;
            printf("Transaction Successful\n");
        }
        break;
        case 4:
        u32 BalanceD;
        printf("Enter the amount of cash you wish to withdraw\n");
        scanf("%d",&BalanceD);
        acc->Balance+=BalanceW;
        printf("Transaction Successful\n");
        break;
        case 0:
        break;
        default:
        printf("You entered a wrong Input");
        break;
    }}

#endif