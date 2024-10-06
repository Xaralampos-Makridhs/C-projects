#include<stdio.h>
#include<windows.h>
#include<time.h>

#define max_an 100
#define max_st 50

typedef struct{
int id;
char species[50];
int age;
char gender[10];
char health[20];
}zwo;

typedef struct{
int id;
char name[50];
char role[30];
}upallhlos;

zwo animal[max_an];
upallhlos staff[max_st];

int animalcount=0;
int staffcount=0;

void addanimal();
void displayanimal();
void searchanimal();
void deleteanimal();
void addstaff();
void stafftoanimal();
void nutrition();
void deletestaff();
void displaystaff();

int main(){
time_t now;
time(&now);
printf("\t\t%s",ctime(&now));
printf("\t\tZoo Managment System\n");
int choice;
    while(1){
        printf("--> 1. Add Animal\n");
        printf("--> 2. Display Animals\n");
        printf("--> 3. Search Animal by species");
        printf("--> 4. Delete Animal\n");
        printf("--> 5. Add Staff member\n");
        printf("--> 6. Display Staff\n");
        printf("--> 7. Assigning staff to an animal\n");
        printf("--> 8. Delete Staff\n");
        printf("--> 9. Animal nutrition programming\n");
        printf("--> 0. Exit\n");
        printf("Enter a valid choice:\n");
        scanf("%d",&choice);
            switch(choice){
                case 1:
                    addanimal();
                    break;
                case 2:
                    displayanimal();
                    break;
                case 3:
                    searchanimal();
                    break;
                case 4:
                    deleteanimal();
                    break;
                case 5:
                    addstaff();
                    break;
                case 6:
                    displaystaff();
                    break;
                case 7:
                    stafftoanimal();
                    break;
                case 8:
                    deletestaff();
                    break;
                case 9:
                    nutrition();
                    break;
                case 0:
                    printf("Exit program.Thank you!");
                    exit(0);
                default:
                    printf("Invalid choice.Enter a valid number!");
            }

    }
return 0;
}

void addanimal(){
    system("cls");
    printf("\t\tAdd a New Animal\n");
    if(animalcount >= max_an){
        printf("The zoo is full. No more animals can be added.\n");
        return;
    }else{
        zwo newan;
        printf("Enter animal ID: ");
        scanf("%d", &newan.id);
        printf("Enter animal species: ");
        scanf("%s", newan.species);
        printf("Enter animal age: ");
        scanf("%d", &newan.age);
        printf("Enter animal gender: ");
        scanf("%s", newan.gender);
        printf("Enter animal health status: ");
        scanf("%s", newan.health);
        animal[animalcount++] = newan;
        printf("The animal has been added successfully!\n");
        printf("----------------------------------------\n");
    }
}

void displayanimal(){
    system("cls");
    printf("\t\tAnimal List\n");
    if(animalcount == 0){
        printf("No animals currently in the zoo.\n");
        return;
    }

    for(int i = 0; i < animalcount; i++){
        printf("Animal ID: %d\n", animal[i].id);
        printf("Species: %s\n", animal[i].species);
        printf("Age: %d\n", animal[i].age);
        printf("Gender: %s\n", animal[i].gender);
        printf("Health Status: %s\n", animal[i].health);
        printf("----------------------------------------\n");
    }
}

void searchanimal(){
    system("cls");
    printf("\t\tSearch for an Animal\n");
    char species[50];
    int found = 0;

    printf("Enter species to search: ");
    scanf("%s", species);
    for(int i = 0; i < animalcount; i++){
        if(strcmp(animal[i].species, species) == 0){
            printf("Animal ID: %d\n", animal[i].id);
            printf("Species: %s\n", animal[i].species);
            printf("Age: %d\n", animal[i].age);
            printf("Gender: %s\n", animal[i].gender);
            printf("Health Status: %s\n", animal[i].health);
            printf("----------------------------------------\n");
            found = 1;
        }
    }

    if(!found){
        printf("No animals found matching the species '%s'.\n", species);
    }
}

void deleteanimal(){
    system("cls");
    printf("\t\tDelete an Animal\n");
    int id, found = 0;

    printf("Enter the animal ID to delete: ");
    scanf("%d", &id);
    if(animalcount == 0){
        printf("The zoo has no animals to delete.\n");
        return;
    }

    for(int i = 0; i < animalcount; i++){
        if(animal[i].id == id){
            found = 1;
            for(int j = i; j < animalcount - 1; j++){
                animal[j] = animal[j + 1];
            }
            animalcount--;
            printf("Animal with ID %d has been successfully deleted.\n", id);
            break;
        }
    }

    if(!found){
        printf("No animal found with ID %d. Please try again.\n", id);
    }
}

void addstaff(){
    system("cls");
    printf("\t\tAdd a New Staff Member\n");
    if(staffcount >= max_st){
        printf("Staff limit reached. Cannot add more staff members.\n");
        return;
    }else{
        upallhlos new_staff;
        printf("Enter staff ID: ");
        scanf("%d", &new_staff.id);
        printf("Enter staff role: ");
        scanf("%s", new_staff.role);
        printf("Enter staff name: ");
        scanf("%s", new_staff.name);
        staff[staffcount++] = new_staff;
        printf("Staff member has been added successfully!\n");
        printf("----------------------------------------\n");
    }
}

void displaystaff(){
    system("cls");
    printf("\t\tStaff Member List\n");
    if(staffcount == 0){
        printf("No staff members available.\n");
        return;
    }

    for(int i = 0; i < staffcount; i++){
        printf("Staff ID: %d\n", staff[i].id);
        printf("Role: %s\n", staff[i].role);
        printf("Name: %s\n", staff[i].name);
        printf("----------------------------------------\n");
    }
}

void stafftoanimal(){
    system("cls");
    printf("\t\tAssign Staff to Animal\n");
    int staffid, animalid;
    int staffexist = 0, animalexist = 0;

    printf("Enter staff ID: ");
    scanf("%d", &staffid);
    printf("Enter animal ID: ");
    scanf("%d", &animalid);

    for(int i = 0; i < animalcount; i++){
        if(animal[i].id == animalid){
            animalexist = 1;
            break;
        }
    }

    for(int i = 0; i < staffcount; i++){
        if(staff[i].id == staffid){
            staffexist = 1;
            break;
        }
    }

    if(animalexist && staffexist){
        printf("Staff member with ID %d has been successfully assigned to animal with ID %d.\n", staffid, animalid);
    }else{
        printf("Error: Either staff or animal not found. Please verify IDs and try again.\n");
    }
}

void deletestaff(){
    system("cls");
    printf("\t\tDelete a Staff Member\n");
    int id, found = 0;

    printf("Enter staff ID to delete: ");
    scanf("%d", &id);
    for(int i = 0; i < staffcount; i++){
        if(staff[i].id == id){
            found = 1;
            for(int j = i; j < staffcount - 1; j++){
                staff[j] = staff[j + 1];
            }
            staffcount--;
            printf("Staff member with ID %d has been successfully deleted.\n", id);
            break;
        }
    }

    if(!found){
        printf("No staff member found with ID %d. Please try again.\n", id);
    }
}

void nutrition(){
    system("cls");
    printf("\t\tAnimal Nutrition Program\n");
    char food_type[30], food_time[30];
    int id, found = 0;

    printf("Enter animal ID: ");
    scanf("%d", &id);
    printf("Enter feeding time: ");
    scanf("%s", food_time);
    printf("Enter food type: ");
    scanf("%s", food_type);

    for(int i = 0; i < animalcount; i++){
        if(animal[i].id == id){
            found = 1;
            printf("Animal with ID %d will be fed at %s with %s.\n", id, food_time, food_type);
            break;
        }
    }

    if(!found){
        printf("No animal found with ID %d. Please try again.\n", id);
    }
}
