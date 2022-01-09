#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "helpers.h"

#define MAXCONTACTS 50
#define YEAR 2021

void clearKeyboard(void) 
{
    while (getchar() != '\n');
}

void pause(void) 
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
    printf("\n");
}

int getInt(void) 
{
    int isDone = 0;
    int selection = 0;
    char NL = '\0';
    while (!isDone){
        scanf("%d%c", &selection, &NL);
        if (NL != '\n'){ // if %c is not a new line
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
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
    while (!isDone){
        selection = getInt();
        if (selection < min || selection > max){
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
        }
        else{
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
        if (NL != '\n'){ // if %c is not a new line
            clearKeyboard();
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        }
        else{
            if (answer == 'y' || answer == 'Y'){
                yesno = 1;
                isDone = 1;
            }
            else if (answer == 'n' || answer == 'N'){
                yesno = 0;
                isDone = 1;
            }
        }
    }
    return yesno;
}

int displayMainMenu(void)
{
    int select = 0;   
    printf("-------------------------\n");
    printf("1. Display All patients  \n");
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

int readFile(char* filename, struct Contact* contacts)
{
    char buffer[1024];
    int row = 0;
    int field_count = 0;
    FILE* fp = fopen("covid19_contact.csv", "r"); // open file to read
    if (!fp) {
        printf("Can't open the file\n");
        return -1;
    }
    else { 
        printf("Welcome to Covid Patient Management System.\n");
        int i = 0;
        while (fgets(buffer, 1024, fp) != NULL) {
            field_count = 0;
            row++;
            if (row == 1) {
                continue;
            }
            //get Name
            char* temp = strtok(buffer, ",");
            strcpy(contacts[i].name.firstName, temp);
            temp = strtok(NULL, ",");
            strcpy(contacts[i].name.lastName, temp);
            //get BirthDate
            temp = strtok(NULL, ".");
            contacts[i].birthdate.year = atoi(temp);
            temp = strtok(NULL, ".");
            contacts[i].birthdate.month = atoi(temp);
            temp = strtok(NULL, ",");
            contacts[i].birthdate.day = atoi(temp);
            //get TestDate
            temp = strtok(NULL, "-");
            contacts[i].result.year = atoi(temp);
            temp = strtok(NULL, "-");
            contacts[i].result.month = atoi(temp);
            temp = strtok(NULL, ",");
            contacts[i].result.day = atoi(temp);
            //get Result
            temp = strtok(NULL, ",");
            strcpy(contacts[i].result.results, temp);
            //get Address
            temp = strtok(NULL, ",");
            strcpy(contacts[i].address.street, temp);
            temp = strtok(NULL, ",");
            strcpy(contacts[i].address.city, temp);
            temp = strtok(NULL, ",");
            strcpy(contacts[i].address.province, temp);
            temp = strtok(NULL, ",");
            strcpy(contacts[i].address.postalCode, temp);
            //getNumbers
            temp = strtok(NULL, "-");
            strcpy(contacts[i].numbers.cell, temp);
            temp = strtok(NULL, "-");
            strcat(contacts[i].numbers.cell, temp);
            temp = strtok(NULL, ",");
            strcat(contacts[i].numbers.cell, temp);
            temp = strtok(NULL, ",");
            strcpy(contacts[i].numbers.secondCell, temp);
            temp = strtok(NULL, ",");
            strcpy(contacts[i].numbers.email, temp);
            i++;
        }
    }
    fclose(fp);
    return 1;
}

void patientManagerSystem(void)
{
    struct Contact contact[MAXCONTACTS] = {0};
    int openfile = readFile("covid19_contact.csv", contact);
    int isDone = 0;
    int option = 0;
    if (openfile == 1) { //file is opened
        while (!isDone)
        {
            option = displayMainMenu();
            switch (option) {
            case 1:
                displayPatients(contact, MAXCONTACTS);  //1. Display All patients
                pause();
                break;
            case 2:
                displaySubMenu(contact, MAXCONTACTS);  //2. Display Records
                pause();
                break;
            case 3:
                addPatients(contact, MAXCONTACTS);   //3. Add Patients
                pause();
                break;
            case 4:
                updatePatients(contact, MAXCONTACTS); // 4. Modify Patient
                pause();
                break;
            case 5:
                deletePatients(contact, MAXCONTACTS); // 5. Remove Patient
                pause();
                break;
            case 6:
                searchPatients(contact, MAXCONTACTS); // 4. Search Patient
                pause();
                break;
            case 0:
                printf("\nExit the program? (Y)es/(N)o: "); // 0. Exit
                if (yes() == 1){
                    printf("\n");
                    printf("Would you like to save the updated data? (Y)es/(N)o: ");
                    if (yes() == 1) {
                        saveFile(contact, MAXCONTACTS); //Save data
                    }
                    isDone = 1;
                    printf("Would you like to save the record of result? (Y)es/(N)o: ");
                    if (yes() == 1) {
                        calculatePercentageByAge(contact, MAXCONTACTS, 2);
                        calculatePercentageByPrv(contact, MAXCONTACTS, 2);
                    }
                    printf("Covid-Patient Management System: terminated\n");
                }
                else{
                    printf("\n");
                    isDone = 0;
                }
            }
           
        }
    }
}

void saveFile(struct Contact* contact, int size)
{
    FILE* f;
    f = fopen("C:\\Users\\JJ\\source\\repos\\covid19_project\\covid19_updated.csv", "w+");
    int i = 0;
    fprintf(f, "first_name, last_name, Birth_date, test_date, result, address, city, province, postal, phone1, phone2, email\n");
    if (f) {
        while (i != MAXCONTACTS) {
            if (strlen(contact[i].numbers.cell) != 0) {
                fprintf(f, "%s,%s,%d.%d.%d,%d-%d-%d,", 
                    &contact[i].name.firstName, &contact[i].name.lastName, 
                    contact[i].birthdate.year, contact[i].birthdate.month, contact[i].birthdate.day,
                    contact[i].result.year, contact[i].result.month, contact[i].result.day);
                fprintf(f, "%s,%s,%s,%s,%s,%s,%s,%s", contact[i].result.results, 
                    contact[i].address.street, contact[i].address.city, 
                    contact[i].address.province, contact[i].address.postalCode, 
                    contact[i].numbers.cell, contact[i].numbers.secondCell, 
                    contact[i].numbers.email);
            }
            i++;
        }
        fclose(f);
    }
    else {
        printf("fail to open file\n");
    }


}

void calculatePercentageByPrv(const struct Contact* contact, int size, int category) 
{
    char province[8][6] = { "ON", "AB", "BC", "NB", "SK", "NS", "QC", "Other"};
    int total = 0; //total patient with Positive result
    double on = 0.0; double ab = 0.0; double bc = 0.0; double nb = 0.0;
    double qc = 0.0; double ns = 0.0; double sk = 0.0; double etc = 0.0;
    for (int i = 0; i < size; i++) {
        if (contact[i].birthdate.year != 0 && strcmp(contact[i].result.results, "Positive") == 0) { //validation --> contact[i] is not null && result == Positive 
            for (int j = 0; j <= 7; j++) {
                if (strcmp(contact[i].address.province, province[j]) == 0) {
                    if (j == 0) {
                        on++;
                    }
                    else if (j == 1) {
                        ab++;
                    }
                    else if (j == 2) {
                        bc++;
                    }
                    else if (j == 3) {
                        nb++;
                    }
                    else if (j == 4) {
                        sk++;
                    }
                    else if (j == 5) {
                        ns++;
                    }
                    else if (j == 6) {
                        qc++;
                    }
                    else {
                        etc++;
                    }
                    total++;
                }
            }
        }
    }
    double groupArr[8] = { on, ab, bc, nb, sk, ns, qc, etc };
    
    if (category == 1) {//save the result
        printPercentage(1, province, groupArr, total);
    }
    else { //print the result
        saveRecordFile("Province", province, groupArr);
    }

}

void calculatePercentageByAge(const struct Contact* contact, int size, int category) 
{
    int age = 0;
    int total = 0; //total patient with Positive result
    double g1 = 0.0; double g2 = 0.0; double g3 = 0.0; double g4 = 0.0;
    double g5 = 0.0; double g6 = 0.0; double g7 = 0.0; double g8 = 0.0;
    char ageGroup[8][6] = { "~19", "20-30", "30-40", "40-50","50-60","60-70","70-80", "80~" };

    for (int i = 0; i < size; i++) {
        if (contact[i].birthdate.year != 0 && strcmp(contact[i].result.results, "Positive") == 0) {
            age = YEAR - contact[i].birthdate.year;
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
        //save the result
        printPercentage(1, ageGroup, groupArr, total);
    }
    else { 
        //print the result
        saveRecordFile("Age", ageGroup, groupArr);
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
        f = fopen("C:\\Users\\JJ\\source\\repos\\covid19_project\\covid19_record.csv", "w+");
    }
    
    fprintf(f, "Country,%s,Cases\n", category); //category == age or Province
    if (f) {
        while (i != 8) {
            fprintf(f, "Canada,%s,%.2f\n", groupName[i], group[i]);
            i++;
        }
        fclose(f);
        printf("***Saved updated Result in csv file***\n");
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
        double result = resultArr[i] / total * 100;
        printf("%s : %.2f%%\n", group[i], result);
    }
    printFooter(total);
}

void displaySubMenu(const struct Contact* contact, int size)
{
    printHeader("2. Display Records");
    printf("Choose Option \n");
    printf("1. Display percentage of Positive results by Age\n");
    printf("2. Display percentage of Positive results by Province\n");
    printf("Select an option--> ");
    int selection = getIntInRange(1, 2);
    if (selection == 1) { // results by Age
        calculatePercentageByAge(contact, MAXCONTACTS, 1);
    }
    else if (selection == 2){ //results by Province
        calculatePercentageByPrv(contact, MAXCONTACTS, 1);
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
            printf("Please enter P(positive) or N(negative): ");
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
                printf("Enter date again(ex: YYYY.MM.DD): ");
                needInput = 0;
            }
            else {
                needInput = 1;
            }
        }
        else { //if date is longer than 10 digits
            printf("Enter date again(ex: YYYY.MM.DD): ");
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

void getTenDigitPhone(char phoneNum[]) {
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
                printf("Enter a 10-digit phone number: ");
                needInput = 0; 
            }
            else {
                needInput = 1;
            }
        }
        else {
            printf("Enter a 10-digit phone number: ");
        }
    }
}

int findIndex(const struct Contact* contacts, int size, const char cellNum[]) 
{
    int indexnum = 0;
    for (int i = 0; i < size; i++) {
        if (contacts[i].numbers.cell > 0) {
            if ((strcmp(cellNum, contacts[i].numbers.cell) == 0)) {
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
    printf("+-----------------------------------------------------------------------------+\n");
    printf("                               %s                                      \n", title);
    printf("+-----------------------------------------------------------------------------+\n");
}

void printFooter(int count) {
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total Patients : %d\n\n", count);
}

void printSuccessMsg(const char* msg) {
    printf("patient's %s is successfully updated!\n", msg);
}

void displayPatient(const struct Contact* contact) {
    printf("\n");
    printf("FULL NAME : %s %s\n", contact->name.firstName, contact->name.lastName);
    printf("     BIRTH DATE: %d-%d-%d \n", contact->birthdate.year, contact->birthdate.month, contact->birthdate.day);
    printf("     ADDRESS   : %s, %s, %s\n", contact->address.street, contact->address.city, contact->address.province, contact->address.postalCode);
    printf("     PHONE     : ");
    for (int i = 0; i < 12; i++) {
        if (i == 3 || i == 6) {
            printf("-%c", contact->numbers.cell[i]);
        }
        else {
            printf("%c", contact->numbers.cell[i]);
        }
    }
    printf("\n     TEST DATE : %d-%d-%d\n", contact->result.year, contact->result.month, contact->result.day);
    printf("---> RESULT    : %s\n", contact->result.results);
}

void displayPatients(const struct Contact* contacts, int size) {
    int total_contact = 0;
    printHeader("1. Display All patients ");
    for (int i = 0; i < size; i++){
        if (strlen(contacts[i].numbers.cell) > 0){
            printf("%d | ", total_contact+1);
            displayPatient(&contacts[i]);
            total_contact++;
        }
    }
    printFooter(total_contact);
}

void searchPatients(const struct Contact* contacts, int size) {
    int Indexnum = 0;
    char cellNumber[13] = { 0 };
    printf("Enter the cell number for the contact: ");
    scanf("%12[^\n]%*c", cellNumber);
    Indexnum = findIndex(contacts, size, cellNumber);
    if (Indexnum == 0 || Indexnum > 0){
        printf("\n");
        displayPatient(&contacts[Indexnum]);
    }
    else{
        printf("*** Contact NOT FOUND ***\n\n");
    }
}

void addPatients(struct Contact* contacts, int size) {
    int emptyIndex = 0;
    char Input_num[11] = { 0 };
    printHeader("3. Add patient");
    emptyIndex = findIndex(contacts, size, Input_num);
    if (emptyIndex == -1){
        printf("*** ERROR: The contact list is full! ***\n\n");
    }
    else{
        getContact(&contacts[emptyIndex]);
        printf("--- New contact added! ---\n\n");
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

void updatePatients(struct Contact* contacts, int size) {
    char CellNum[13] = { 0 };
    int index = 0;
    int isDone = 0;
    int selection = 0;

    printHeader("4. Modify patient");
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(CellNum);
    index = findIndex(contacts, size, CellNum);
    if (index >= 0) {
        printf("\nContact found:\n");
        displayPatient(&contacts[index]);
        printf("\n");
        while (!isDone)
        {
            selection = displayUpdateMenu();
            switch (selection) {
            case 1:
                clearKeyboard();
                contacts[index].name.firstName[0] = '\0';
                contacts[index].name.lastName[0] = '\0';
                getName(&contacts[index].name);
                printSuccessMsg("name");
                pause();
                break;
            case 2:
                clearKeyboard();
                getBirth(&contacts[index].birthdate);  
                printSuccessMsg("Birth Date");
                pause();
                break;
            case 3:
                clearKeyboard();
                getAddress(&contacts[index].address);
                printSuccessMsg("Address");
                pause();
                break;
            case 4:
                clearKeyboard();
                getNumbers(&contacts[index].numbers);
                printSuccessMsg("Numbers & Email");
                pause();
                break;
            case 5:
                clearKeyboard();
                getResults(&contacts[index].result);
                printSuccessMsg("Result");
                pause();
                break;
            case 0:
                isDone = 1;
            }
        }
    }
    else{
        printf("*** Contact NOT FOUND ***\n");
        printf("\n");
    }
}

void deletePatients(struct Contact* contacts, int size) {
    char CellNum[13] = { 0 };
    int index = 0;
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(CellNum);
    clearKeyboard();
    index = findIndex(contacts, size, CellNum); // finding index of cellnumber in array 
    if (index == 0 || index > 0)
    {
        printf("\n");
        printf("Contact found:\n");
        displayPatient(&contacts[index]);
        printf("CONFIRM: Delete this contact? (y or n): ");
        if (yes() == 1){
            strcpy(contacts[index].numbers.cell, "");
            strcpy(contacts[index].numbers.secondCell,"");
            printf("--- Contact deleted! ---\n\n");
        }
        else{
            printf("\n");
        }
    }
    else{
        printf("*** Contact NOT FOUND ***\n\n");
    }
    sortPatients(contacts, MAXCONTACTS);
}

void sortPatients(struct Contact* contacts, int size) {
    for (int i = 0;i < size;i++) {
        if (strlen(contacts[i].numbers.cell) == 0){
            //if the patients information is deleted
            contacts[size-1] = contacts[i];
            contacts[i] = contacts[i + 1];
            *(contacts + i + 1)->numbers.cell = '\0';
        }
    }
}

