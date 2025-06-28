#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>

void setcolor(int color){
HANDLE hconsole=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hconsole,color);
}

typedef struct{
int id;
char name[30];
char eidikothta[30];
}giatros;

typedef struct{
int id;
char name[30];
char disease[30];
int age;
}asthenis;

typedef struct{
int id;
char date[20];
int doctorid;
int patientid;
}rantevou;

rantevou appointment[100];
giatros doctor[100];
asthenis patient[100];

int doctorscount=0;
int patientcount=0;
int appointmentcount=0;

void adddoctor();
void editdoctor();
void deletedoctor();
void addpatient();
void editpatient();
void deletepatient();
void addappointment();
void deleteappointment();
void searchdoctor();
void statistics();
void searchdoctorid();
void searchdoctorname();

int main(){
    int choice;
    setcolor(5);
    while(1){

time_t now;
time(&now);
printf("\t\t\t%s",ctime(&now));// wra

    printf("\t\t\tHospital Managment System\n");
    printf("--> 1. Add Doctor\n");
    printf("--> 2. Edit Doctor\n");
    printf("--> 3. Delete Doctor\n");
    printf("--> 4. Add Patient\n");
    printf("--> 5. Edit Patient\n");
    printf("--> 6. Delete Patient\n");
    printf("--> 7. Add Appointment\n");
    printf("--> 8. Delete Appointment\n");
    printf("--> 9. Search Doctor\n");
    printf("--> 10. Display Statistics\n");
    printf("--> 0. Exit\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
        switch(choice){
            case 1:
                adddoctor();
                break;
            case 2:
                editdoctor();
                break;
            case 3:
                deletedoctor();
                break;
            case 4:
                addpatient();
                break;
            case 5:
                editpatient();
                break;
            case 6:
                deletepatient();
                break;
            case 7:
                addappointment();
                break;
            case 8:
                deleteappointment();
                break;
            case 9:
                searchdoctor();
                break;
            case 10:
                statistics();
                break;
            case 0:
                printf("Exit.Thank you for yiur trust!\n");
                exit(0);
        }
    }
return 0;
}

void adddoctor(){
system("cls");
printf("\t\t\tAdd Doctor\n");

int id;
    printf("Enter the doctor ID to add:");
    scanf("%d",&id);

    for(int i=0;i<doctorscount;i++){
        if(doctor[i].id==id){
            printf("Doctor already exists\n");
            return;
        }
    }
doctor[doctorscount].id=id;
printf("Enter the name of the doctor:\n");
scanf(" %[^\n]",doctor[doctorscount].name);
printf("Enter the specialization of the doctor:\n");
scanf(" %[^\n]",doctor[doctorscount].eidikothta);
doctorscount++;
printf("Doctor with ID:%d Added Succesfully\n",id);
}

void editdoctor(){
        system("cls");
    printf("\t\tEdit Doctor\n");
    int id,choice;
    int found=0;
    printf("Enter the doctor ID to edit: ");
    scanf("%d",&id);
        for(int i=0;i<doctorscount;i++){
            if(doctor[i].id==id){
                printf("--> 1.Name\n");
                printf("--> 2.Specialization\n");
                printf("--> 3.ID\n");
                printf("What detail you want to edit?\n");
                scanf("%d",&choice);
                    fflush(stdin);
                    switch(choice){
                        case 1:
                            printf("Enter the new name of the doctor:");
                            scanf("%[^\n]",doctor[i].name);
                            break;
                        case 2:
                            printf("Enter the new specialization:");
                            scanf("%[^\n]",doctor[i].eidikothta);
                            break;
                        case 3:
                            printf("Enter the new ID for the doctor:");
                            scanf("%d",&doctor[i].id);
                            break;
                        default:
                            printf("Enter a valid choice.Please try again\n");

                    }
                    printf("Doctor Details updated succesfully!\n");
                    found=1;
            }

        }
        if(!found){
            printf("The ID:%d you gave is wrong.Please try again!\n",id);
        }
}

void deletedoctor(){
system("cls");
int id;
int found=0;
printf("\t\tDelete Doctor\n");
printf("Enter the doctor ID you want to delete:");
scanf("%d",&id);
    for(int i=0;i<doctorscount;i++){
        if(doctor[i].id==id){
                for(int j=i;j<doctorscount-1;j++){
                    doctor[j]=doctor[j+1];
                }
                    doctorscount--;
                    printf("Doctor Deleted Succesfully!\n");
                    found=1;
                    break;
        }
    }
    if(!found){
        printf("The doctor ID:%d you entered is wrong\n",id);
    }
}

void addpatient(){
system("cls");
printf("\t\tAdd Patient\n");
int id;
printf("Enter the patient ID you want to add:");
scanf("%d",&id);
    for(int i=0;i<patientcount;i++){
        if(patient[i].id==id){
            printf("Enter the patient already exsits\n");
            return;
        }

    }
patient[patientcount].id=id;
printf("Enter the name of the patient:");
scanf("%[^\n]",patient[patientcount].name);
printf("Enter the disease of the patient:");
scanf("%[^\n]",patient[patientcount].disease);
printf("Enter the age of the patient:");
scanf("%d",&patient[patientcount].age);
while(patient[patientcount].age<=0 || patient[patientcount].age>=110){
    printf("Invalid Age.Please enter a valid age for your patient(1-110)");
    scanf("%d",&patient[patientcount].age);
}
patientcount++;
printf("Patient with ID:%d added succesfully!",id);
}

void editpatient(){
system("cls");
int id,choice;
int found=0;
printf("\t\tEdit Patient\n");
printf("Enter the patient ID:");
scanf("%d",&id);
    for(int i=0;i<patientcount;i++){
        if(patient[i].id==id){
            printf("--> 1. ID\n");
            printf("--> 2. Disease\n");
            printf("--> 3. Age\n");
            printf("--> 4. Name\n");
            printf("Enter the choice you want to edit:");
            scanf("%d",&choice);
                fflush(stdin);
                switch(choice){
                    case 1:
                        printf("Enter the new ID:");
                        scanf("%d",patient[i].id);
                        break;
                    case 2:
                        printf("Enter the new Disease:");
                        scanf("%[^\n]",patient[i].disease);
                        break;
                    case 3:
                        printf("Enter the new age:");
                        scanf("%d",&patient[i].age);
                        break;
                    case 4:
                        printf("Enter th new Name:");
                        scanf("%[^\n]",patient[i].name);
                        break;
                    default:
                        printf("Enter a valid choice.Please try again\n");

                }
                printf("Patient details updated succesfully!");
                found=1;
        }
    }
        if(!found){
            printf("The ID:%d you gave is wrong.Please try again",id);
        }
}

void deletepatient(){
int id;
int found=0;
system("cls");
printf("\t\tDelete Patient\n");
printf("Enter the patient ID:");
scanf("%d",&id);
    for(int i=0;i<patientcount;i++){
        if(patient[i].id==id){
            for(int j=i;j<patientcount-1;j++){
                patient[j]=patient[j+1];
            }
                patientcount--;
                printf("Patient Deleted Succesfully");
                found=1;
                break;
        }
    }
        if(!found){
            printf("Enter the ID you gave is wrong.Please try again\n");
        }
}

void addappointment(){
int id;
int doctorid,patientid,doctorexist=0,patientexist=0;
system("cls");
printf("\t\tAdd Appointment");
printf("Enter the appointment ID:");
scanf("%d",&id);

    for(int i=0;i<appointmentcount;i++){
        if(appointment[i].id==id){
            printf("The appointment with this ID:%d already exists.Try again\n",id);
            return;
        }
    }
printf("Enter the doctor ID:");
scanf("%d",&doctorid);
printf("Enter the patient ID:");
scanf("%d",&patientid);
    //elegxos an o asthenis yparxei
    for(int i=0;i<patientcount;i++){
        if(patient[i].id==patientid){
            patientexist=1;
            break;
        }
    }
    //elegxos an o giatros yparxei
    for(int i=0;i<doctorscount;i++){
        if(doctor[i].id==doctorid){
            doctorexist=1;
            break;
        }
    }
        if(!doctorexist){
            printf("Doctor with ID:%d doesn't exists.Please try again\n",doctorid);
            return;
        }

        if(!patientexist){
            printf("Patient with ID:%d doesn't exists.Please try again\n",patientid);
            return;
        }

appointment[appointmentcount].id=id;
appointment[appointmentcount].doctorid=doctorid;
appointment[appointmentcount].patientid=patientid;
printf("Enter the date of the appointment dd/mm/yy: ");
scanf("%19[^\n]",appointment[appointmentcount].date);
appointmentcount++;
printf("The appointment added succesfully!");
}

void deleteappointment(){
    system("cls");
printf("\t\tDelete Appointment\n");
int id;
int found=0;
printf("Enter the patient ID:");
scanf("%d",&id);
    for(int i=0;i<appointmentcount;i++){
        if(appointment[i].id==id){
            for(int j=i;j<appointmentcount-1;j++){
                appointment[j]=appointment[j+1];
            }
            appointmentcount--;
            printf("The appointment deleted succesfully!");
            found=1;
            break;
        }
    }

    if(!found){
        printf("The appointment ID:%d you entered is wrong.Please try again\n",id);
    }
}

void searchdoctor(){
int choice;
system("cls");
printf("\t\tSearch Doctor\n");
printf("Do you want to search doctor by the  name or by the ID? (1=YES 2=NO)");
scanf("%d",&choice);
    switch(choice){
        case 1:
            searchdoctorid();
            break;
        case 2:
            searchdoctorname();
            break;
        default:
            printf("Enter a valid choice. 1 or 2");
    }
}

void searchdoctorid(){
    system("cls");
printf("\t\tSearch Doctor By the ID\n");
int doctorid;
int found=0;
printf("Enter the doctor ID you want to search:");
scanf("%d",&doctorid);

    for(int i=0;i<doctorscount;i++){
        if(doctor[i].id==doctorid){
            printf("The name of the doctor is:%s\n",doctor[i].name);
            printf("The specialization of the doctor is:%s\n",doctor[i].eidikothta);
            printf("The ID of the doctor is:%d\n",doctor[i].id);
            found=1;
            break;
        }
    }
        if(!found){
            printf("The doctor with ID:%d didn't found\n",doctorid);
        }
}

void searchdoctorname(){
system("cls");
printf("\t\tSearch Doctor by the Name\n");
char name[20];
int found=0;
printf("Enter the name of the doctor:");
scanf("%[^\n]",name);
    for(int i=0;i<doctorscount;i++){
        if(strcmp(doctor[i].name,name)==0){
            printf("Doctor's name:%s\n",doctor[i].name);
            printf("Doctor's ID:%d",doctor[i].id);
            printf("Doctor's Specialization:%s",doctor[i].eidikothta);
            found=1;
            return;
        }
    }

        if(!found){
            printf("The name of the doctor you entered doesn't exist");
        }
}

void statistics(){
system("cls");
printf("\t\tDisplay Statistics\n");
printf("APPOINTMENT COUNT:%d\n",appointmentcount);
printf("PATIENT COUNT:%d\n",patientcount);
printf("DOCTOR COUNT:%d\n",doctorscount);
}
