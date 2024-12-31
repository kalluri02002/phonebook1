#include "contact.h"
#include <stdio.h>
//daving file
void saveFile(AddressBook *addressBook)
 {
    FILE *file = fopen("contact.txc", "w");
    if (file == NULL) {
        perror("Unable to open file for writing");
        return;
    }

    for (int i = 0; i < addressBook->contactCount; i++) {
        fprintf(file, "%s, %s, %s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    fclose(file);
    printf("Contacts saved successfully.\n");
}
//intitialize contacts 
void initialize(AddressBook *addressBook) { 
    addressBook->contactCount=0;
    FILE *file = fopen("contact.txc", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }

    char name1[50];
    char phone1[15];
    char email1[50];
    int i = 0;

    // Read until the end of file
    while (fscanf(file, " %49[^,], %14[^,], %49[^\n]\n", name1, phone1, email1) == 3) {
        // Ensure the array index doesn't exceed the limit
        if (i >= MAX_CONTACTS) {
            printf("Address book is full.\n");
            break;
        }

        // Populate the contact information
        strcpy(addressBook->contacts[i].name, name1);
        strcpy(addressBook->contacts[i].phone, phone1);
        strcpy(addressBook->contacts[i].email, email1);

        addressBook->contactCount++;
        i++;
        //printf("%d",addressBook->contactCount);
    }

    fclose(file);
}
// listing the contacts 

void listContacts(AddressBook *addressBook)

{
    int listn = addressBook->contactCount;
    printf("%d",listn);
    printf("***********************The contact book *****8**************\n");
    printf("Sno  Name               phonenumber        email\n");
    printf("*************************************** \n");
    for (int i = 0; i < listn; i++)
    {
        // printing the elements in speacified distances
        printf(" %d   %s          %s         %s\n", i + 1, addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
}

void createContact(AddressBook *addressBook)
{
    int t = 1;
    while (t)
    {
    int valid=1;
    Contact temp;
    
    printf("Please enter the contact details\n");
    
    // Get user inputs
    printf("Please enter the name: \n");
    scanf(" %[^\n]", temp.name); // Using " %[^\n]" to capture full name (with spaces)
    printf("Please enter the phone number: \n");
    scanf("%s", temp.phone); // Getting phone number as a string
    
    
    printf("Please enter the email: \n");
    scanf("%s", temp.email); // Getting email as a string
    
    // Output the collected details
    
    
        // checking the name valid or not

        for (int i = 0; i < strlen(temp.name) - 1; i++)
        {
            if (!((temp.name[i]==' ')|| (temp.name[i] >= 65 && temp.name[i] <= 90) || (temp.name[i] >= 97 && temp.name[i] <= 122)))
            {
                printf("please enter the valide name \n");
                valid = 0;
                break;
            }
        }
        // checking the number is valid or not

        for (int i = 0; i < strlen(temp.phone) - 1; i++)
        {
            if (strlen(temp.phone) != 10)
            {
                printf("please enter the valide phone number \n");
                valid = 0;
                break;
            }
            if (!(temp.phone[i] >= 48 && temp.phone[i] <= 57))
            {
                printf("please enter the valide phone number \n");
                valid = 0;
                break;
            }
        }
        // email valid or not
        if (!(strstr(temp.email, "@") && strstr(temp.email, ".com")))
        {
            valid = 0;
            printf("Please enter the valid email \n");
        }
        // if valid contact will add to the list
        if (valid)
        {
            int n = addressBook->contactCount;
             addressBook->contacts[n] = temp;
         
            printf("added contact successfully\n");
            // stopping while loop
            (addressBook->contactCount)++;
            t = 0;
        }
    }
}

void searchContact(AddressBook *addressBook)
{
    printf("Please the enter the what you want search enter 1 to 3\n");
    char searchstr[50];
    int searchnum1;
    printf("1.Name \n");
    printf("2.phone\n");
    printf("3.email\n");
    // select the vallue to be search
    scanf("%d", &searchnum1);
    // enter the value to be searched
    scanf(" %[^\n]", searchstr);
    int searchnum = addressBook->contactCount;
    int type = 1;
    if (searchnum1 == 1)
    {

        for (int i = 0; i < searchnum; i++)
        {   
            //strcasestr used for check first occurance of searchstr so it will common otput
            if (strcasestr(addressBook->contacts[i].name, searchstr))
            {
                type = 0;
                printf("Name : %s\n", addressBook->contacts[i].name);
                printf("phone number : %s\n", addressBook->contacts[i].phone);
                printf("email : %s\n", addressBook->contacts[i].email);
                printf("\n");
            }
        }
    }
    else if (searchnum1 == 2)
    {

        for (int i = 0; i < searchnum; i++)
        {   
             //strcasestr used for check first occurance of searchstr so it will common otput
            if (strcasestr(addressBook->contacts[i].phone, searchstr))
            {
                type = 0;
                printf("Name : %s\n", addressBook->contacts[i].name);
                printf("phone number : %s\n", addressBook->contacts[i].phone);
                printf("email : %s\n", addressBook->contacts[i].email);
                printf("\n");
            }
        }
    }
    else if (searchnum1 == 3)
    {

        for (int i = 0; i < searchnum; i++)
        {   
             //strcasestr used for check first occurance of searchstr so it will common otput
            if (strcasestr(addressBook->contacts[i].email, searchstr))
            {
                type = 0;
                printf("Name : %s\n", addressBook->contacts[i].name);
                printf("phone number : %s\n", addressBook->contacts[i].phone);
                printf("email : %s\n", addressBook->contacts[i].email);
                printf("\n");
            }
        }
    }
    if (type)
    {
        printf("Not found .......\n");
    }
}

void editContact(AddressBook *addressBook)
{

    printf("Please the enter the option\n");
    char editstr[50];
    int editnum;
    Contact temp;
    printf("1.Name \n");
    printf("2.phone\n");
    printf("3.email\n");
    printf("Please enter the value to be edit : ");
    scanf("%d", &editnum);
   
    int editnum2 = addressBook->contactCount;
    int type = 1;
    if (editnum == 1)
    {
        printf("Please enter the name : ");
        scanf(" %[^\n]", editstr);
        for (int i = 0; i < editnum2; i++)
        {
            if (!strcmp(addressBook->contacts[i].name, editstr))
            {
                type = 0;
                printf("enter the updated values\n");
                printf("Please enter the contact details\n");

                printf("Please enter the name :");
                scanf("%s", temp.name);
                printf("please enter the phone Number :");
                scanf("%s", temp.phone);
                printf("please enter the emeil :");
                scanf("%s", temp.email);
                // using function validating the given inpute
                int valid = validate(&temp);
                if (valid)
                {

                    addressBook->contacts[i] = temp;
                    printf("updated success fully....\n");
                }
            }
        }
    }
    else if (editnum == 2)
    {
         printf("Please enter the phone : ");
         scanf(" %s", editstr);

        for (int i = 0; i < editnum2; i++)
        {
            if (!strcmp(addressBook->contacts[i].phone, editstr))
            {
                type = 0;
                printf("enter the updated values\n");
                printf("Please enter the contact details\n");

                printf("Please enter the name  :");
                scanf("%s", temp.name);
                printf("please enter the phone Number :");
                scanf("%s", temp.phone);
                printf("please enter the emeil :");
                scanf("%s", temp.email);
                 // using function validating the given inpute
                int valid = validate(&temp);
                if (valid)
                {

                    addressBook->contacts[i] = temp;
                    printf("updated success fully....");
                }
            }
        }
    }
    else if (editnum == 3)
    {   
         printf("Please enter the email : ");
         scanf(" %s", editstr);

        for (int i = 0; i < editnum2; i++)
        {
            if (!strcmp(addressBook->contacts[i].email, editstr))
            {
                type = 0;
                printf("enter the updated values\n");
                printf("Please enter the contact details\n");

                printf("Please enter the name :");
                scanf("%s", temp.name);
                printf("please enter the phone Number :");
                scanf("%s", temp.phone);
                printf("please enter the emeil :");
                scanf("%s", temp.email);
                int valid = validate(&temp);
                 // using function validating the given inpute
                if (valid)
                {

                    addressBook->contacts[i] = temp;
                    printf("updated success fully....");
                }
            }
        }
    }
    if (type)
    {
        printf("Not found .......\n");
    }
}

void deleteContact(AddressBook *addressBook)
{
    printf("Please the enter the what you want search enter 1 to 3\n");
    char editstr[50];
    int editnum;

    printf("1.Name \n");
    printf("2.phone\n");
    printf("3.email\n");
    scanf("%d", &editnum);
    printf("Please enter the value want delete : ");
    scanf("%s", editstr);
    int editnum2 = addressBook->contactCount;
    int type = 1;
    if (editnum == 1)
    {

        for (int i = 0; i < editnum2; i++)

        {   
            //strcmp compered total string equall or not if quall output zero
            if (!strcmp(addressBook->contacts[i].name, editstr))
            {
                type = 0;
                for (int j = i; i < editnum2 - 1; i++)
                {
                    addressBook->contacts[i] = addressBook->contacts[i + 1];
                }
                (addressBook->contactCount)--;
                printf("Deleted success fullly\n");
            }
        }
    }
    else if (editnum == 2)
    {

        for (int i = 0; i < editnum2; i++)
        {
            //strcmp compered total string equall or not if quall output zero
            if (!strcmp(addressBook->contacts[i].phone, editstr))
            {
                type = 0;
                for (int j = i; i < editnum2 - 1; i++)
                {
                    addressBook->contacts[i] = addressBook->contacts[i + 1];
                }
                (addressBook->contactCount)--;
                printf("Deleted success fullly\n");
            }
        }
    }
    else if (editnum == 3)
    {
        for (int i = 0; i < editnum2; i++)
        {
            //strcmp compered total string equall or not if quall output zero
            if (!strcmp(addressBook->contacts[i].email, editstr))
            {
                type = 0;
                for (int j = i; i < editnum2 - 1; i++)
                {
                    addressBook->contacts[i] = addressBook->contacts[i + 1];
                }
                printf("Deleted success fullly\n");
                (addressBook->contactCount)--;
            }
        }
    }
    if (type)
    {
        printf("Not found .......\n");
    }
}
// this function used for valid or not
int validate(Contact *temp)
{
    int valid = 1;
    for (int i = 0; i < strlen(temp->name) - 1; i++)
    {
        if (!(temp->name[i] >= 65 && temp->name[i] <= 90 || temp->name[i] >= 97 && temp->name[i] <= 122))
        {
            printf("please enter the valide name \n");
            valid = 0;
            break;
        }
    }
    // checking the number is valid or not

    for (int i = 0; i < strlen(temp->phone) - 1; i++)
    {
        if (strlen(temp->phone) != 10)
        {
            printf("please enter the valide phone number \n");
            valid = 0;
            break;
        }
        if (!(temp->phone[i] >= 48 && temp->phone[i] <= 57))
        {
            printf("please enter the valide phone number \n");
            valid = 0;
            break;
        }
    }
    // email valid or not
    if (!(strstr(temp->email, "@") && strstr(temp->email, ".com")))
    {
        valid = 0;
        printf("Please enter the valid email \n");
    }
    return valid;
}