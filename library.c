#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


typedef struct{
char author[20];
char bookname[20];
float price;
int pages;
}book;

void setcolor(int color){
HANDLE hconsole=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hconsole,color);
}


int main(){
book biblio[100];
int i;
int count;
int input;
char author_name[100];
count=0;
input=0;
i=0;
time_t now;
time(&now);
printf("%s\n",ctime(&now));
setcolor(3);
while(input!=5){
    printf("1.Add Book informations\n");
    printf("2.Display book informations\n");
    printf("3.List all books of given author\n");
    printf("4.List the count of the books\n");
    printf("5.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&input);
        switch(input){
    case 1:
        printf("Enter the name of the book:");
        scanf("%s",biblio[i].bookname);

        printf("Enter the name of the author:");
        scanf("%s",biblio[i].author);

        printf("Enter the price of the book:");
        scanf("%f",&biblio[i].price);

        printf("enter the pages of the book:");
        scanf("%d",&biblio[i].pages);
        count++;
        break;
    case 2:
        printf("Y add those informations:\n");
        for(i=0;i<count;i++){
        printf("name of the book:%s",biblio[i].bookname);
        printf("name of the author:%s",biblio[i].author);
        printf("price of the book:%.2f",biblio[i].price);
        printf("pages of the book:%d",biblio[i].pages);
            }

        break;
    case 3:
        printf("list all books of given author:");
        scanf("%s",author_name);
        for(i=0;i<count;i++){
            if(strcmp(biblio[i].author,author_name)==0){
                printf("name: %s\n author: %s\n pages: %d\n price: %.2f\n",biblio[i].bookname,biblio[i].author,biblio[i].pages,biblio[i].price);
            }
        }
        break;
    case 4:
        printf("the count of books is:%d\n",count);
        break;
    case 5:
        exit(0);
    default:
        printf("invalid choice.enter a number between 1-5");

        }
}



return 0;}
