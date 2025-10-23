#include "contact.h"
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void listContacts(AddressBook *addressBook) 
{
    printf("S.No  Name                 Contact         Email\n");
    printf("-------------------------------------------------------\n");
    for (int i = 0; i < addressBook->contactCount; i++) {
        printf("%-5d %-20s %-15s %s \n", i + 1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);       
    }
}
void createContact(AddressBook *addressBook) {
    if (addressBook->contactCount >= MAX_CONTACTS) {
        printf("Cannot add more contacts. Maximum limit (%d) reached.\n", MAX_CONTACTS);
        return;
    }
    char newName[100], phone[11], email1[100];
    char choice12[100];

    printf("........Add New Contact.......\n");
     while (1) {
    printf("1. Exit                    2. Continue\n");
    printf("Enter your choice: ");
    scanf(" %s", choice12);

    if (strcmp(choice12,"1") == 0) {
        return;
    } else if (strcmp(choice12,"2")== 0) {
        break; 
    } else {
        printf("Invalid Choice. Please try again: \n");
    }
}
    printf("Enter Name : ");
    scanf(" %[^\n]s", newName);
    ValidName(addressBook, newName);

    printf("Enter Phone : ");
    scanf("%s",phone);
    ValidPhone(addressBook, phone);
    

    printf("Enter Email: ");
    scanf(" %[^\n]s", email1);
    ValidEmail(addressBook, email1);
    
      
    addressBook->contactCount++;
    printf("Contact Add Successfully.\n");

}
void searchContact(AddressBook *addressBook){
    char searchName[100];
    char searchPhone[100];
    char searchEmail[100];
    int search;
    char choice12[100];
    while (1) {
    printf("1. Exit                    2. Continue\n");
    printf("Enter your choice: ");
    scanf(" %s", choice12);

    if (strcmp(choice12,"1") == 0) {
        return;
    } else if (strcmp(choice12,"2")== 0) {
        break; 
    } else {
        printf("Invalid Choice. Please try again: \n");
    }
}
    printf("\nSearch by\n1.Name\n2.Phone Number\n3.Email Id\nEnter the Choice: ");
    scanf("%d", &search);

    switch (search) {
    case 1:
    label1:
        printf("Enter the name to search: ");
        scanf(" %[^\n]", searchName); 
        int flag = 0;
        for (int i = 0; i < addressBook->contactCount; i++) {
            if (strcmp(addressBook->contacts[i].name, searchName) == 0) {
                    printf("\n====***Contacts Found***====\n");
                printf("Name   : %s\n", addressBook->contacts[i].name);
                printf("Phone  : %s\n", addressBook->contacts[i].phone);
                printf("Email  : %s\n\n", addressBook->contacts[i].email);
                flag = 1;
            }
        }
        if (flag == 0) {
            printf("Name Not Found\n");
            goto label1;
        }
        break;

    case 2:
    label2:
        printf("Enter the phone number to search: ");
        scanf(" %s", searchPhone); 
        int flag1 = 0;
        for (int i = 0; i < addressBook->contactCount; i++) {
            if (strcmp(addressBook->contacts[i].phone, searchPhone) == 0) {
                printf("\n====***Contact found====***\n");
                printf("Name  : %s\n", addressBook->contacts[i].name);
                printf("Phone : %s\n", addressBook->contacts[i].phone);
                printf("Email : %s\n", addressBook->contacts[i].email);
                flag1 = 1;
                break;
            }
        }
        if (flag1 == 0) {
            printf("Phone Number Not Found\n");
            goto label2;
        }
        break;

    case 3:
    label3:
        printf("Enter the email ID to search: ");
        scanf(" %s", searchEmail);
        int flag2 = 0;
        for (int i = 0; i < addressBook->contactCount; i++) {
            if (strcmp(addressBook->contacts[i].email, searchEmail) == 0) {
                printf("\n====***Contact found====***\n");
                printf("Name  : %s\n", addressBook->contacts[i].name);
                printf("Phone : %s\n", addressBook->contacts[i].phone);
                printf("Email : %s\n", addressBook->contacts[i].email);
                flag2 = 1;
                break;
            }
        }
        if (flag2 == 0) {
            printf("Email Not Found\n");
            goto label3;
        }
        break;
        default:printf("Invalid Option.!!!");
        break;
    }
}

void editContact(AddressBook *addressBook) 
{
    int Choice;
    char choice12[100];
    while (1) {
    printf("1. Exit                    2. Continue\n");
    printf("Enter your choice: ");
    scanf(" %s", choice12);

    if (strcmp(choice12,"1") == 0) {
        return;
    } else if (strcmp(choice12,"2")== 0) {
        break; 
    } else {
        printf("Invalid Choice. Please try again: \n");
    }
}
    int searchOption;
    char searchKey[100];
    int foundIndexes[100];  
    int matchCount = 0;

    printf("\nEdit by:\n1. Name\n2. Phone Number\n3. Email Id\n");
    printf("Enter your choice: ");
    scanf("%d", &searchOption);

    switch (searchOption) {
        case 1:
            printf("Enter the name to edit: ");
            scanf(" %[^\n]s", searchKey);
            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strcmp(addressBook->contacts[i].name, searchKey) == 0) {
                    foundIndexes[matchCount++] = i;
                }
            }
            break;

        case 2:
            printf("Enter the phone number to edit: ");
            scanf(" %[^\n]s", searchKey);
            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strcmp(addressBook->contacts[i].phone, searchKey) == 0) {
                    foundIndexes[matchCount++] = i;
                  
                }
            }
            break;

        case 3:
            printf("Enter the email ID to edit: ");
            scanf(" %[^\n]s", searchKey);
            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strcmp(addressBook->contacts[i].email, searchKey) == 0) {
                    foundIndexes[matchCount++] = i;
                }
            }
            break;

        default:
            printf("Invalid option.\n");
            return;
    }

    if (matchCount == 0) {
        printf("Contact Not Found.\n");
        return;
    }

    int editIndex;
    if (matchCount == 1) {
        editIndex = foundIndexes[0];
    } else {
        printf("\n*Multiple contacts found with the given information*\n");
        for (int i = 0; i < matchCount; i++) {
        int no = foundIndexes[i];
        printf("\n%d. Name : %s\n   Phone: %s\n   Email: %s\n",i + 1,addressBook->contacts[no].name,addressBook->contacts[no].phone,
                   addressBook->contacts[no].email);
        }

        printf("\nEnter serial number to edit: ");
        scanf("%d", &Choice);
        if (Choice < 1 || Choice > matchCount) {
            printf("Invalid choice. Try again...\n");
            return;
        }
        editIndex = foundIndexes[Choice - 1];
    }

   
    printf("\nSelected Contact:\n");
    printf("1. Name  : %s\n", addressBook->contacts[editIndex].name);
    printf("2. Phone : %s\n", addressBook->contacts[editIndex].phone);
    printf("3. Email : %s\n", addressBook->contacts[editIndex].email);

   
    printf("\nWhat do you want to edit?\n1. Name\n2. Phone\n3. Email\nEnter your choice: ");
    int Choice1;
    scanf("%d", &Choice1);

    switch (Choice1) {
        case 1:
            printf("Enter new name: ");
            scanf(" %[^\n]", addressBook->contacts[editIndex].name);
            ValidName(addressBook, addressBook->contacts[editIndex].name);
            break;
        case 2:
        char phone[100];
            printf("Enter new phone: ");
            scanf(" %[^\n]", phone);
            ValidPhoneEdit(addressBook,phone,editIndex);
            break;
        case 3:
        char email[100];
            printf("Enter new email: ");
            scanf(" %[^\n]", email);
           ValidEmailEdit(addressBook, email,editIndex);
            break;
        default:
            printf("Invalid choice. Try again...\n");
            return;
    }

    printf("Contact updated successfully.\n");
}


void deleteContact(AddressBook *addressBook) 
{
    int choice;
    char choice12[100];
      while (1) {
    printf("1. Exit                    2. Continue\n");
    printf("Enter your choice: ");
    scanf(" %s", choice12);

    if (strcmp(choice12,"1") == 0) {
        return;
    } else if (strcmp(choice12,"2")== 0) {
        break; 
    } else {
        printf("Invalid Choice. Please try again: \n");
    }
}

    int deleteOption;
    char input[100];
    int indexes[100]; 
    int matchCount = 0;

    printf("\nDelete by:\n1. Name\n2. Phone Number\n3. Email ID\n");
    printf("Enter your choice: ");
    scanf("%d", &deleteOption);

    switch(deleteOption) {
        case 1:
            printf("Enter the name to delete: ");
            scanf(" %[^\n]s", input);
            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strcmp(addressBook->contacts[i].name, input) == 0) {
                    indexes[matchCount++] = i;
                }
            }
            break;

        case 2:
            printf("Enter the phone number to delete: ");
            scanf(" %[^\n]s", input);
            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strcmp(addressBook->contacts[i].phone, input) == 0) {
                    indexes[matchCount++] = i;
                }
            }
            break;

        case 3:
            printf("Enter the email ID to delete: ");
            scanf(" %[^\n]s", input);
            for (int i = 0; i < addressBook->contactCount; i++) {
                if (strcmp(addressBook->contacts[i].email, input) == 0) {
                    indexes[matchCount++] = i;
                }
            }
            break;

        default:
            printf("Invalid option.\n");
            return;
    }

    if (matchCount == 0) {
        printf("No contact found with the given data %s.\n",input);
        return;
    }

    if (matchCount == 1) {
        int idx = indexes[0];
        for (int j = idx; j < addressBook->contactCount - 1; j++) {
            addressBook->contacts[j] = addressBook->contacts[j + 1];
        }
        addressBook->contactCount--;
        printf("Contact deleted successfully.\n");
    } else {
        printf("\nMultiple contacts found:\n");
        for (int i = 0; i < matchCount; i++) {
            int idx = indexes[i];
            printf("\n%d. Name: %s\nPhone: %s\nEmail: %s\n", 
                   i + 1, 
                   addressBook->contacts[idx].name, 
                   addressBook->contacts[idx].phone, 
                   addressBook->contacts[idx].email);
        }

        int select;
        printf("\nEnter choice to delete: ");
        scanf("%d", &select);

        if (select < 1 || select > matchCount) {
            printf("Invalid choice. Try again.\n");
            return;
        }

        int delIndex = indexes[select - 1];
        for (int j = delIndex; j < addressBook->contactCount - 1; j++) {
            addressBook->contacts[j] = addressBook->contacts[j + 1];
        }
        addressBook->contactCount--;
        printf("Contact deleted successfully.\n");
    }
}

void exitProgram(){
    printf("**** Thank You Visit Again🤝 ****\n");
    exit(0);
}
void ValidName(AddressBook *addressBook,char *newName){
    int count=0;
for (int i = 0;  newName[i] != '\0'; i++) {
       if (!isalpha(newName[i]) && newName[i]!=' ') {
         count=1;
         break;
        }
    }
    if(count){
      printf("Enter Valid Name : ");
        scanf(" %[^\n]s",newName);
         ValidName(addressBook,newName);
          return;
    }
 strcpy(addressBook->contacts[addressBook->contactCount].name,newName);
}
void ValidPhone(AddressBook *addressBook, char *phone1) {
    int len = strlen(phone1);
    int isValid = 1;

    // Length check
    if (len != 10) {
        isValid = 0;
    } else {
        for (int i = 0; i < len; i++) {
            if (!isdigit(phone1[i])) {
                isValid = 0;
                break;
            }
        }
    }

    if (!isValid || phoneexist(addressBook, phone1)) {
        char phone11[20];
        if (!isValid)
            printf("Invalid phone number.\n");
        else
            printf("Phone number already exists.\n");

        printf("Enter a valid phone number: ");
        scanf(" %19s", phone11);
        ValidPhone(addressBook, phone11);  
    

        return;
    }
    strcpy(addressBook->contacts[addressBook->contactCount].phone, phone1);
}


void ValidEmail(AddressBook *addressBook, char *email1) {
    int atCount = 0;
    int invalid = 0;
    int length = strlen(email1);

 
    for (int i = 0; i < length; i++) {
        if (email1[i] == '@') {
            atCount++;
        } else if (!islower(email1[i]) && !isdigit(email1[i]) && email1[i] != '.' && !isspace(email1[i])) {
            invalid = 1;
        }
        if (isspace(email1[i])) {
            invalid = 1;
        }
    }

    if (length < 10 || atCount != 1 || strcmp(&email1[length - 10], "@gmail.com") != 0) {
        invalid = 1;
    }


    if (invalid) {
        char email2[100];
        printf("Invalid email. Enter a valid email (e.g. user@gmail.com): ");
        scanf(" %[^\n]s", email2);
        ValidEmail(addressBook, email2);
        return;
    }


    if (emailexist(addressBook, email1)) {
        char email2[100];
        printf("Email already exists. Enter a different email: ");
        scanf(" %[^\n]s", email2);
        ValidEmail(addressBook, email2);
        return;
    }

    
    strcpy(addressBook->contacts[addressBook->contactCount].email, email1);
}
 void savecontacts(AddressBook *addressBook, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < addressBook->contactCount; i++) {
        fprintf(fp, "%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }

    fclose(fp);
    printf("Contacts saved to file successfully.\n");
}

void loadContactsFromFile(AddressBook *addressBook, const char *filename) {
    FILE *fp = fopen(filename, "r"); 
    if (fp == NULL) {
        printf("No saved contacts found.\n");
        return;
    }
    addressBook->contactCount = 0;
    for (int i = 0; i <MAX_CONTACTS; i++) {
    if (fscanf(fp, " %[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email) == 3){
            addressBook->contactCount++;  
        } else {
            break;  
        }
    }
    fclose(fp);
}
int phoneexist(AddressBook *addressBook, const char *phone) {
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].phone, phone) == 0) {
            return 1; 
        }
    }
    return 0;
}

int emailexist(AddressBook *addressBook, const char *email) {
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (strcmp(addressBook->contacts[i].email, email) == 0) {
            return 1;  
        }
    }
    return 0; 
}


//edit function call for exist

int phoneexist1(AddressBook *addressBook, const char *phone, int skipIndex) {
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (i == skipIndex) continue;  
        if (strcmp(addressBook->contacts[i].phone, phone) == 0) {
            return 1;
        }
    }
    return 0;
}
int emailexist1(AddressBook *addressBook, const char *email, int skipIndex) {
    for (int i = 0; i < addressBook->contactCount; i++) {
        if (i == skipIndex) 
        continue;
        if (strcmp(addressBook->contacts[i].email, email) == 0) {
            return 1;
        }
    }
    return 0;
}

//edit function call for valid
void ValidPhoneEdit(AddressBook *addressBook, char *phone, int editIndex) {
    char input[20];

    while (1) {
        int len = strlen(phone);
        int isValid = 1;

        if (len != 10) {
            isValid = 0;
        } else {
            for (int i = 0; i < len; i++) {
                if (!isdigit(phone[i])) {
                    isValid = 0;
                    break;
                }
            }
        }

        if (isValid && !phoneexist1(addressBook, phone, editIndex)) {
            strcpy(addressBook->contacts[editIndex].phone, phone);
            return;
        }

        if (!isValid)
            printf("Invalid phone number. It must be exactly 10 digits.\n");
        else
            printf("Phone number already exists.\n");

        printf("Enter a valid phone number: ");
        scanf(" %19s", input);
        phone = input;
    }
}
void ValidEmailEdit(AddressBook *addressBook, char *email, int editIndex) {
    char input[100];
    strcpy(input, email);  

    while (1) {
        int atCount = 0, invalid = 0;
        int length = strlen(input);

        for (int i = 0; i < length; i++) {
            if (input[i] == '@') {
                atCount++;
            } else if (!islower(input[i]) && !isdigit(input[i]) && input[i] != '.') {
                invalid = 1;
            }
            if (isspace(input[i])) {
                invalid = 1;
            }
        }
        if (length < 10 || atCount != 1 || strcmp(&input[length - 10], "@gmail.com") != 0) {
            invalid = 1;
        }
        if (!invalid && !emailexist1(addressBook, input, editIndex)) {
            strcpy(addressBook->contacts[editIndex].email, input);
            return;
        }
        if (invalid) {
            printf("Invalid email format. Must end with @gmail.com and contain only lowercase letters/digits.\n");
        }
        if (emailexist1(addressBook, input, editIndex)==1) {
            printf("Email already exists.\n");
        }
        printf("Enter a valid email: ");
        scanf(" %[^\n]s", input); 
    }
}

