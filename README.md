# Project Title
Covid19 - Patient Management & Record Tracking System

## Description

This application manages patient information with Add, Modify, Remove, and Search functions.
Also, it is able to get the records of patients who have tested positive in percentage by region or age.
User can save the updated patients' data, and records of results.


## Getting Started

### Compiling and Running the Application
First of all, download the zip file and unzip on your computer, or clone the repository using HTTPS.
`git clone https://github.com/myjin590/Covid19-project.git`

Compile the source codes
`gcc -o ws contact.c helpers.c covid19_project.`
Run the executable program
`ws.exe`


## Sample output
`Welcome to Covid Patient Management System.
-------------------------
1. Display All patients
2. Display Records
3. Add patient
4. Modify patient
5. Remove patient
6. Search patient
0. Exit
Select an option--> 1

+-----------------------------------------------------------------------------+
                               1. Display All patients
+-----------------------------------------------------------------------------+
1 |
FULL NAME : Francoise Rautenstrauch
     BIRTH DATE: 1990-2-20
     ADDRESS   : 2335 Canton Hwy #6, Windsor, ON
     PHONE     : 519-569-8399
     TEST DATE : 2021-11-2
---> RESULT    : Positive
2 |
FULL NAME : Kendra Loud
     BIRTH DATE: 2002-10-2
     ADDRESS   : 6 Arch St #9757, Alcida, NB
     PHONE     : 506-363-1526
     TEST DATE : 2021-11-3
---> RESULT    : Positive
3 |
FULL NAME : Lourdes Bauswell
     BIRTH DATE: 1972-11-2
     ADDRESS   : 9547 Belmont Rd #21, Belleville, ON
     PHONE     : 613-903-7043
     TEST DATE : 2021-11-4
---> RESULT    : Positive

.
.
.

47 |
FULL NAME : Edelmira Calzado
     BIRTH DATE: 1966-2-3
     ADDRESS   : 4936 Walcott Rd, Regina, SK
     PHONE     : 306-611-7185
     TEST DATE : 2021-6-27
---> RESULT    : Negative
48 |
FULL NAME : Jaime Wasurick
     BIRTH DATE: 1962-4-7
     ADDRESS   : 6760 E Fayette St #9, Saint-Damien, QC
     PHONE     : 450-531-8633
     TEST DATE : 2021-12-11
---> RESULT    : Negative
49 |
FULL NAME : Lera Hua
     BIRTH DATE: 1959-12-25
     ADDRESS   : 6638 S Webster St #491, Miramichi, NB
     PHONE     : 506-556-4300
     TEST DATE : 2021-10-10
---> RESULT    : Negative
+-----------------------------------------------------------------------------+
Total Patients : 49

(Press Enter to Continue)

-------------------------
1. Display All patients
2. Display Records
3. Add patient
4. Modify patient
5. Remove patient
6. Search patient
0. Exit
Select an option--> 2

+-----------------------------------------------------------------------------+
                               2. Display Records
+-----------------------------------------------------------------------------+
Choose Option
1. Display percentage of Positive results by Age
2. Display percentage of Positive results by Province
Select an option--> 1

+-----------------------------------------------------------------------------+
                               Results by Age
+-----------------------------------------------------------------------------+
~19 : 21.74%
20-30 : 13.04%
30-40 : 17.39%
40-50 : 26.09%
50-60 : 4.35%
60-70 : 13.04%
70-80 : 4.35%
80~ : 0.00%
+-----------------------------------------------------------------------------+
Total Patients : 23

(Press Enter to Continue)

-------------------------
1. Display All patients
2. Display Records
3. Add patient
4. Modify patient
5. Remove patient
6. Search patient
0. Exit
Select an option--> 2

+-----------------------------------------------------------------------------+
                               2. Display Records
+-----------------------------------------------------------------------------+
Choose Option
1. Display percentage of Positive results by Age
2. Display percentage of Positive results by Province
Select an option--> 2

+-----------------------------------------------------------------------------+
                               Results by Age
+-----------------------------------------------------------------------------+
ON : 26.09%
AB : 13.04%
BC : 13.04%
NB : 4.35%
SK : 17.39%
NS : 4.35%
QC : 21.74%
Other : 0.00%
+-----------------------------------------------------------------------------+
Total Patients : 23

(Press Enter to Continue)

-------------------------
1. Display All patients
2. Display Records
3. Add patient
4. Modify patient
5. Remove patient
6. Search patient
0. Exit
Select an option--> 3

+-----------------------------------------------------------------------------+
                               3. Add patient
+-----------------------------------------------------------------------------+
Please enter the following information
the patient's first name: John
the patient's last name: Doe
Patient's birthdate (ex: YYYY.MM.DD): 2022.12.12
Enter date again(ex: YYYY.MM.DD): 2000.13.12
Enter date again(ex: YYYY.MM.DD): 2000.12.31
Street address with street number: 31 John st
City: Toronto
Province (ex:ON, QC, etc): ON
Postal code: M1J 3P9
Patient's cell phone number without dash: 647abc1234
Enter a 10-digit phone number: 64712344444
Enter a 10-digit phone number: 6471234567
Do you want to enter a second cell phone number? (y or n): n
Patient's email address: johndoe@hello.com
Patient's covid test result (ex: Positive -> P or Negative -> N): Positive
Please enter P(positive) or N(negative): P
Patient's covid test date in number(ex: YYYY.MM.DD): 2021.12.04
--- New contact added! ---

(Press Enter to Continue)

-------------------------
1. Display All patients
2. Display Records
3. Add patient
4. Modify patient
5. Remove patient
6. Search patient
0. Exit
Select an option--> 1

+-----------------------------------------------------------------------------+
                               1. Display All patients
+-----------------------------------------------------------------------------+
1 |
FULL NAME : Francoise Rautenstrauch
     BIRTH DATE: 1990-2-20
     ADDRESS   : 2335 Canton Hwy #6, Windsor, ON
     PHONE     : 519-569-8399
     TEST DATE : 2021-11-2
---> RESULT    : Positive
2 |
FULL NAME : Kendra Loud
     BIRTH DATE: 2002-10-2
     ADDRESS   : 6 Arch St #9757, Alcida, NB
     PHONE     : 506-363-1526
     TEST DATE : 2021-11-3
---> RESULT    : Positive
3 |
FULL NAME : Lourdes Bauswell
     BIRTH DATE: 1972-11-2
     ADDRESS   : 9547 Belmont Rd #21, Belleville, ON
     PHONE     : 613-903-7043
     TEST DATE : 2021-11-4
---> RESULT    : Positive
.
.
.

48 |
FULL NAME : Jaime Wasurick
     BIRTH DATE: 1962-4-7
     ADDRESS   : 6760 E Fayette St #9, Saint-Damien, QC
     PHONE     : 450-531-8633
     TEST DATE : 2021-12-11
---> RESULT    : Negative
49 |
FULL NAME : Lera Hua
     BIRTH DATE: 1959-12-25
     ADDRESS   : 6638 S Webster St #491, Miramichi, NB
     PHONE     : 506-556-4300
     TEST DATE : 2021-10-10
---> RESULT    : Negative
50 |
FULL NAME : John Doe
     BIRTH DATE: 2000-12-31
     ADDRESS   : 31 John st, Toronto, ON
     PHONE     : 647-123-4567
     TEST DATE : 2021-12-4
---> RESULT    : Positive
+-----------------------------------------------------------------------------+
Total Patients : 50

(Press Enter to Continue)

-------------------------
1. Display All patients
2. Display Records
3. Add patient
4. Modify patient
5. Remove patient
6. Search patient
0. Exit
Select an option--> 4

+-----------------------------------------------------------------------------+
                               4. Modify patient
+-----------------------------------------------------------------------------+
Enter the cell number for the contact: 6471234567

Contact found:

FULL NAME : John Doe
     BIRTH DATE: 2000-12-31
     ADDRESS   : 31 John st, Toronto, ON
     PHONE     : 647-123-4567
     TEST DATE : 2021-12-4
---> RESULT    : Positive

-----------------------------
Please choose menu for update
1. Name
2. Birth Date
3. Address
4. Phone number && Email
5. Covid Result and Test Date
0. Go back to menu
Selection--> 1

the patient's first name: James
the patient's last name: Lee
patient's name is successfully updated!
(Press Enter to Continue)

-----------------------------
Please choose menu for update
1. Name
2. Birth Date
3. Address
4. Phone number && Email
5. Covid Result and Test Date
0. Go back to menu
Selection--> 0

(Press Enter to Continue)
-------------------------
1. Display All patients
2. Display Records
3. Add patient
4. Modify patient
5. Remove patient
6. Search patient
0. Exit
Select an option--> 1

+-----------------------------------------------------------------------------+
                               1. Display All patients
+-----------------------------------------------------------------------------+
1 |
FULL NAME : Francoise Rautenstrauch
     BIRTH DATE: 1990-2-20
     ADDRESS   : 2335 Canton Hwy #6, Windsor, ON
     PHONE     : 519-569-8399
     TEST DATE : 2021-11-2
---> RESULT    : Positive
2 |
FULL NAME : Kendra Loud
     BIRTH DATE: 2002-10-2
     ADDRESS   : 6 Arch St #9757, Alcida, NB
     PHONE     : 506-363-1526
     TEST DATE : 2021-11-3
---> RESULT    : Positive
3 |
FULL NAME : Lourdes Bauswell
     BIRTH DATE: 1972-11-2
     ADDRESS   : 9547 Belmont Rd #21, Belleville, ON
     PHONE     : 613-903-7043
     TEST DATE : 2021-11-4
---> RESULT    : Positive

.
.
.

48 |
FULL NAME : Jaime Wasurick
     BIRTH DATE: 1962-4-7
     ADDRESS   : 6760 E Fayette St #9, Saint-Damien, QC
     PHONE     : 450-531-8633
     TEST DATE : 2021-12-11
---> RESULT    : Negative
49 |
FULL NAME : Lera Hua
     BIRTH DATE: 1959-12-25
     ADDRESS   : 6638 S Webster St #491, Miramichi, NB
     PHONE     : 506-556-4300
     TEST DATE : 2021-10-10
---> RESULT    : Negative
50 |
FULL NAME : James Lee
     BIRTH DATE: 2000-12-31
     ADDRESS   : 31 John st, Toronto, ON
     PHONE     : 647-123-4567
     TEST DATE : 2021-12-4
---> RESULT    : Positive
+-----------------------------------------------------------------------------+
Total Patients : 50

(Press Enter to Continue)

-------------------------
1. Display All patients
2. Display Records
3. Add patient
4. Modify patient
5. Remove patient
6. Search patient
0. Exit
Select an option--> 5
Enter the cell number for the contact: 5065564300

Contact found:

FULL NAME : Lera Hua
     BIRTH DATE: 1959-12-25
     ADDRESS   : 6638 S Webster St #491, Miramichi, NB
     PHONE     : 506-556-4300
     TEST DATE : 2021-10-10
---> RESULT    : Negative
CONFIRM: Delete this contact? (y or n): y
--- Contact deleted! ---

(Press Enter to Continue)

-------------------------
1. Display All patients
2. Display Records
3. Add patient
4. Modify patient
5. Remove patient
6. Search patient
0. Exit
Select an option--> 1

+-----------------------------------------------------------------------------+
                               1. Display All patients
+-----------------------------------------------------------------------------+
1 |
FULL NAME : Francoise Rautenstrauch
     BIRTH DATE: 1990-2-20
     ADDRESS   : 2335 Canton Hwy #6, Windsor, ON
     PHONE     : 519-569-8399
     TEST DATE : 2021-11-2
---> RESULT    : Positive
2 |
FULL NAME : Kendra Loud
     BIRTH DATE: 2002-10-2
     ADDRESS   : 6 Arch St #9757, Alcida, NB
     PHONE     : 506-363-1526
     TEST DATE : 2021-11-3
---> RESULT    : Positive
3 |
FULL NAME : Lourdes Bauswell
     BIRTH DATE: 1972-11-2
     ADDRESS   : 9547 Belmont Rd #21, Belleville, ON
     PHONE     : 613-903-7043
     TEST DATE : 2021-11-4
---> RESULT    : Positive

.
.
.

47 |
FULL NAME : Edelmira Calzado
     BIRTH DATE: 1966-2-3
     ADDRESS   : 4936 Walcott Rd, Regina, SK
     PHONE     : 306-611-7185
     TEST DATE : 2021-6-27
---> RESULT    : Negative
48 |
FULL NAME : Jaime Wasurick
     BIRTH DATE: 1962-4-7
     ADDRESS   : 6760 E Fayette St #9, Saint-Damien, QC
     PHONE     : 450-531-8633
     TEST DATE : 2021-12-11
---> RESULT    : Negative
49 |
FULL NAME : James Lee
     BIRTH DATE: 2000-12-31
     ADDRESS   : 31 John st, Toronto, ON
     PHONE     : 647-123-4567
     TEST DATE : 2021-12-4
---> RESULT    : Positive
+-----------------------------------------------------------------------------+
Total Patients : 49

(Press Enter to Continue)

-------------------------
1. Display All patients
2. Display Records
3. Add patient
4. Modify patient
5. Remove patient
6. Search patient
0. Exit
Select an option--> 6
Enter the cell number for the contact: 6471234567


FULL NAME : James Lee
     BIRTH DATE: 2000-12-31
     ADDRESS   : 31 John st, Toronto, ON
     PHONE     : 647-123-4567
     TEST DATE : 2021-12-4
---> RESULT    : Positive
(Press Enter to Continue)

-------------------------
1. Display All patients
2. Display Records
3. Add patient
4. Modify patient
5. Remove patient
6. Search patient
0. Exit
Select an option--> 0

Exit the program? (Y)es/(N)o: y

Would you like to save the updated data? (Y)es/(N)o: y
Would you like to save the record of result? (Y)es/(N)o: y
***Saved updated Result in csv file***
***Saved updated Result in csv file***
Covid-Patient Management System: terminated 


## Authors
Jinny Yun

## Version History
* 0.2
    * Various bug fixes and optimizations
* 0.1
    * Initial Release

## License

This project is licensed under the JInny Yeejin Yun License - see the LICENSE.md file for details
