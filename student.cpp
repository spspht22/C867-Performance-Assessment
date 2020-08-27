#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include "degree.h"
#include "student.h"
using namespace std;


//Accessor(i.e., getter) for each instance variable from part D1
string Student::getterstudentID() { return studentID; }
string Student::getterFirstName() { return firstName; }
string Student::getterLastName() { return lastName; }
string Student::getterEmail() { return email; }
int Student::getterAge() { return age; }
int* Student::getterDaysInCourse() { return days; }
DegreeProgram Student::getterDegreeProgram() { return degreeProgram; }

// Mutator (i.e., setter) for each instance variable from part D1
void Student::setterstudentID(string nStudentID) { studentID = nStudentID; }
void Student::setterFirstName(string nFirstName) { firstName = nFirstName; }
void Student::setterLastName(string nLastName) { lastName = nLastName; }
void Student::setterEmail(string nEmail) { email = nEmail; }
void Student::setterAge(int nAge) { age = nAge; }
void Student::setterDegree(DegreeProgram nDegreeProgram) { degreeProgram = nDegreeProgram; }
void Student::setterDaysInCourse(int* daysInCourse) {
    for (int i = 0; i < 3; i++) {

        days[i] = daysInCourse[i];
    }
}

// if statement to run if true
int Student::authenticEmail() {

    if (email.find("@") == string::npos) {

        return 1;
    }
    if (email.find(".") == string::npos) {
        
        return 1;
    }
    if (email.find(" ") != string::npos) {
        
        return 1;
    }
    return 0;
}

// Roster Table with alignements.
void Student::print() {

    string studID = this->getterstudentID();
    string fName = this->getterFirstName();
    string lName = this->getterLastName();
    string eMail = this->getterEmail();
    int AGE = this->getterAge();
    int courseOne = this->getterDaysInCourse()[0];
    int courseTwo = this->getterDaysInCourse()[1];
    int courseThree = this->getterDaysInCourse()[2];
  
    cout << "Student ID: "     << left << setw(5)  << studID;
    cout << "First Name: "     << left << setw(10) << fName;
    cout << "Last Name: "      << left << setw(10) << lName;
    cout << "Email: "          << left << setw(25) << eMail;
    cout << "Age: "            << left << setw(5)  << AGE;
    cout << "Course 1: "       << left << setw(5)  << courseOne;
    cout << "Course 2: "       << left << setw(5)  << courseTwo;
    cout << "Course 3: "       << left << setw(5)  << courseThree;
    cout << "Degree Program: " << left << setw(10);

    if (this->getterDegreeProgram() == DegreeProgram::SECURITY) {

        cout << "Security";
    }
    else if (this->getterDegreeProgram() == DegreeProgram::NETWORK) {
        
        cout << "Network";
    }
    else {
        
        cout << "Software";
    }
    cout << endl;
}

Student::Student() {}

// constructor using all of the input parameters provided in the table
Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse[3], DegreeProgram degreeType) {

    setterstudentID(studentID);
    setterFirstName(firstName);
    setterLastName(lastName);
    setterEmail(email);
    setterAge(age);
    setterDaysInCourse(daysInCourse);
    setterDegree(degreeType);
}

//Roster data table
const string Student::studentTable[] = {

    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    //  Modify the “studentTable Table” to include your personal information as the last item.
    "A5,Martin,Silva,msilv99@wgu.edu,31,30,40,45,SOFTWARE"
};

// Student Deconstructor.
Student::~Student() = default;