#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
char name[100];
char number[100];
float usage;
float totalbill;
}customer;



customer pelaths[100];
int count=0;
void menu();
void addnewrecord();
void viewlist();
void modify(char phonenumber[]);
void payment(char phonenumber[]);
void deleterecord(char phonenumber[]);



int main(){
int choice;
char phonenumber[20];
while(1){
    menu();
    printf("Enter your choice:");
    scanf("%d",&choice);

    switch(choice){
    case 1:
        addnewrecord();
        break;

    case 2:
        viewlist();
        break;
    case 3:
        printf("enter your phone to modify your record:");
        scanf("%s",phonenumber);
        modify(phonenumber);
        break;
    case 4:
        printf("enter your phone to view your record:");
        scanf("%s",phonenumber);
        payment(phonenumber);
        break;
    case 5:
        printf("enter your phone to delete your record:");
        scanf("%s",phonenumber);
        deleterecord(phonenumber);
        break;
    case 6:
        exit(0);
    default:
        printf("enter a valid choice!");
        break;
    }
}
return 0;}


void menu(){
printf("\n1. Add New Record\n");
printf("2. View List of Records\n");
printf("3. Modify Record\n");
printf("4. View Payment\n");
printf("5. Delete Record\n");
printf("6. Exit\n");
}


void addnewrecord(){
    if(count<100){
printf("Enter your name:");
scanf("%s", pelaths[count].name);
printf("enter your number:");
scanf("%s",pelaths[count].number);
printf("enter your usage(in minutes):");
scanf("%f",&pelaths[count].usage);
pelaths[count].totalbill=pelaths[count].usage*0.1;
printf("Total Bill:%.2f",pelaths[count].totalbill);
count++;
printf("\nRecord added successfully!\n");
    }else{
    printf("\nMaximum number of records reached!\n");
    }
}

void viewlist(){
    printf("\n%-20s %-15s %-10s %-10s\n", "Name", "Phone Number", "Usage(min)", "TotalBill(euros)");
    printf("---------------------------------------------------------------\n");
    for(int i = 0; i < count; i++){
        printf("%-20s %-15s %-10.2f %-10.2f\n",
               pelaths[i].name, pelaths[i].number, pelaths[i].usage,
               pelaths[i].totalbill);
    }
}

void modify(char phonenumber[])
{
    for (int i=0;i<count;i++){
        if (strcmp(pelaths[i].number, phonenumber) == 0) {
            printf("\nEnter new usage (in minutes) for %s: ",pelaths[i].name);
            scanf("%f", &pelaths[i].usage);
            pelaths[i].totalbill = pelaths[i].usage * 0.1;
            printf("\nRecord modified successfully!\n");
            return;
        }
    }
    printf("\nRecord not found!\n");
}


void payment(char phonenumber[]){
for(int i=0;i<count;i++){
    if(strcmp(phonenumber,pelaths[i].number)==0){
        printf("Payment:%.2f",pelaths[i].totalbill);
        return;
    }else{
    printf("wrong phone.try again\n");}

    }
}

void deleterecord(char phonenumber[]){
for(int i=0;i<count;i++){
    if(strcmp(phonenumber,pelaths[i].number)==0){
        for(int j=i;j<count-1;j++){
            pelaths[j]=pelaths[j+1];
            count--;
            printf("record deleted succesfully\n");
            return;
        }

    }else{printf("record not found\n");}
}

}




