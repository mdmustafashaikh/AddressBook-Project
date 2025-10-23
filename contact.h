#ifndef CONTACT_H
#define CONTACT_H

#define MAX_CONTACTS 100

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>

typedef struct {
    char name[50];
    char phone[20];
    char email[50];
} Contact;


typedef struct {
    Contact contacts[100];
    int contactCount;
} AddressBook;

void createContact(AddressBook *addressBook);
void searchContact(AddressBook *addressBook);
void editContact(AddressBook *addressBook);
void deleteContact(AddressBook *addressBook);
void listContacts(AddressBook *addressBook);
void initialize(AddressBook *addressBook);
void savecontacts(AddressBook *addressbook, const char *filename);
void loadContactsFromFile(AddressBook *addressBook, const char *filename);
void exitProgram();

//For Validation Name phone NUmber Email
void ValidName(AddressBook *addressBook,char *newName);
void ValidPhone(AddressBook *addressBook,char *phone);
void ValidEmail(AddressBook *addressBook,char *email1);



int phoneexist(AddressBook *addressBook, const char *phone);
int emailexist(AddressBook *addressBook, const char *email);
void check(char *choice1);


//edit function call
int phoneexist1(AddressBook *addressBook, const char *phone, int skipIndex);
int emailexist1(AddressBook *addressBook, const char *email, int skipIndex);
void ValidPhoneEdit(AddressBook *addressBook, char *phone, int editIndex);
void ValidEmailEdit(AddressBook *addressBook, char *email, int editIndex);
#endif
