#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "helpers.h"

#define MAXPATIENTS 100
#define YEAR 2021

void patientManagerSystem(void)
{
    struct Patient patient[MAXPATIENTS] = { 0 };
    int openfile = readFile("patient.csv", patient);
    int isDone = 0;
    int option = 0;
    if (openfile == 1) { //file is opened
        while (!isDone)
        {
            sortPatients(patient, MAXPATIENTS);
            option = displayMainMenu();
            switch (option) {
            case 1:
                displayPatients(patient, MAXPATIENTS);  //1. Display All patients
                pause();
                break;
            case 2:
                displaySubMenu(patient, MAXPATIENTS);  //2. Display Records
                pause();
                break;
            case 3:
                addPatients(patient, MAXPATIENTS);   //3. Add Patients
                pause();
                break;
            case 4:
                updatePatients(patient, MAXPATIENTS); // 4. Modify Patient
                pause();
                break;
            case 5:
                deletePatients(patient, MAXPATIENTS); // 5. Remove Patient
                pause();
                break;
            case 6:
                searchPatients(patient, MAXPATIENTS); // 6. Search Patient
                pause();
                break;
            case 0:
                printf("\nExit the program? (Y)es/(N)o: "); // 0. Exit
                if (yes() == 1) {
                    printf("\n");
                    printf("Would you like to save the updated data? (Y)es/(N)o: ");
                    if (yes() == 1) {
                        saveFile(patient, MAXPATIENTS); //Save data
                    }
                    isDone = 1;
                    printf("Would you like to save the record of result? (Y)es/(N)o: ");
                    if (yes() == 1) {
                        calculatePercentageByAge(patient, MAXPATIENTS, 2);
                        calculatePercentageByPrv(patient, MAXPATIENTS, 2);
                    }
                    printf("*** Saved updated Result ***\n");
                    printf("COVID-19 Patient Management System: terminated\n");
                }
                else {
                    printf("\n");
                    isDone = 0;
                }
            }

        }
    }
}

int displayMainMenu(void)
{
    int select = 0;   
    printf("-------------------------\n");
    printf("1. Display All Patients  \n");
    printf("2. Display Records        \n");
            //--> 1) Display percentage of Positive by age
            //--> 2) Display percentage of Positive by Province
    printf("3. Add patient           \n");
    printf("4. Modify patient        \n");
    printf("5. Remove patient        \n");
    printf("6. Search patient        \n");
    printf("0. Exit\n");
    printf("Select an option--> ");
    select = getIntInRange(0, 6);
    return select;
}

int readFile(char* filename, struct Patient* patients)
{
    char buffer[1024];
    int row = 0;
    int field_count = 0;
    FILE* fp = fopen(filename, "r"); // open file to read
    if (!fp) {
        printf("Can't open the file\n");
        return -1;
    }
    else { 
        printf("Welcome to COVID-19 Patient Management System.\n");
        int i = 0;
        while (fgets(buffer, 1024, fp) != NULL) {
            field_count = 0;
            row++;
            if (row == 1) {
                continue;
            }
            //get Name
            char* temp = strtok(buffer, ",");
            strcpy(patients[i].name.firstName, temp);
            temp = strtok(NULL, ",");
            strcpy(patients[i].name.lastName, temp);
            //get BirthDate
            temp = strtok(NULL, ".");
            patients[i].birthdate.year = atoi(temp);
            temp = strtok(NULL, ".");
            patients[i].birthdate.month = atoi(temp);
            temp = strtok(NULL, ",");
            patients[i].birthdate.day = atoi(temp);
            //get TestDate
            temp = strtok(NULL, "-");
            patients[i].result.year = atoi(temp);
            temp = strtok(NULL, "-");
            patients[i].result.month = atoi(temp);
            temp = strtok(NULL, ",");
            patients[i].result.day = atoi(temp);
            //get Result
            temp = strtok(NULL, ",");
            strcpy(patients[i].result.results, temp);
            //get Address
            temp = strtok(NULL, ",");
            strcpy(patients[i].address.street, temp);
            temp = strtok(NULL, ",");
            strcpy(patients[i].address.city, temp);
            temp = strtok(NULL, ",");
            strcpy(patients[i].address.province, temp);
            temp = strtok(NULL, ",");
            strcpy(patients[i].address.postalCode, temp);
            //getNumbers
            temp = strtok(NULL, "-");
            strcpy(patients[i].numbers.cell, temp);
            temp = strtok(NULL, "-");
            strcat(patients[i].numbers.cell, temp);
            temp = strtok(NULL, ",");
            strcat(patients[i].numbers.cell, temp);
            temp = strtok(NULL, ",");
            strcpy(patients[i].numbers.secondCell, temp);
            temp = strtok(NULL, ",");
            strcpy(patients[i].numbers.email, temp);
            i++;
        }
    }
    fclose(fp);
    return 1;
}

void saveFile(struct Patient* patients, int size)
{
    FILE* f;
    f = fopen("C:\\Users\\JJ\\source\\repos\\covid19_project\\updated_records.csv", "w+");
    int i = 0;
    fprintf(f, "first_name, last_name, Birth_date, test_date, result, address, city, province, postal, phone1, phone2, email\n");
    if (f) {
        while (i != MAXPATIENTS) {
            if (strlen(patients[i].numbers.cell) != 0) {
                fprintf(f, "%s,%s,%d.%d.%d,%d-%d-%d,", 
                    &patients[i].name.firstName, &patients[i].name.lastName,
                    patients[i].birthdate.year, patients[i].birthdate.month, patients[i].birthdate.day,
                    patients[i].result.year, patients[i].result.month, patients[i].result.day);
                fprintf(f, "%s,%s,%s,%s,%s,%s,%s,%s", patients[i].result.results,
                    patients[i].address.street, patients[i].address.city,
                    patients[i].address.province, patients[i].address.postalCode,
                    patients[i].numbers.cell, patients[i].numbers.secondCell,
                    patients[i].numbers.email);
            }
            i++;
        }
        fclose(f);
    }
    else {
        printf("fail to open file\n");
    }
}

void saveRecordFile(char* category, char groupName[][6], double group[]) {
    FILE* f;
    int i = 0;
    if (strcmp(category, "Age") == 0) {
        f = fopen("C:\\Users\\JJ\\source\\repos\\covid19_project\\covid19_record_age.csv", "w+");
    }
    else {
        //category == "Province"
        f = fopen("C:\\Users\\JJ\\source\\repos\\covid19_project\\covid19_record_prov.csv", "w+");
    }
    fprintf(f, "Country,%s,Cases\n", category); //category == age or Province
    if (f) {
        while (i != 8) {
            fprintf(f, "Canada,%s,%.2f\n", groupName[i], group[i]);
            i++;
        }
        fclose(f);
    }
}

void calculatePercentageByPrv(const struct Patient* patients, int size, int category)
{ //category == 1 == print Result
  //category == 2 == save Result
    char province[8][6] = { "ON", "AB", "BC", "NB", "SK", "NS", "QC", "Other"};
    int total = 0; //total patient with Positive result
    int isGood = 0;
    double on = 0.0; double ab = 0.0; double bc = 0.0; double nb = 0.0;
    double qc = 0.0; double ns = 0.0; double sk = 0.0; double etc = 0.0;
    for (int i = 0; i < size; i++) {
        if (patients[i].birthdate.year != 0 && strcmp(patients[i].result.results, "Positive") == 0) { //validation --> patients[i] is not null && result == Positive 
            isGood = 0;
            for (int j = 0; j <= 7; j++) {
                if (j == 7) { //if patients[i].address.province is not in province array
                    if (strcmp(patients[i].address.province, province[j]) != 0 && isGood == 0) {
                        etc++;
                    }
                }
                else {
                    if (strcmp(patients[i].address.province, province[j]) == 0) {
                        if (j == 0) {
                            on++;
                            isGood = 1;
                        }
                        else if (j == 1) {
                            ab++;
                            isGood = 1;
                        }
                        else if (j == 2) {
                            bc++;
                            isGood = 1;
                        }
                        else if (j == 3) {
                            nb++;
                            isGood = 1;
                        }
                        else if (j == 4) {
                            sk++;
                            isGood = 1;
                        }
                        else if (j == 5) {
                            ns++;
                            isGood = 1;
                        }
                        else if (j == 6) {
                            qc++;
                            isGood = 1;
                        }
                    }
                }
            }
            total++;
        }
    }
    double groupArr[8] = { on, ab, bc, nb, sk, ns, qc, etc };
    
    if (category == 1) { 
        printPercentage(2, province, groupArr, total);
    }
    else { 
        saveRecordFile("Province", province, groupArr);
    }
}

void calculatePercentageByAge(const struct Patient* patients, int size, int category)
{
   //category == 1 == print Result
   //category == 2 == save Result
    int age = 0;
    int total = 0; //total patient with Positive result
    double g1 = 0.0; double g2 = 0.0; double g3 = 0.0; double g4 = 0.0;
    double g5 = 0.0; double g6 = 0.0; double g7 = 0.0; double g8 = 0.0;
    char ageGroup[8][6] = { "~19", "20-30", "30-40", "40-50","50-60","60-70","70-80", "80~" };

    for (int i = 0; i < size; i++) {
        if (patients[i].birthdate.year != 0 && strcmp(patients[i].result.results, "Positive") == 0) {
            age = YEAR - patients[i].birthdate.year;
            if (age <= 19) {
                g1++;
            }
            else if (age >= 20 && age <= 30) {
                g2++;
            }
            else if (age >= 31 && age <= 40) {
                g3++;
            }
            else if (age >= 41 && age <= 50) {
                g4++;
            }
            else if (age >= 51 && age <= 60) {
                g5++;
            }
            else if (age>= 61 && age<= 70) {
                g6++;
            }
            else if (age >= 71 && age <= 80) {
                g7++;
            }
            else if (age >= 81) {
                g8++;
            }
            total++;
        }
    }
    double groupArr[8] = { g1, g2, g3, g4, g5, g6, g7, g8 };
    if (category == 1) {
        printPercentage(1, ageGroup, groupArr, total);
    }
    else { 
        saveRecordFile("Age", ageGroup, groupArr);
    }
}

void printPercentage(int category, char group[][6], double* resultArr, int total) 
{   //category 1==Age , category 2==Province
    if (category == 1){
        printHeader("Results by Age");
    }
    else {
        printHeader("Results by Province");
    }
    for (int i = 0; i < 8; i++) {
        double result = (resultArr[i] / total) * 100;
        printf("%s : %.2f%%\n", group[i], result);
    }
    printFooter(total);
}

void displaySubMenu(const struct Patient* patients, int size)
{
    printHeader("2. Display Records");
    printf("Choose Option \n");
    printf("1. Display percentage of Positive results by Age\n");
    printf("2. Display percentage of Positive results by Province\n");
    printf("Select an option--> ");
    int selection = getIntInRange(1, 2);
    if (selection == 1) { // results by Age
        calculatePercentageByAge(patients, MAXPATIENTS, 1);
    }
    else if (selection == 2){ //results by Province
        calculatePercentageByPrv(patients, MAXPATIENTS, 1);
    }
}

char* getResult(char* r) 
{
    int isDone = 0;
    char NL = 0;
    char *result = { 0 };
    while (!isDone) {
        scanf("%c%c", r, &NL);
        if (NL == '\n' ) {
            if (*r == 'P' || *r == 'p') {
                //strcpy(result, "Positive");
                result = "Positive";
                isDone = 1;
            }
            else if (*r == 'N' || *r == 'n') {
                result="Negative";
                isDone = 1;
            }
        }
        else {
            clearKeyboard();
            printf("*ERROR* Please enter P(positive) or N(negative): ");
            isDone = 0;
        }
    }
    return result;
}

char* getDate(char* date) 
{
    int needInput = 0;
    int isNotDigit = 0;
    while (!needInput)
    {
        isNotDigit = 0;
        scanf("%s", date);
        if (strlen(date) == 10){
            for (int i = 0; i < 10; i++){
                if (i == 4 || i == 7) { 
                    if (date[i] != '.') { // if input didn't follow the form -- error
                        isNotDigit = 1;
                    }
                }
                else if (*(date + i) < '0' || *(date + i) > '9') { //if date is not a digit
                    isNotDigit = 1;
                }
            }
            if (isNotDigit == 1) {
                printf("*ERROR* Enter date again(ex: YYYY.MM.DD): ");
                needInput = 0;
            }
            else {
                needInput = 1;
            }
        }
        else { //if date is longer than 10 digits
            printf("*ERROR* Enter date again(ex: YYYY.MM.DD): ");
        }
    }
    return date;
}

int checkValidDate(int year, int month, int day) 
{
    if (year > YEAR || month > 12 || day <= 0 || day > 31) {
        return -1;
    }
    return 0;
}

void getPhoneNumber(char phoneNum[]) {
    int needInput = 0;
    int isNotDigit = 0;
    while (!needInput)
    {
        isNotDigit = 0;
        scanf("%s", phoneNum);
        if (strlen(phoneNum) == 10){
            for (int i = 0; i < 10; i++){
                if (*(phoneNum + i) < '0' || *(phoneNum + i) > '9') { //if phoneNum is not a digit
                    isNotDigit = 1; // error
                }
            }
            if (isNotDigit == 1) {
                printf("*ERROR* Enter a 10-digit phone number: ");
                needInput = 0; 
            }
            else {
                needInput = 1;
            }
        }
        else {
            printf("*ERROR* Enter a 10-digit phone number: ");
        }
    }
}

int findIndex(const struct Patient* patients, int size, const char cellNum[])
{
    int indexnum = 0;
    for (int i = 0; i < size; i++) {
        if (patients[i].numbers.cell > 0) {
            if ((strcmp(cellNum, patients[i].numbers.cell) == 0)) {
                indexnum = i;
                return indexnum;
            }
        }
        else{
            indexnum = i;
            return indexnum;
        }
    }
    return -1;
}

void printHeader(const char* title) {
    printf("\n");
    printf("**********************************************************************\n");
    printf("                      %s                                      \n", title);
    printf("**********************************************************************\n");
}

void printFooter(int count) {
    printf("---------------------------------------------------------------\n");
    printf("Total Patients : %d\n\n", count);
}

void printSuccessMsg(const char* msg) {
    printf("patient's %s is successfully updated!\n", msg);
}

void displayPatient(const struct Patient* patients) {
    printf("\n");
    printf("     FULL NAME : %s %s\n", patients->name.firstName, patients->name.lastName);
    printf("     BIRTH DATE: %d-%d-%d \n", patients->birthdate.year, patients->birthdate.month, patients->birthdate.day);
    printf("     ADDRESS   : %s, %s, %s\n", patients->address.street, patients->address.city, patients->address.province, patients->address.postalCode);
    printf("     PHONE     : ");
    for (int i = 0; i < 12; i++) {
        if (i == 3 || i == 6) {
            printf("-%c", patients->numbers.cell[i]);
        }
        else {
            printf("%c", patients->numbers.cell[i]);
        }
    }
    printf("\n     TEST DATE : %d-%d-%d\n", patients->result.year, patients->result.month, patients->result.day);
    printf("---> RESULT    : %s\n", patients->result.results);
}

void displayPatients(const struct Patient* patients, int size) {
    int total_patients = 0;
    printHeader("1. Display All Patients ");
    for (int i = 0; i < size; i++){
        if (strlen(patients[i].numbers.cell) >0){
            printf("%d | ", total_patients +1);
            displayPatient(&patients[i]);
            total_patients++;
        }
    }
    printFooter(total_patients);
}

void addPatients(struct Patient* patients, int size) {
    int emptyIndex = 0;
    char Input_num[11] = { 0 };
    printHeader("3. Add patient");
    emptyIndex = findIndex(patients, size, Input_num);
    if (emptyIndex == -1){
        printf("!!! ERROR: The patient list is full !!!\n\n");
    }
    else{
        getPatient(&patients[emptyIndex]);
        printf("--- New patient added! ---\n\n");
    }
}

int displayUpdateMenu(void) {
    int selection = 0;
    printf("-----------------------------\n");
    printf("Please choose menu for update\n");
    printf("1. Name\n");
    printf("2. Birth Date\n");
    printf("3. Address\n");
    printf("4. Phone number && Email\n");
    printf("5. Covid Result and Test Date\n");
    printf("0. Go back to menu\n");
    printf("Selection--> ");
    scanf("%d", &selection);
    printf("\n");
    return selection;
}

void updatePatients(struct Patient* patients, int size) {
    char CellNum[13] = { 0 };
    int index = 0;
    int isDone = 0;
    int selection = 0;

    printHeader("4. Modify patient");
    printf("Enter the cell number for the patients: ");
    getPhoneNumber(CellNum);
    index = findIndex(patients, size, CellNum);
    if (index >= 0) {
        printf("\Patient found:\n");
        displayPatient(&patients[index]);
        printf("\n");
        while (!isDone)
        {
            selection = displayUpdateMenu();
            switch (selection) {
            case 1:
                clearKeyboard();
                patients[index].name.firstName[0] = '\0';
                patients[index].name.lastName[0] = '\0';
                getName(&patients[index].name);
                printSuccessMsg("name");
                pause();
                break;
            case 2:
                clearKeyboard();
                getBirth(&patients[index].birthdate);
                printSuccessMsg("Birth Date");
                pause();
                break;
            case 3:
                clearKeyboard();
                getAddress(&patients[index].address);
                printSuccessMsg("Address");
                pause();
                break;
            case 4:
                clearKeyboard();
                getNumbers(&patients[index].numbers);
                printSuccessMsg("Numbers & Email");
                pause();
                break;
            case 5:
                clearKeyboard();
                getResults(&patients[index].result);
                printSuccessMsg("Result");
                pause();
                break;
            case 0:
                isDone = 1;
            }
        }
    }
    else{
        printf("!!! Patient NOT FOUND !!!\n\n");
   
    }
}

void deletePatients(struct Patient* patients, int size) {
    char CellNum[13] = { 0 };
    int index = 0;
    printHeader("5. Remove patient ");
    printf("Enter the cell number for the patient: ");
    getPhoneNumber(CellNum);
    clearKeyboard();
    index = findIndex(patients, size, CellNum); // finding index of cellnumber in array 
    if (index == 0 || index > 0)
    {
        printf("\n");
        printf("Patient found:\n");
        displayPatient(&patients[index]);
        printf("CONFIRM: Delete this patient? (y or n): ");
        if (yes() == 1){
            *(patients + index)->name.firstName = '\0';
            *(patients + index)->numbers.cell = '\0';
            *(patients + index)->numbers.secondCell = '\0';
            printf("--- Patient deleted! ---\n\n");
        }
        else{
            printf("\n");
        }
    }
    else{
        printf("!!! Patient NOT FOUND !!!\n\n");
    }
}

void searchPatients(const struct Patient* patients, int size) {
    int Indexnum = 0;
    char cellNumber[13] = { 0 };
    printHeader("6. Search patients ");
    printf("Enter the cell number of patient: ");
    scanf("%12[^\n]%*c", cellNumber);
    Indexnum = findIndex(patients, size, cellNumber);
    if (Indexnum == 0 || Indexnum > 0) {
        printf("\n");
        displayPatient(&patients[Indexnum]);
    }
    else {
        printf("!!! Patient NOT FOUND !!!\n\n");
    }
}

void sortPatients(struct Patient* patients, int size) {
    for (int i = 0;i < size;i++) {
        if (strlen(patients[i].numbers.cell) == 0 && strlen(patients[i].name.firstName) != 0) {
            //if the patients information is deleted
            patients[size - 1] = patients[i];
            patients[i] = patients[i + 1];
            *(patients + i + 1)->numbers.cell = '\0';
        }
    }
}

void clearKeyboard(void)
{
    while (getchar() != '\n');
}

void pause(void)
{
    printf("Press Enter to Continue");
    clearKeyboard();
    printf("\n");
}

int getInt(void)
{
    int isDone = 0;
    int selection = 0;
    char NL = '\0';
    while (!isDone) {
        scanf("%d%c", &selection, &NL);
        if (NL != '\n') { // if %c is not a new line
            clearKeyboard();
            printf("!!! INVALID NUMBER !!! Please enter an integer: ");
        }
        else {
            isDone = 1;
        }
    }
    return selection;
}

int getIntInRange(int min, int max)
{
    int selection = 0;
    int isDone = 0;
    while (!isDone) {
        selection = getInt();
        if (selection < min || selection > max) {
            printf("!!! OUT OF RANGE !!! Enter a number between %d and %d: ", min, max);
        }
        else {
            isDone = 1;
        }
    }
    return selection;
}

int yes(void)
{
    int yesno = 0;
    char NL = 0;
    char answer = 0;
    int isDone = 0;
    while (!isDone)
    {
        scanf("%c%c", &answer, &NL);
        if (NL != '\n') { // if %c is not a new line
            clearKeyboard();
            printf("!!! INVALID ENTRY !!! Only (Y)es or (N)o are acceptable: ");
        }
        else {
            if (answer == 'y' || answer == 'Y') {
                yesno = 1;
                isDone = 1;
            }
            else if (answer == 'n' || answer == 'N') {
                yesno = 0;
                isDone = 1;
            }
        }
    }
    return yesno;
}

