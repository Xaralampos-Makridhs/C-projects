#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#define max_acc 200
#define MAX_LENGTH 200

typedef struct{
char kwdikos[100];
char name[100];
float balance;
}account;


void maskwdikos(char *password);
void updateacc(account acc[],char *code,int plithos);
void createacc(account acc[],int *plithos);
void withdraw(account acc[],int plithos,char *code,float amount);
void deposit(account acc[],char *code,float amount,int plithos);

void setcolor(int color){
HANDLE hconsole=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hconsole,color);
}

int main(){
account acc[max_acc];
int plithos = 0;
int choice;
char code[100];
float amount;

setcolor(9);
time_t now;
time(&now);
printf("%s", ctime(&now));
printf("\t\t\t\tWELCOME TO THE ATM\n\n");

do {
printf("1. Create account\n");
printf("2. Update account\n");
printf("3. Withdraw amount\n");
printf("4. Deposit amount\n");
printf("5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
getchar();

        switch (choice) {
        case 1:
            createacc(acc, &plithos);
            break;
        case 2:
            printf("Give the password of the account:\n");
            maskwdikos(code);
            updateacc(acc, code, plithos);
            break;
        case 3:
            printf("Give the password of the account:\n");
            maskwdikos(code);
            printf("Give the amount you want to withdraw:\n");
            scanf("%f", &amount);
            withdraw(acc, plithos, code, amount);
            break;
        case 4:
            printf("Give the password of the account:\n");
            maskwdikos(code);
            printf("Give the amount you want to deposit:\n");
            scanf("%f", &amount);
            deposit(acc, code, amount, plithos);
            break;
        case 5:
            printf("Exiting the program. Thank you!\n");
            break;
        default:
            printf("Invalid choice. Enter a valid option\n");
            break;
        }
    } while (choice != 5);

    return 0;
}



void createacc(account acc[],int *plithos){
printf("\t\t\t\tCREATE ACCOUNT\n");
if(*plithos<max_acc){
    printf("Enter the name of the holder:");
    scanf(" %[^\n]",acc[*plithos].name);

    printf("Enter the code of the account: ");
    maskwdikos(acc[*plithos].kwdikos);

    acc[*plithos].balance=0.0;
    (*plithos)++;

    printf("\t\t\t\taccount created succesfully\n");
    }else{
        printf("\t\t\t\tcannot create more accoutnts\n");
    }
}

void updateacc(account acc[],char *code,int plithos){
    printf("\t\t\t\tUPDATE ACCOUNT\n");
for(int i=0;i<plithos;i++){
    if(strcmp(code,acc[i].kwdikos)==0){

    printf("name of the holder:%s\n",acc[i].name);
    printf("balance of the account:%f\n", acc[i].balance);
    break;

    }else{
    Beep(510,600);
    printf("wrong password\n");
        }
    }
}


void deposit(account acc[],char *code,float amount,int plithos){
    printf("\t\t\t\tDEPOSIT\n");
for(int i=0;i<plithos;i++){
    if(strcmp(code,acc[i].kwdikos)==0){
        acc[i].balance+=amount;
        printf("your new balance:%.2f\n",acc[i].balance);
        return;
    }else{
        printf("account not found.Deposit failed\n");
        }
    }
}


void withdraw(account acc[],int plithos,char *code,float amount){
    printf("\t\t\t\tWITHDRAW\n");
for(int i=0;i<plithos;i++){
    if(strcmp(code,acc[i].kwdikos)==0){
        if(acc[i].balance<amount){
            printf("insufficient balance\n");
        }else{
        acc[i].balance-=amount;
        printf("your new balance is:%.2f\n",acc[i].balance);

        }
    }else{
     printf("account not found.");
     return;
        }
    }
}

void maskwdikos(char *password){
int index = 0;
char ch;
while ((ch = _getch()) != '\r' && index < MAX_LENGTH - 1) {
if (ch == '\b' && index > 0) {
index--;
printf("\b \b");
}else if (ch != '\b') {
password[index++] = ch;
printf("*");
}
}
password[index] = '\0';
printf("\n");
}
