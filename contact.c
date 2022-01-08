#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "helpers.h"

void getName(struct Name* name)
{
    printf("the patient's first name: ");
    scanf("%30[^\n]%*c", name->firstName);
    printf("the patient's last name: ");
    scanf("%35[^\n]%*c", name->lastName);
}

void getAddress(struct Address* address)
{
    printf("Street address with street number: ");
    scanf("%40[^\n]%*c", address->street);

    printf("City: ");
    scanf("%14[^\n]%*c", address->city);

    printf("Province (ex:ON, QC, etc): ");
    scanf("%2[^\n]%*c", address->province);

    printf("Postal code: ");
    scanf("%7[^\n]%*c", address->postalCode);
}

void getBirth(struct Birth* birth) 
{
    int isDone = 0;
    char temp[11] = { 0 };
    int tempYear = 0;
    int tempMon = 0;
    int tempDay = 0;
    char* birthDate = {0};

    printf("Patient's birthdate (ex: YYYY.MM.DD): ");
    while (!isDone) {
        birthDate = strtok(getDate(temp), "."); //check validation of test date
        clearKeyboard();
        tempYear = atoi(birthDate);
        birthDate = strtok(NULL, ".");
        tempMon = atoi(birthDate);
        birthDate = strtok(NULL, "");
        tempDay = atoi(birthDate);
        if (checkValidDate(tempYear, tempMon, tempDay) == 0) {
            birth->year = tempYear;
            birth->month = tempMon;
            birth->day = tempDay;
            isDone = 1;
        }
        else {
            printf("Enter date again(ex: YYYY.MM.DD): ");
            isDone = 0;
        }
    }
}


void getNumbers(struct Numbers* numbers)
{
    printf("Patient's cell phone number without dash: ");
    getTenDigitPhone(numbers->cell); //check validation of phone number
    clearKeyboard();
    printf("Do you want to enter a second cell phone number? (y or n): ");
    if (yes() == 1) // get answer Y or N
    {
        printf("patient's second cell phone number: ");
        getTenDigitPhone(numbers->cell);
        clearKeyboard();
    }
    printf("Patient's email address: ");
    scanf("%99[^\n]%*c", numbers->email);

}

void getResults(struct Result* result) 
{
    int isDone = 0;
    char temp[100] = { 0 };
    int tempYear = 0; 
    int tempMon = 0;
    int tempDay = 0;
    char* date = { 0 };
    char r[2] = { 0 };
   
    printf("Patient's covid test result (ex: Positive -> P or Negative -> N): ");
    strcpy(result->results,getResult(&r)); // check validation and copy to result

    printf("Patient's covid test date in number(ex: YYYY.MM.DD): ");
    while (!isDone) {
        date = strtok(getDate(temp), ".");
        clearKeyboard();
        // convert to int
        tempYear = atoi(date);
        date = strtok(NULL, ".");
        tempMon = atoi(date);
        date = strtok(NULL, "");
        tempDay = atoi(date);
        if (checkValidDate(tempYear, tempMon, tempDay) == 0) {
            result->year = tempYear;
            result->month = tempMon;
            result->day = tempDay;
            isDone = 1;
        }
        else {
            printf("Enter date again(ex: YYYY.MM.DD): ");
            isDone = 0;
        }
    }
}

void getContact(struct Contact* contact) 
{
    printf("Please enter the following information\n");
    getName(&contact->name);
    getBirth(&contact->birthdate);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
    getResults(&contact->result);
}

