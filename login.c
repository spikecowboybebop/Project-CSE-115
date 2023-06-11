#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "new_entry.h"
#include "search_record.h"
#include "modify_record.h"
#include "all_records.h"
#include "delete_record.h"

typedef struct
{
    //creating user structure

    char userName[30];//User name must be unique
    char firstName[30];
    char lastName[30];
    char userPassword[30];//user password needed to log in

} UserType;
void patient_system() {
struct patient_data *ptr;
    ptr = (struct patient_data *)malloc(1 * sizeof(struct patient_data));
    int c;
    do {
        printf("[Enter a] Add New Patient Records\n");
        printf("[Enter b] Search Existing Patient Records\n");
        printf("[Enter c] Modify Existing Patient Records\n");
        printf("[Enter d] Delete Patient Records\n");
        printf("[Enter e] View All Records\n");
        printf("[Enter f] Exit\n");
        printf("Choice - ");

        char b;
        scanf("%c", &b);
        fflush(stdin);

        switch (b) {
            case 'a':
                new_entry(ptr);
                break;
            case 'b':
                search_record(ptr);
                break;
            case 'c':
                modify_record(ptr);
                break;
            case 'd':
                delete_record();
                break;
            case 'e':
                all_records(ptr);
                break;
            case 'f':
                printf("Thank You\n");
                break;
            default:
                printf("Error\n");
                break;
        }
        printf("\nEnter 1 to do it again or 0 to exit - ");
        scanf("%d", &c);
        fflush(stdin);
        printf("\n");
        system("cls");
    } while (c != 0);

}
void showUserMenu()
{
    //this menu will show for registration , log in or deleting user
    // This menu will appear at the start of the project

    printf("1.New user register \n");
    printf("2.User log in \n");
    printf("3.Delete user\n");
    printf("4.Exit\n");
}
void newUser()
{

    UserType newUser;// this structure is used to create a new user
    UserType user;// this structure will read user from file

    FILE* fp;

    while(1)
    {
        //here we are taking user name from the user and determining the size of user name

        fflush(stdin);//this is to clear the input buffer from new lines
        printf("User Name : ");
        gets(newUser.userName);

        if(strlen(newUser.userName)>4&&strlen(newUser.userName)<30)  //strlen to determine the size of userName
        {

            break;
        }
        printf("Username size must be between 5 and 30 \n");
    }

    fp= fopen("userInfo.txt", "r");//opening user file in reading mode

    while(fscanf(fp, "%s %d", user.userName, &user.userPassword) == 2)
    {

        if(strcmp(user.userName,newUser.userName)==0)  //comparing strings of new user and existing user from file
        {

            printf("User name is already taken. Please enter another user name \n");
            fclose(fp);
            return;// this return will return the user to user menu
        }
    }

    fclose(fp);

    fflush(stdin);
    printf("First Name : ");
    gets(newUser.firstName);

    fflush(stdin);
    printf("Last Name : ");
    gets(newUser.lastName);

    while(1)
    {
        //taking password input and making sure that is has appropriate size

        fflush(stdin);
        printf("Password : ");
        gets(newUser.userPassword);

        if(strlen(newUser.userPassword)>3&&strlen(newUser.userPassword)<30)  //determining the size of password
        {

            break;
        }
        printf("Password size must be between 4 and 30 \n");
    }

    fp= fopen("userInfo.txt", "a");//opening file in append mode

    if(fp==NULL)  //if there is no file
    {

        printf("File could not be opened");
    }

    fprintf(fp,"%s %s\n", newUser.userName,newUser.userPassword); //writing about new user in the file

    fclose(fp);
}
UserType userLogIn()
{
    //this function tries to log in and returns the user

    char userName[30];//log in username
    char pass[30];//if the password is correct user will log in

    UserType user;// creating a structure

    fflush(stdin);
    printf("Enter user name : \n");
    gets(userName);// log in username

    printf("Enter password : \n");
    gets(pass);// log in user password

    FILE* fp;

    fp= fopen("userInfo.txt", "r");

    while(fscanf(fp, "%s %s", user.userName, user.userPassword) == 2)
    {

        if(strcmp(user.userName, userName)==0 && strcmp(user.userPassword, pass)==0)  //comparing string for user and password from user input and file
        {

            return user;
        }
    }

    strcpy(user.userName,"NULL");// here the user is null when log in is unsuccessful

    return user;// returning null user

}
int countUsers()
{
    // this function will count the number of users in the user file

    int count = 0; //variable used to count users
    char username[50], password[50]; //buffer to read each user's information from file

    FILE *fp;

    fp = fopen("userInfo.txt", "r");

    while (fscanf(fp, "%s %s", username, password) == 2)
    {
        //here we are reading the username and password (two strings) for each user and counting the number of users

        count++;
    }

    fclose(fp);

    return count;//here we return the number of users
}

void deleteUser()
{
    //here we will delete a user

    int index= -1;//if index does not change it means the user is not found
    int i=0;
    int count= countUsers();//counting the number of users
    char userName[30];
    char userPass[30];

    UserType *users=(UserType*) malloc(count * sizeof(UserType));
    //creating an array of dynamic size for UserType users[count];

    fflush(stdin);
    printf("Enter user name to delete : ");
    gets(userName);

    fflush(stdin);
    printf("Enter user pass : ");
    gets(userPass);

    FILE* fp;
    fp= fopen("userInfo.txt", "r");

    while(fscanf(fp, "%s %s", users[i].userName, users[i].userPassword) != EOF)
    {

        if(strcmp(users[i].userName,userName)==0&&strcmp(users[i].userPassword,userPass)==0 )
        {
            //if we find the user to delete from the string compare then we will get the index of the user to delete

            index =i;
        }

        i++;
    }

    fclose(fp);

    if(index== -1)
    {
        // if we do not get the user, the index will remain unchanged

        printf("The user was not found \n");
        return; //this will return the user to user menu
    }

    for(i=index; i<count-1; i++)
    {
        //this loop is used to delete the user by bringing all the users at the right 1 place left

        users[i]= users[i+1]; //here we are taking the user to the rightmost array
    }

    fp= fopen("userInfo.txt", "w");

    printf("\nUser deleted \n");

    for(i=0; i<count-1; i++)
    {
        fprintf(fp, "%s %s\n", users[i].userName, users[i].userPassword);
    }

    fclose(fp);
}
void showHospitalMenu(){

    printf("1. Patient\n");
    printf("2. Staff\n");
    printf("3. Pharmacy\n");
    printf("4. Log Out\n");
}
void mainMenu(UserType currentUser)
{

    UserType user;//structure for user
    int userChoice;//userChoice for switch case

    while(1)
    {

        showHospitalMenu(); // showing the book menu
        printf("User choice : ");
        scanf("%d", &userChoice);//user will choose what to do
        fflush(stdin);

        switch(userChoice)
        {
        case 1:
                patient_system();
                break;
        case 2:
                printf("Staff System\n");
                break;
        case 3:
                printf("Inventory System\n");
                break;

        case 4:

            return;//returning to user menu after logging out
            break;

        default:

            printf("Please enter a valid option \n");//if user inputs an non valid option in the book menu

        }
        printf("Enter any button to continue...\n");
        getc(stdin); //character input
        system("cls"); //console clean
    }
}

int main()
{

    int userMenuChoice;//user input for user menu
    int count; //variable for counting
    int i;// variable to use loops
    int userInput;//variable to get user input
    int result;// variable to get a result
    UserType users;// structure for users
    UserType user;// structure for user

    FILE* fp;
    fp = fopen("userInfo.txt", "r");

    if(fp==NULL)
    {
        fp = fopen("userInfo.txt", "w");
    }
    fclose(fp);

    while(1)
    {

        showUserMenu();// showing the user menu
        printf("User choice : ");
        scanf("%d", &userMenuChoice);
        fflush(stdin);

        switch(userMenuChoice)
        {

        case 1:

            newUser();// creating a new user using this function

            break;

        case 2 :

            user=userLogIn();

            if(strcmp(user.userName,"NULL") !=0)
            {
                //when user log in fails a null user is returned
                //when logged in successful we are sending to main menu with logged in user information
                system("cls");
                mainMenu(user);
            }
            else
            {
                printf("Log in failed, please try again\n");// for null user
            }

            break;
        case 3 :

            deleteUser();// deleting a user

            break;

        case 4 :

            return 0;// exit

            break;
        default:
            // if user enters a non valid option

            printf("Please enter a valid option \n");
        }

        printf("Enter any button to continue...\n");
        getc(stdin); //character input
        system("cls"); //console clean
    }
    return 0;
}

