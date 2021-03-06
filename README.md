# Project Title
COVID-19 Patient Management & Record Tracking System

## Description

This application manages patient information such as Full name, Birth date, Address, Phone number, COVID-19 testing date and result, \
and is allowed to Add, Modify, Remove, Search patient with cell phone number.\
Also, it is able to get the records of patients who have tested positive in percentage by region or age.
User can save the updated patients' data, and records of results.

## Additional project

If user choose "save the data" when they exit the program, 
the records of COVID19-testing result will be saved in csv file.\
This results can be checked as graph.
You can check the project from my repository 
<a href="https://github.com/myjin590/Project-Data-Visualization">Project-Data-Visualization<href>

### Validation check

Date
1. date should be followed the form (ex: YYYY.MM.DD)
2. Year can't be greater than 2021.
3. Month should be between 0 and 12.
4. Day should be between 0 and 31.

Numbers
1. phone number should be 10 digits.
2. phone number should be entered without dash

Covid19-Testing Result
1. result should be entered one letter (P or N)

## Getting Started

### Compiling and Running the Application
* First of all, download the zip file and unzip on your computer, or clone the repository using HTTPS.\
`git clone https://github.com/myjin590/Project-COVID-19-Patient-Management.git`

* Compile the source codes\
`gcc -o ws patient.c helpers.c main.c`
* Run the executable program\
`ws.exe`


## Sample output
* Menu\
<img src="/images/menu.jpg" width="500px"></img><br>
* 1.Display All patients\
<img src="/images/1.display.jpg" width="500px"></img><br>
<img src="/images/1.display-end.jpg" width="500px"></img><br>
* 2.Display Records by age\
<img src="/images/2.records.jpg" width="500px"></img><br>
* 2.Display Records by Province\
<img src="/images/2-2.jpg" width="500px"></img><br>
* 3.Add Patient\
<img src="/images/3.add.jpg" width="500px"></img><br>
After adding a new patient\
<img src="/images/3-added.jpg" width="500px"></img><br>
* 4.Modify Patient\
<img src="/images/4-modify.jpg" width="500px"></img><br>
After modifying the patient\
<img src="/images/4-modified.jpg" width="500px"></img><br>
* 5.Remove Patient\
<img src="/images/5.remove.jpg" width="500px"></img><br>
After deleting the patient\
<img src="/images/5-removed.jpg" width="500px"></img><br>
* 6.Search Patient\
<img src="/images/6.search.jpg" width="500px"></img><br>
* Terminate program\
<img src="/images/0.exit.jpg" width="500px"></img><br>

## Authors
Jinny Yun

## Version History
* 0.1
    * Initial Release

## Acknowledgments
<a href = "https://pages.github.com/">Github Pages</href><br>
<a href = "https://www.briandunning.com/sample-data/">Sample Data</href>

