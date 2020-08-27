#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>
#include "roster.h"
#include "student.h"
using namespace std;

// Adds each student to the Class Roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress,int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

    int courseDays[3];

    courseDays[0] = daysInCourse1;
    courseDays[1] = daysInCourse2;
    courseDays[2] = daysInCourse3;

    classRosterArray[index] = new Student(studentID, firstName, lastName, emailAddress, age, courseDays, degreeProgram);
    
    index++;
}

//parse data on the student data table
void Roster::parseData() {
    
    cout << "Parsing Data";

    PrintDelay();

    for (int i = 0; i < ROSTER_SIZE; i++) {

        // Grabs the student data
        string input = Student::studentTable[i];

        //changed from istringstream
       std::stringstream studentString(input);

        // Separate each line by commas and store values in array
        string studentValue;
        string newEntryStudData[9];
        int summate = 0;

        while (getline(studentString, studentValue, ',')) {

            newEntryStudData[summate] = studentValue;

            summate++;
        }

        // Determine the correct degree program enum from the raw string
        DegreeProgram program;

        if (newEntryStudData[8] == "NETWORK") {

            program = DegreeProgram::NETWORK;
        }
        else if (newEntryStudData[8] == "SECURITY") {

            program = DegreeProgram::SECURITY;
        }
        else {

            program = DegreeProgram::SOFTWARE;
        }
        // Add the student to the roster
        add(newEntryStudData[0],
            newEntryStudData[1],
            newEntryStudData[2],
            newEntryStudData[3],
            std::stoi(newEntryStudData[4]),
            std::stoi(newEntryStudData[5]),
            std::stoi(newEntryStudData[6]),
            std::stoi(newEntryStudData[7]),program);
    }
}

//Removes student, Displays ID of removed student
void Roster::remove(string removeStudent) {

    int i = 0;
    bool j = false;
    
    cout << "Removing student A3";

    PrintDelay();

    for (i = 0; i < ROSTER_SIZE; i++) {
    
        if (classRosterArray[i] == nullptr) {

            cout << "Student not Found." << endl;
        } else {

            if (classRosterArray[i]->getterstudentID() == removeStudent) {

                delete classRosterArray[i];
                classRosterArray[i] = nullptr;
                j = true;

                cout << "Student " << removeStudent << " is removed." << endl;
            }
        }
    }
    PrintLoadLine();
}

//Print Class Roster
void Roster::printAll() {
    
    cout << "Loading Roster";

    PrintDelay();

    for (int i = 0; i < ROSTER_SIZE; i++) {

        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
    PrintLoadLine();
}

//Locates and Prints all invalid emails. 
void Roster::printInvalidEmails() {

    int i = 0;
    
    cout << "Printing invalid emails";
    
    PrintDelay();
    
    for (i = 0; i < ROSTER_SIZE; i++) {

        if (classRosterArray[i]->authenticEmail() == 1) {

            cout << classRosterArray[i]->getterEmail() << endl;
        }
    }
    PrintLoadLine();
}

//Print Average day in course for all students course days. 
void Roster::printAverageDaysInCourse(string studentID) {

    cout << "Printing Average Days per course";

    PrintDelay();

    for (int i = 0; i < ROSTER_SIZE; ++i) 
    {
        if (classRosterArray[i]->getterstudentID() == studentID) {

            cout << "Student ID #" << classRosterArray[i]->getterstudentID() << ": ";

            int* days = classRosterArray[i]->getterDaysInCourse();
            int AvePerCourse = (days[0] + days[1] + days[2]) / 3;
            
            cout << "Average days per course: " << AvePerCourse << endl;
            
            return;
        }
    }
}

// Prints average days of course, per student
void Roster::printAverage() {

    for (int i = 0; i < ROSTER_SIZE; i++) {
      
        string StudID = classRosterArray[i]->getterstudentID();
        printAverageDaysInCourse(StudID);

        cout << endl;
    }
}

//Prtin students by Degree type.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

    cout << "Information printing for students in ";
    
    if (degreeProgram == 0) {

        cout << "Software Degree Program";
        
        PrintDelay();
    }
    else if (degreeProgram == 1) {

        cout << "Security Degree Program";
        
        PrintDelay();
    }
    else if (degreeProgram == 2) {

        cout << "Network Degree Program";
        
        PrintDelay();
    }
    for (int i = 0; i < ROSTER_SIZE; i++) {

        if (classRosterArray[i] != nullptr) {

            if (classRosterArray[i]->getterDegreeProgram() == degreeProgram) {

                classRosterArray[i]->print();
            }
        }
    }
    cout << endl;

    PrintLoadLine();
}

// Animation to mirror loading data ("...")
void Roster::PrintDelay() {

    cout << dot;Sleep(500);
    cout << dot;Sleep(500);
    cout << dot << endl;Sleep(500);
}
// Animation to seperate Printed Data ("---")
void Roster::PrintLoadLine() {
 
    cout << line;Sleep(50);cout << line;Sleep(50);
    cout << line;Sleep(50);cout << line;Sleep(50);
    cout << line;Sleep(50);cout << line;Sleep(50);
    cout << line;Sleep(50);cout << line;Sleep(50);
    cout << line;Sleep(50);cout << line;Sleep(50);
    cout << line;Sleep(50);cout << line;Sleep(50);
    cout << line;Sleep(50);cout << line;Sleep(50);
    cout << line;Sleep(50);cout << line << endl;Sleep(200);
}

// Initial info, loads at startup. 
void Roster::PrintIntro() {

    cout << introBorder << endl;
    cout << "Created by Martin Silva jr" << endl;
    cout << "Student ID: #001228533" << endl;
    cout << "WGU C867 Performance Assessment, Software Program" << endl;
    cout << introBorder << endl;
    cout << endl;
    cout << "Loading 2020 Student Roster";

    PrintDelay();
}

// Roster Deconstructor. 
Roster::~Roster() = default;