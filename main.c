#include "contact.h"

int main()
{   
    //initialing the addressbook
    AddressBook addressbook;
    //loading dummy values to it
    initialize(&addressbook);
    int t=1;
    while(t){

        printf("************** MAIN MENU ***********\n");
        printf("         1.Add contcat\n");
        printf("         2.Search contcat\n");
        printf("         3.edit contcat\n");
        printf("         4.delete contcat\n");
        printf("         5.list contcat\n");
        printf("         6.save contacts\n");
        printf("         7.exit \n");
        // option taking from  user
        int num;
        printf("enter the option :");
        scanf("%d",&num);
        switch (num)
        {
        case 1:
            //calling the createcontact
           createContact(&addressbook);
            break;
        
        case 2:
           //calling searching function
            searchContact(&addressbook);
            break;
        
        case 3:
        // calling the edit function
           editContact(&addressbook);
            break;
        
        case 4:
        // calling the delete function
            deleteContact(&addressbook);
            break;
        
        case 5:
        //calling list contacts functions
           listContacts(&addressbook);
            break;
        
        case 6:
           


        // saving the addressbook
        saveFile(&addressbook);
        break;

        
        default:
        
           t=0;
            
            
        }
    }
    return 0;
    
}

