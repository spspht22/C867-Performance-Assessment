// Create a C++ project in your integrated development environment (IDE) with the following files:
//degree.h
//student.hand student.cpp
//roster.hand roster.cpp
//main.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include "degree.h"
#include "student.h"
#include "roster.h"
using namespace std;

int main() {

    //Output Color = Blue
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 3);

    Roster classRoster;

    //Signature
    classRoster.PrintIntro();

    //parses data from student table
    classRoster.parseData();

    // Prints Roster of students
    classRoster.printAll();
    
    //Prints all invalid emails
    classRoster.printInvalidEmails();
   
    //Prints average days in course for all students
    classRoster.printAverage();

    //Prints student Roster by Degree Program
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    classRoster.printByDegreeProgram(DegreeProgram::NETWORK);
    classRoster.printByDegreeProgram(DegreeProgram::SECURITY);

    // Removes Student ID #A3 from Roster
    classRoster.remove("A3");

    classRoster.PrintDelay();

    //Reprints Roster to show Student ID #A3 is no longer listed 
    classRoster.printAll();

   //Prints after not location Student ID #A3
    classRoster.remove("A3");

    cout << "Exiting 2020 Student Roster." << endl;
 
    return 0;
}