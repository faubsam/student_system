#include "student.h"
#include <iostream>
using namespace std;


Student::Student()
{
	this->studentID = "";
	this->age = 0;
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->degreeProgram = DegreeProgram::NETWORK;
	for (int i = 0; i < arraySize; i++) { this->numDays[i] = 0; }
}

Student::~Student()
{
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->age = age;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = emailAddress;
	this->degreeProgram = degreeProgram;
	for (int i = 0; i < arraySize; i++) { this->numDays[i] = numDays[i]; }
}

string Student::getStudentID() const
{
	return this->studentID;
}

int Student::getAge() const
{
	return this->age;
}

string Student::getFirstName() const
{
	return this->firstName;
}

string Student::getLastName() const
{
	return this->lastName;
}

string Student::getEmail() const
{
	return this->email;
}

DegreeProgram Student::getDegreeProgram() const
{
	return this->degreeProgram;
}

int* Student::getNumDays()
{
	return this->numDays;
}

void Student::setStudentID(int studentID)
{
	this->studentID = studentID;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setFirstName(string name)
{
	this->firstName = name;
}

void Student::setLastName(string name)
{
	this->lastName = name;
}

void Student::setEmail(string email)
{
	this->email = email;
}

void Student::setDegreeProgram(DegreeProgram program)
{
	this->degreeProgram = program;
}

void Student::setNumDays(int days1, int days2, int days3)
{
	numDays[0] = days1;
	numDays[1] = days2;
	numDays[2] = days3;
}

void Student::printHeader()
{
	cout << "Student ID | First Name | Last Name | Age | Days in course | Degree Program";
}

void Student::print()
{
	cout << this->getStudentID() << "\t";
	cout << this->getFirstName() << "\t";
	cout << this->getLastName() << "\t";
	cout << this->getAge() << "\t";
	cout << this->getNumDays()[0] << ",";
	cout << this->getNumDays()[1] << ",";
	cout << this->getNumDays()[2] << "\t";
	cout << degreeNames[this->getDegreeProgram()] << "\n";

}
