#ifndef CONTACTS_H_
#define CONTACTS_H_
#define YEAR 2021

struct Name
{
    char firstName[31];
    char lastName[36];
};

struct Birth
{
    int year;
    int month;
    int day;

};

struct Address
{
    char street[41];
    char city[15];
    char province[3];
    char postalCode[8];
};

struct Numbers
{
    char cell[13];
    char secondCell[13];
    char email[100];
};

struct Result
{
    char results[9];
    int year;
    int month;
    int day;
};

struct Contact
{
    struct Name name;
    struct Birth birthdate;
    struct Address address;
    struct Numbers numbers;
    struct Result result;

};

void getName(struct Name* name);
void getAddress(struct Address* address);
void getNumbers(struct Numbers* numbers);
void getBirth(struct Birth* birth);
void getResults(struct Result* result);
void getContact(struct Contact* contact);

#endif // CONTACTS_H_
