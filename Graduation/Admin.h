#ifndef Admin_H_
#define Admin_H_

void Create_acc(account* acc, u32 counter){
    printf("Enter the Data you need: \n");
    while(1){
    printf("Full Name:    ");
    fflush(stdin);
    scanf("%[^\n]%*c",acc->Full_name);
    u8 spaces = 0,flag =0 , i=0;
        while(1){
            
            if(acc->Full_name[i]=='\0'){
                if(spaces < 3 )
                flag=1;
                break;
            }
            if(acc->Full_name[i]==' ' && acc->Full_name[i+1] != ' ')
                spaces++;
        i++;
        }

        if (flag!=1)
            break;
        printf("The Full Name you entered is invalid\n");
    }
    printf("Full Address:    ");
    fflush(stdin);
    scanf("%[^\n]%*c",acc->Full_Address);
    printf("Age:    ");
    scanf("%d",acc->age);
    printf("National ID:    ");
    fflush(stdin);
    scanf("%[^\n]%*c",acc->National_ID);
    if(acc->age<21){
    printf("Guardian National ID:    ");
    fflush(stdin);
    scanf("%[^\n]%*c",acc->Gurdain_ID);
    }
    printf("Balance:    ");
    scanf("%d",acc->Balance);
    //printf("Full Name:    ");
    //printf("%s",acc->Full_name);
    acc->Acc_Status=1;
    acc->Bank_acc_ID = 1000000000 + counter;


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
            acc->pass[i] = numbers[rand() % 10];
            randomizer = rand() % 4;
           
        }
        else if (randomizer == 2) {
            acc->pass[i] = symbols[rand() % 8];
            randomizer = rand() % 4;
            
        }
        else if (randomizer == 3) {
            acc->pass[i] = LETTER[rand() % 26];
            randomizer = rand() % 4;
            
        }
        else {
            acc->pass[i] = letter[rand() % 26];
            randomizer = rand() % 4;
            
        }
    }
    
printf("Your generated Account password is : %s",acc->pass);
}

void Exist_acc(account* acc,account* Total_acc){
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
    }

}



#endif