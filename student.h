#include <iostream>
#include <string>
#include "degree.h"
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;

// Part D1.  Create the class Student  in the files student.h and student.cpp, which includes each of the following variables :
//student ID
//first name
//last name
//email address
//age
//array of number of days to complete each course
//degree program
class Student {

public:
    const static string studentTable[];

	//Mutators
	void setterstudentID(string);
	void setterFirstName(string);
	void setterLastName(string);
	void setterEmail(string);
	void setterAge(int);
	void setterDaysInCourse(int[3]);
	void setterDegree(DegreeProgram);

	//Accessors
    string getterstudentID();
	string getterFirstName();
	string getterLastName();
	string getterEmail();
	int getterAge();
	int* getterDaysInCourse();
    DegreeProgram getterDegreeProgram();

	int authenticEmail();
	
	void print();
	
	Student();
	Student(string studentID,string firstName,string lastName,string email,int age,int daysInCourse[3],DegreeProgram degreeType);

	//deconstructor
	~Student();

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int days[3];
    DegreeProgram degreeProgram;
};

#endif