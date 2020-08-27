#include <iostream>
#include <string>
#include "student.h"
using namespace std;

class Roster {

public:
    Student* classRosterArray[5];

    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
    void parseData();
    void printAll();
    void printAverage();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void remove(string studentID);
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void PrintDelay();
    void PrintLoadLine();
    void PrintIntro();

        ~Roster();

private:
    int index = 0;
    const int ROSTER_SIZE = 5;
    char dot = '.';
    string line = "---";
    string introBorder = "=================================================";
};