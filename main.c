#include "contact.h" 
int main()
{
    AddressBook addressbook;
    initialize(&addressbook);
    loadContactsFromFile(&addressbook, "contacts.txt");
     int choise;
     printf("\n=======*** Welcome To Address Book System ***=======\n");
     while (1) {
        printf("\n1.👉🏻----List Existing Contacts--\n");
        printf("\n2.👉🏻----Add New Contact---------\n");
        printf("\n3.👉🏻----Edit Existing Contacts--\n");
        printf("\n4.👉🏻----Search Contact----------\n");
        printf("\n5.👉🏻----Delete Contact----------\n");
        printf("\n6.👉🏻----Saved Contacts----------\n");
        printf("\n7.❌------Exit--------------------\n");
        printf("\nEnter your choice 🖥️: ");
    
        scanf("%d",&choise);

        switch (choise) {
            case 1: listContacts(&addressbook);
            break;
            case 2: createContact(&addressbook); 
            break;
            case 3: editContact(&addressbook); 
            break;
            case 4: searchContact(&addressbook); 
            break;
            case 5: deleteContact(&addressbook); 
            break;
            case 6: savecontacts(&addressbook, "contacts.txt");
            break;
            case 7: exitProgram();
            break;
            default: printf("Invalid choice.!!!!!!!!\n");
            break;
        }
    }
return 0;

}