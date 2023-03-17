//Name: Kai Ibarrondo and Davis Nguyen
//Project: Bank Management System

//Should have multiple users with ID and password (at least 5). Only those with correct ID and password can login.
//The person should be able to withdraw/deposit cash. To make things easy you do not need to add new customers.
//If you want to make things interesting add a feature of adding a new customer.
//Hint: You can create two files one for keeping track of username and password to keep track.
//Still, you are most welcome to implement however you prefer.


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void menu(char *ID, char *pass);
int check_login(char *ID, char *pass);
int check_ID(char *ID);
void sign_up(char *ID, char *pass);
void deposit(char *ID, char *pass);
void withdraw(char *ID, char *pass);
void view_profile(char *ID, char *pass);


struct profile{
    char ID[100];
    char password[100];
    double balance;
} user;


int main()
{
    char username[500];
    char password[500];
    int select;
    int status_login = 1;
    int status_signup = 1;
    int check_id;
    int check_user;


    printf("\n\n\t\t\t*******************************************\n");
    printf("\t\t\t** WELCOME TO THE BANK MANAGEMENT SYSTEM **\n");
    printf("\t\t\t*******************************************\n");
    printf("\t\t\t       KAI IBARRONDO & DAVIS NGUYEN\n");
    printf("\t\t\t*******************************************\n");
    printf("\t\t\t\t1: LOGIN\n");
    printf("\t\t\t\t2: SIGN UP\n");
    printf("\t\t\t     PRESS ANY OTHER KEY TO END PROGRAM\n");
    printf("\n\t\t\t*******************************************\n\n\n");

    printf("\nEnter your option: ");
    scanf("%d", &select);


    if(select == 2)
    {
        while (status_signup != 0)
        {
            printf("\nPlease enter ID: ");
            scanf("%s", username);

            check_id = check_ID(username);

            if (check_id == 0)
            {
                printf("Please enter password: ");
                scanf("%s", password);
                sign_up(username, password);
                printf("\n\t\t\t\t      Welcome %s!", username);
                menu(username, password);
                break;
            }
            else
            {
                printf("\nThe ID has been taken. Enter 1 to try again or 0 to end the program: ");
                scanf("%d", &status_signup);
                if (status_signup == 0)
                {
                    puts("\nThank you for using the program. Goodbye!");
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
    }

    if(select == 1)
    {
        while (status_login != 0)
        {
            printf("\nPlease enter ID: ");
            scanf("%s", username);
            printf("Please enter password: ");
            scanf("%s", password);

            check_user = check_login(username, password);

            if (check_user == 1)
            {
                printf("\n\t\t\t\t    Welcome Back %s!", username);
                menu(username, password);
                break;
            }
            else
            {
                printf("\nIncorrect ID or password. Enter 1 to try again or 0 to end the program: ");
                scanf("%d", &status_login);
                if (status_login == 0)
                {
                    puts("\nThank you for using the program. Goodbye!");
                    break;
                }
                else
                {
                    continue;
                }
            }
        }
    }
}

int check_login(char *ID, char *pass)
{
    FILE *userFile;
    userFile = fopen("userInfo.txt", "r");
    char line[500];
    int count = 0;
    int check = 0;


    if (userFile == NULL){
        puts("A file can not be opened.");
    }
    while (fgets(line, 500, userFile) != NULL){
        count = 0;
        char *token = strtok(line, " ");
        while (token != NULL){
           if (count == 0){
                strcpy(user.ID, token);
           }
           else if (count == 1){
                strcpy(user.password, token);
           }
           token = strtok(NULL, " ");
           count++;
        }
        if ((strcmp(user.ID, ID) == 0) && (strcmp(user.password, pass) == 0)){
            check++;
        }

    }
    fclose(userFile);
    if (check != 0){
        return 1;
    }
    return 0;
}

int check_ID(char *ID)
{
    FILE *userFile;
    userFile = fopen("userInfo.txt", "r");
    char line[500];
    int count = 0;
    int check = 0;

    if (userFile == NULL){
        puts("A file can not be opened.");
    }
    while (fgets(line, 500, userFile) != NULL){
        count = 0;
        char *token = strtok(line, " ");
        while (token != NULL){
            if (count == 0){
                strcpy(user.ID, token);
            }
            token = strtok(NULL, " ");
            count++;
        }
        if (strcmp(user.ID, ID) == 0){
            check++;
        }
    }
    fclose(userFile);
    if (check != 0){
        return 1;
    }
    return 0;
}


void sign_up(char *ID, char *pass)
{
    FILE *userFile;
    userFile = fopen("userInfo.txt", "a+");
    fprintf(userFile,"%s %s 0.00\n", ID, pass);
    fclose(userFile);
}


void deposit(char *ID, char *pass)
{
    FILE *oldFile;
    FILE *newFile;
    oldFile = fopen("userInfo.txt", "r");
    newFile = fopen("updatedInfo.txt", "w");
    char line[500];
    int count = 0;
    int select;
    double deposit_amount;

    if ((oldFile == NULL) || (newFile == NULL)){
        puts("A file can not be opened.");
    }

    while (fgets(line, 500, oldFile) != NULL){
        count = 0;
        char *token = strtok(line, " ");
        while (token != NULL){
           if (count == 0){
                strcpy(user.ID, token);
           }
           else if (count == 1){
                strcpy(user.password, token);
           }
           else if (count == 2){
                user.balance = strtod(token, &*token);
           }
           token = strtok(NULL, " ");
           count++;
        }
        if ((strcmp(user.ID, ID) == 0) && (strcmp(user.password, pass) == 0)){
            printf("Your current balance is %.2lf\n", user.balance);
            printf("\nEnter the amount you want to deposit: ");
            scanf("%lf",&deposit_amount);
            user.balance += deposit_amount;
            fprintf(newFile,"%s %s %.2lf\n", user.ID, user.password, user.balance);
            printf("The deposit was completed! Your new balance is %.2lf", user.balance);
        }
        else{
            fprintf(newFile,"%s %s %.2lf\n", user.ID, user.password, user.balance);
        }

   }

   fclose(oldFile);
   fclose(newFile);
   remove("userInfo.txt");
   rename("updatedInfo.txt", "userInfo.txt");

   printf("\n\n\nEnter 1 to return to main menu and any other key to end the program: ");
   scanf("%d", &select);

   if (select == 1){
        menu(ID, pass);
   }
   else{
        puts("\nThank you for using the program. Goodbye!");
   }
}



void withdraw(char *ID, char *pass)
{
    FILE *oldFile;
    FILE *newFile;
    oldFile = fopen("userInfo.txt", "r");
    newFile = fopen("updatedInfo.txt", "w");
    char line[500];
    int count = 0;
    int select;
    double withdraw_amount;

    if ((oldFile == NULL) || (newFile == NULL)){
        puts("A file can not be opened.");
    }

    while (fgets(line, 500, oldFile) != NULL){
        count = 0;
        char *token = strtok(line, " ");
        while (token != NULL){
           if (count == 0){
                strcpy(user.ID, token);
           }
           else if (count == 1){
                strcpy(user.password, token);
           }
           else if (count == 2){
                user.balance = strtod(token, &*token);
           }
           token = strtok(NULL, " ");
           count++;
        }
        if ((strcmp(user.ID, ID) == 0) && (strcmp(user.password, pass) == 0)){
            printf("Your current balance is %.2lf\n", user.balance);
            printf("\nEnter the amount you want to withdraw: ");
            scanf("%lf", &withdraw_amount);
            user.balance -= withdraw_amount;
            fprintf(newFile, "%s %s %.2lf\n", user.ID, user.password, user.balance);
            printf("The withdraw was completed! Your new balance is %.2lf", user.balance);
        }
        else{
            fprintf(newFile, "%s %s %.2lf\n", user.ID, user.password, user.balance);
        }
   }

   fclose(oldFile);
   fclose(newFile);
   remove("userInfo.txt");
   rename("updatedInfo.txt", "userInfo.txt");

   printf("\n\n\nEnter 1 to return to main menu and any other key to end the program: ");
   scanf("%d", &select);

   if (select == 1){
        menu(ID, pass);
   }
   else{
        puts("\nThank you for using the program. Goodbye!");
   }
}


void view_profile(char *ID, char *pass)
{
    FILE *userFile;
    userFile = fopen("userInfo.txt","r");
    char line[500];
    int count = 0;
    int select;


    if (userFile == NULL){
        puts("A file can not be opened.");
    }

    printf("\n\nHere is all the info in your profile.\n");
    puts("-------------------------------------");
    while (fgets(line, 500, userFile) != NULL){
        count = 0;
        char *token = strtok(line, " ");
        while (token != NULL){
           if (count == 0){
                strcpy(user.ID, token);
           }
           else if (count == 1){
                strcpy(user.password, token);
           }
           else if (count == 2){
                user.balance = strtod(token, &*token);
           }
           token = strtok(NULL, " ");
           count++;
        }
        if ((strcmp(user.ID, ID) == 0) && (strcmp(user.password, pass) == 0)){
            printf("ID: %s\nPASSWORD: %s\nBALANCE: %.2lf\n", user.ID, user.password, user.balance);
            puts("-------------------------------------");
        }
   }

   fclose(userFile);

   printf("\nEnter 1 to return to main menu and any other key to end the program: ");
   scanf("%d", &select);

   if (select == 1){
        menu(ID, pass);
   }
   else{
        puts("\nThank you for using the program. Goodbye!");
   }

}


void menu(char *ID, char *pass)
{
    int select;
    printf("\n\n\t\t\t*******************************************\n");
    printf("\t\t\t**** BANK MANAGEMENT SYSTEM  MAIN MENU ****\n");
    printf("\t\t\t*******************************************\n");
    printf("\t\t\t       KAI IBARRONDO & DAVIS NGUYEN\n");
    printf("\t\t\t*******************************************\n");
    printf("\t\t\t\t1: DEPOSIT\n");
    printf("\t\t\t\t2: WITHDRAW\n");
    printf("\t\t\t\t3: VIEW PROFILE\n");
    printf("\t\t\t\t4: BACK TO LOGIN\n");
    printf("\t\t\t     PRESS ANY OTHER KEY TO END PROGRAM\n");
    printf("\n\t\t\t*******************************************\n\n\n");


    printf("\nEnter your option: ");
    scanf("%d", &select);

    switch(select){
        case 1:
            deposit(ID, pass);
            break;
        case 2:
            withdraw(ID, pass);
            break;
        case 3:
            view_profile(ID, pass);
            break;
        case 4:
            printf("\n");
            main();
            break;
        default:
            puts("Thank you for using the program. Goodbye!");
    }
}


