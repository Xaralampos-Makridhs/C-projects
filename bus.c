#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#define MAX_LENGTH 100


typedef struct{
int number;
char source[100];
char destination[100];
int availableseats;
int totalseats;
float fare;
}lewforeia;

typedef struct{
char name[100];
char password[100];
}xrhsths;

void maskwdikos(char password[]);
void wra();
void mainmenu();
void usermenu();
int login(xrhsths user[],int numusers,char password[],char name[]);
void bookticket(lewforeia bus[],int buses);
void canceltickets(lewforeia bus[],int buses);
void busstatus(lewforeia bus[],int buses);
void separator(int n);
int main(){
lewforeia bus[3]= {
        {101, "City A", "City B", 50, 50, 500.0},
        {102, "City C", "City D", 40, 40, 400.0},
        {103, "City E", "City F", 30, 30, 300.0},
    };
xrhsths user[5]={
        {"user1", "pass1"}, {"user2", "pass2"}, {"user3", "pass3"}, {"user4", "pass4"}, {"user5", "pass5"},
    };


wra();
printf("\n");

int numusers=5;
int buses=3;
int logindex=-1; //gia na syndethei me ta stoixeia tou
int i;
while(1){
    if (logindex==-1){
        mainmenu();
        int choice;
        scanf("%d",&choice);

        if(choice==1){
            char name[50];
            char password[50];
            printf("\t\t\t\tLog in to your account\n");
            printf("Enter your username:");
            scanf("%s",name);
            printf("Enter your password:");
            maskwdikos(password);
            logindex=login(user,numusers,password,name);
            if(logindex==-1){
                printf("Login failed.Check your username and your password!!\n");
                }
                else{
            printf("Login succesfull.Welcome %s\n",name);
            }
        }else if(choice==2){
        printf("Exiting the program.\n");
        break;
        }else{
        printf("invalid choice.Please try again.\n");
        }

    }else{
     usermenu();
     int userchoice;
     scanf("%d",&userchoice);
        switch(userchoice){
    case 1:
        bookticket(bus,buses);
        break;
    case 2:
        canceltickets(bus,buses);
        break;
    case 3:
        busstatus(bus,buses);
        break;
    case 4:
    printf("logging out.\n");
    logindex=-1;
        break;
    default:
        printf("enter a valid option\n");
        }
     }
}
return 0;
}

void mainmenu(){
printf("Main\n");
separator(10);
printf("1. login\n");
printf("2.exit\n");
printf("give option:\n");
}

void usermenu(){
printf("User Menu\n");
separator(10);
printf("1.Book a ticket\n");
printf("2.cancel ticket\n");
printf("3.check bus status\n");
printf("4.logout\n");
printf("enter your choice: ");
}

int login(xrhsths user[],int numusers,char password[],char name[]){
for(int i=0;i<numusers;i++){
    if(strcmp(user[i].name, name)==0 && strcmp(user[i].password, password)==0){
        return i;
    }
}
return -1;
}

void bookticket(lewforeia bus[],int buses){
    int arithmos;
printf("\t\t\t\tBook ticket\n");
printf("Enter the number of the bus:\n");
scanf("%d",&arithmos);
int busindex=-1;
for(int i=0;i<buses;i++){
    if(bus[i].number==arithmos){
        busindex=i;
        break;
    }
}
if(busindex==-1){
    printf("Bus with bus number %d not found.\n",arithmos);
}else{
printf("Enter the number of seats:");
int seats;
scanf("%d",&seats);
if(bus[busindex].availableseats<seats){
    printf("Sorry,only %d seats available: ",bus[busindex].availableseats);
}else{
bus[busindex].availableseats-=seats;
printf("Booking succesfull! %d seats bookedd on Bus Number %d.\n",seats,arithmos);
            }
    }
}

void canceltickets(lewforeia bus[],int buses){
int arithmos;
printf("/t/t/t/tCancel ticket\n");
printf("Enter the bus number\n");
scanf("%d",&arithmos);
int busindex=-1;
for(int i=0;i<buses;i++){
    if(bus[i].number==arithmos){
        busindex=i;
        break;
    }
}

if(busindex==-1){
    printf("Bus with bus number %d not found\n",arithmos);
}else{

printf("Entre number of seats to cancel:");
int seatstocancel;
scanf("%d",&seatstocancel);

if(seatstocancel>bus[busindex].totalseats-bus[busindex].availableseats){
    printf("You cannot cancel more seats than were bookd\n");

}else{

bus[busindex].availableseats+=seatstocancel;
printf("Cancellation successful! %d seats canceled on Bus Number %d.\n ",seatstocancel,arithmos);
        }
    }
}


void busstatus(lewforeia bus[],int buses){
int arithmos;
printf("/t/t/t/tCheck bus status\n");
printf("Enter the number of the bus\n");
scanf("%d",&arithmos);
int busindex=-1;
for(int i=0;i<buses;i++){
    if(bus[i].number==arithmos){
        busindex=i;
        break;
    }
}

if(busindex!=-1){
    printf("\nBus Number: %d\n", bus[busindex].number);
        printf("Source: %s\n", bus[busindex].source);
        printf("Destination: %s\n", bus[busindex].destination);
        printf("Total Seats: %d\n", bus[busindex].totalseats);
        printf("Available Seats: %d\n", bus[busindex].availableseats);
        printf("Fare: %.2f\n", bus[busindex].fare);


}else{
printf("bus with bus number %d not found\n",bus[busindex].number);
       }

}

void separator(int n){
for(int i=0;i<n;i++){
    printf("-");
}
printf("\n");
}

void wra(){
time_t now;
time(&now);
printf("%s",ctime(&now));
}

void maskwdikos(char password[]){
int index = 0;
char ch;
while ((ch = _getch()) != '\r' && index < MAX_LENGTH - 1) {
if (ch == '\b' && index > 0) {
index--;
printf("\b \b");
} else if (ch != '\b') {
password[index++] = ch;
printf("*");
}
}
password[index] = '\0';
printf("\n");
}
