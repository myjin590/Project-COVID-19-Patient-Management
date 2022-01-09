#ifndef CONTACTS_HELPERS_H_
#define CONTACTS_HELPERS_H_
#include "contact.h"

void patientManagerSystem(void);

//-----------Function for File Handling-----------
int readFile(char* filename, struct Contact* contacts);
void saveFile(struct Contact* contact, int size);
void saveRecordFile(char* category, char groupName[][6], double* group);

//-----------Function for Validation-----------
int checkValidDate(int year, int month, int day);
int getInt(void);
int getIntInRange(int min, int max);
char* getResult(char* r);
char* getDate(char* date);
void getTenDigitPhone(char phoneNum[]);

//-----------Functions for SubMenu-----------
void calculatePercentageByAge(const struct Contact* contact, int size, int category);
void calculatePercentageByPrv(const struct Contact* contact, int size, int category);

//-----------Functions for MainMenu-----------
void searchPatients(const struct Contact* contacts, int size);
void addPatients(struct Contact* contacts, int size);
void updatePatients(struct Contact* contacts, int size);
void deletePatients(struct Contact* contacts, int size);
void sortPatients(struct Contact* contacts, int size);

//-----------Print&&Display Functions-----------
int displayMainMenu(void);
void displaySubMenu(const struct Contact* contacts, int size);
void displayPatient(const struct Contact* contact);
void displayPatients(const struct Contact* contacts, int size);
int displayUpdateMenu(void);
void printSuccessMsg(const char* msg);
void printHeader(const char* title);
void printFooter(int count);
void printPercentage(int category, char group[][6], double* resultArr, int total);

//-----------------------------------------------
void clearKeyboard(void);
void pause(void);
int yes(void);
int findIndex(const struct Contact* contacts, int size, const char cellNum[]);

#endif