#ifndef CONTACTS_HELPERS_H_
#define CONTACTS_HELPERS_H_
#include "contact.h"

void contactManagerSystem(void);

//-----------Function for File Handling-----------
int readFile(char* filename, struct Contact* contacts);
void saveFile(struct Contact* contact, int size);

//-----------Function for Validation-----------
int checkValidDate(int year, int month, int day);
int getInt(void);
int getIntInRange(int min, int max);
char* getResult(char* r);
char* getDate(char* date);
void getTenDigitPhone(char phoneNum[]);

//-----------Functions for SubMenu-----------
void calculatePercentageByAge(const struct Contact* contact, int size);
void calculatePercentageByPrv(const struct Contact* contact, int size);

//-----------Functions for MainMenu-----------
void searchContacts(const struct Contact* contacts, int size);
void addContact(struct Contact* contacts, int size);
void updateContact(struct Contact* contacts, int size);
void deleteContact(struct Contact* contacts, int size);
void sortContacts(struct Contact* contacts, int size);

//-----------Print&&Display Functions-----------
int printMainMenu(void);
void printSubMenu(const struct Contact* contacts, int size);
void printSuccessMsg(const char* msg);
void displayContactHeader(const char* title);
void displayContactFooter(int count);
void displayContact(const struct Contact* contact);
void displayContacts(const struct Contact* contacts, int size);
int displayUpdateMenu(void);

//-----------------------------------------------
void clearKeyboard(void);
void pause(void);
int yes(void);
int findContactIndex(const struct Contact* contacts, int size, const char cellNum[]);

#endif CONTACTS_HELPERS_H_