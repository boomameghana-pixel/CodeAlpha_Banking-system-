#include <stdio.h>
#include <string.h>
struct Bank{
    char name[20];
    int accNo;
    float bal;
};
struct Bank b;
void deposit(){
    float amt;
    printf("Enter amount to deposit: ");
    scanf("%f",&amt);
    b.bal = b.bal + amt;
    printf("Deposited successfully\n");
    FILE *fp = fopen("account.txt","w");
    fprintf(fp,"%s %d %f",b.name,b.accNo,b.bal);
    fclose(fp);
}
void withdraw(){
    float amt;
    printf("Enter amount to withdraw: ");
    scanf("%f",&amt);
    if(amt > b.bal){
        printf("No balance\n");
    }
    else{
        b.bal = b.bal - amt;
        printf("Withdraw success\n");
        FILE *fp = fopen("account.txt","w");
        fprintf(fp,"%s %d %f",b.name,b.accNo,b.bal);
        fclose(fp);
    }
}
void balance(){
    printf("\nName = %s\n",b.name);
    printf("Account No = %d\n",b.accNo);
    printf("Balance = %.2f\n",b.bal);
}
int main(){
    int choice;
    FILE *fp = fopen("account.txt","r");
    if(fp==NULL){
        printf("Enter your name: ");
        scanf("%s",b.name);
        printf("Enter account number: ");
        scanf("%d",&b.accNo);
        b.bal = 0;
    }
    else{
        fscanf(fp,"%s %d %f",b.name,&b.accNo,&b.bal);
        fclose(fp);
    }

    while(1){
        printf("\n1.Deposit\n2.Withdraw\n3.Balance Enquiry\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        if(choice==1) deposit();
        else if(choice==2) withdraw();
        else if(choice==3) balance();
        else if(choice==4) break;
        else printf("Invalid choice\n");
    }
    return 0;
}