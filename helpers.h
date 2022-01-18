#ifndef HELPERS_H
#define HELPERS_H
#include "patient.h"

void patientManagerSystem(void);

//-----------Function for File Handling-----------
int readFile(char* filename, struct Patient* patients);
void saveFile(struct Patient* patients, int size);
void saveRecordFile(char* category, char groupName[][6], double* group);

//-----------Function for Validation-----------
int checkValidDate(int year, int month, int day);
int getInt(void);
int getIntInRange(int min, int max);
char* getResult(char* r);
char* getDate(char* date);
void getPhoneNumber(char phoneNum[]);

//-----------Functions for SubMenu-----------
void calculatePercentageByAge(const struct Patient* patients, int size, int category);
void calculatePercentageByPrv(const struct Patient* patients, int size, int category);

//-----------Functions for MainMenu-----------
void searchPatients(const struct Patient* patients, int size);
void addPatients(struct Patient* patients, int size);
void updatePatients(struct Patient* patients, int size);
void deletePatients(struct Patient* patients, int size);
void sortPatients(struct Patient* patients, int size);

//-----------Print&&Display Functions-----------
int displayMainMenu(void);
void displaySubMenu(const struct Patient* patients, int size);
void displayPatient(const struct Patient* patients);
void displayPatients(const struct Patient* patients, int size);
int displayUpdateMenu(void);
void printSuccessMsg(const char* msg);
void printHeader(const char* title);
void printFooter(int count);
void printPercentage(int category, char group[][6], double* resultArr, int total);

//-----------------------------------------------
void clearKeyboard(void);
void pause(void);
int yes(void);
int findIndex(const struct Patient* patients, int size, const char cellNum[]);

#endif