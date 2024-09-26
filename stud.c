#include<stdio.h>
#include<windows.h>
#include<string.h>


int i=0;//metraei tous foithtes

typedef struct{
char fname[10];
char lname[10];
int roll;
float gpa;
int cid[10];
}stud;

void updatestudents(stud student[]);
void deletestudent(stud student[]);
void totalnumber(stud student[]);
void findcourseid(stud student[]);
void findfname(stud student[]);
void addst(stud student[]);
void findroll(stud student[]);


int main(){
stud student[55];
int choice;
    while(i=1){
    printf("The task that you want to perform:\n");
    printf("1. Add student details\n");
    printf("2. Find the student details by roll number\n");
    printf("3. Find the student details by the first name\n");
    printf("4. Find the student details by course ID\n");
    printf("5. Find the total number of studnets\n");
    printf("6. Delete the students details by roll number\n");
    printf("7. Update the students detail by roll numbers\n");
    printf("8. Exit\n");
    printf("Enter your choice to find the task\n");
    scanf("%d",&choice);
    system("cls");
        switch(choice){
case 1:
    addst(student);
    break;
case 2:
    findroll(student);
    break;
case 3:
    findfname(student);
    break;

case 4:
    findcourseid(student);
    break;
case 5:
    totalnumber(student);
    break;
case 6:
    deletestudent(student);
    break;
case 7:
    updatestudents(student);
    break;

case 8:
    exit(0);
default:
    printf("enter a valid number-choice\n");
        }
    }



return 0;
}


void addst(stud student[]){
printf("Add Student Details\n");
printf("-------------------\n");
printf("Enter the first name of the student:\n");
scanf("%s",student[i].fname);
printf("Enter the last name of the student:\n");
scanf("%s",student[i].lname);
printf("Enter the roll number of the student:\n");
scanf("%d",&student[i].roll);
printf("Enter the GPA of the student:\n");
scanf("%f",&student[i].gpa);
printf("Enter the course ID of each course:\n");
for(int j=0;j<5;j++){
    scanf("%d",&student[i].cid[j]);
    }
i++;
printf("Student Add Succesfully");
}

void findroll(stud student[]){
printf("Find the student by the roll number\n");
int x;
printf("Enter the roll number:");
scanf("%d",&x);
for(int j=0;j<i;j++){
if(x==student[i].roll){
    printf("The student details are:\n");
    printf("The  first name is:%s",student[i].fname);
    printf("The last name is:%s",student[i].lname);
    printf("The GPA is:%f",student[i].gpa);
}
    for(int j=0;j<i;j++){
        printf("The course ID are:%d\n",student[i].cid[j]);
    }
break;
}
}

void findfname(stud student[]){
char a[50];
int c=0;
    for(int j=0;j<i;j++){
        if(strcmp(a,student[j].fname)==0){
        printf("The students details are:\n");
        printf("------------------------\n");
        printf("The first name of the student is:%s\n",student[i].fname);
        printf("The last name of the student is:%s\n",student[i].lname);
        printf("The roll nuumber of the student is:%d\n",student[i].roll);
        printf("The GPA of the student is:%f\n",student[i].gpa);
            for(int j=0;j<5;j++){
            printf("The ID of the courses are:%d\n",student[i].cid[j]);
            }
        c=1;
        }
    else printf("The first name did not found.\n");
    }
}

void findcourseid(stud student[]){
printf("Find the student details from course IDs\n");
printf("Enter the course ID:\n");
int courseID;
scanf("%d",&courseID);
int c=0;
    for(int j=0;j<i;j++){
        for(int d=0;d<5;d++){
            if(courseID==student[j].cid[d]){
            printf("The students details are:\n");
        printf("------------------------\n");
        printf("The first name of the student is:%s\n",student[i].fname);
        printf("The last name of the student is:%s\n",student[i].lname);
        printf("The roll nuumber of the student is:%d\n",student[i].roll);
        printf("The GPA of the student is:%f\n",student[i].gpa);
            c=1;
            break;
            }else{
                printf("The first name not found.\n");
            }
        }
    }
}

void totalnumber(stud student[]){
printf("The total numer of the students is:%d\n",i);
printf("You can have a max of 50 students\n");
printf("you can have %d more students",50-i);
}

void deletestudent(stud student[]){
printf("Delete student\n");
printf("Enter the roll number of the student:\n");
int a;
scanf("%d",&a);
    for(int j=0;j<i;j++){
        if(a==student[j].roll){
            for(int d=0;d<49;d++){
                student[d]=student[d+1];
                i--;
            }

        }
        printf("The student with roll number %d deleted succesfully",a);
    }
}

void updatestudents(stud student[]){
printf("Enter the roll number to update the entry:\n");
long int x;
int uchoice;
scanf("%ld",&x);
    for(int j=0;j<i;j++){
        if(x==student[j].roll){
        printf("1. First name\n");
        printf("2. Last name\n");
        printf("3. Roll");
        printf("4. GPA\n");
        printf("5. ID courses\n");
        printf("enter a choice between 1-5");
        scanf("%d",&uchoice);
            switch(uchoice){
        case 1:
            printf("enter the new first name:\n");
            scanf("%s",student[j].fname);
            break;
        case 2:
            printf("enter the new last name:\n");
            scanf("%s",student[i].lname);
            break;
        case 3:
            printf("enter the new roll number:\n");
            scanf("%d",&student[i].roll);
            break;
        case 4:
            printf("Enter the new GPA:\n");
            scanf("%f",&student[i].roll);
            break;
        case 5:
            printf("enter the new ID courses:\n");
            scanf("%d%d%d",&student[j].cid[0],&student[j].cid[1],&student[j].cid[2],&student[j].cid[3],&student[j].cid[4]);
            break;
        case 6:
            exit(0);
        default:
            printf("enter a valid choice-number\n");
            break;
            }
        }
    }
}

