#include "roster.h"
#include <iostream>
#include <string>

void Roster::parse(string data)
{
	size_t left = 0;
	size_t right = 0;
	
	right = data.find(",");
	string studentID = data.substr(0, right);

	left = right + 1;
	right = data.find(",", left);
	string first = data.substr(left, right - left);

	left = right + 1;
	right = data.find(",", left);
	string last = data.substr(left, right - left);

	left = right + 1;
	right = data.find(",", left);
	string email = data.substr(left, right - left);

	left = right + 1;
	right = data.find(",", left);
	int age = stoi(data.substr(left, right - left));

	left = right + 1;
	right = data.find(",", left);
	int days1 = stoi(data.substr(left, right - left));

	left = right + 1;
	right = data.find(",", left);
	int days2 = stoi(data.substr(left, right - left));

	left = right + 1;
	right = data.find(",", left);
	int days3 = stoi(data.substr(left, right - left));

	left = right + 1;
	right = data.find(",", left);
	string deg = data.substr(left, right - left);
	DegreeProgram degree = SECURITY;
	if (deg == "SOFTWARE") {
		degree = SOFTWARE;
	}
	else if (deg == "NETWORK") {
		degree = NETWORK;
	}

	add(studentID, first, last, email, age, days1, days2, days3, degree);
}

void Roster::add(string studentID, 
				string firstName, 
				string lastName, 
				string emailAddress, 
				int age, 
				int daysInCourse1, 
				int daysInCourse2, 
				int daysInCourse3, 
				DegreeProgram degreeProgram)
{
	int days[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[index] = new Student(studentID, firstName, lastName, emailAddress, age, days, degreeProgram);
	index++;
}

void Roster::remove(string studentID)
{
	bool student = false;
	for (int i = 0; i < index; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			/* Swap the student to remove with the last element of the array
			   Decrement the index to reduce the size of the array. The last element is now no longer part of the array, but the object is still in memory.	
			*/
			Student* temp = classRosterArray[i];
			classRosterArray[i] = classRosterArray[index - 1];
			classRosterArray[index - 1] = temp;
			index--;
			student = true;
		}
		
	}
	if (!student) {
		cout << "The student ID could not be found" << std::endl;
	}
	else {
		cout << "The student " << studentID << " was removed" << std::endl;
	}
}

void Roster::printAll()
{
	//Student::printHeader;
	for (int i = 0; i < index; i++) {
		
		cout << classRosterArray[i]->getStudentID() << "\t";
		cout << "First Name: " << classRosterArray[i]->getFirstName() << "\t";
		cout << "Last Name: " << classRosterArray[i]->getLastName() << "\t";
		cout << "Email address: " << classRosterArray[i]->getEmail() << "\t";
		cout << "Age: " << classRosterArray[i]->getAge() << "\t";
		cout << "daysInCourse: {" << classRosterArray[i]->getNumDays()[0] << ", ";
		cout << classRosterArray[i]->getNumDays()[1] << ", ";
		cout << classRosterArray[i]->getNumDays()[2] << "}\t";
		cout << "Degree Program: " << degreeNames[classRosterArray[i]->getDegreeProgram()] << std::endl;
	}
}

void Roster::printAverageDaysInCourse(string studentID)
{
	double total = 0;
	double days = 3.0;
	bool student = false;

	for (int i = 0; i < index; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			total = classRosterArray[i]->getNumDays()[0] + classRosterArray[i]->getNumDays()[1] + classRosterArray[i]->getNumDays()[2];
			student = true;
			break;
		}
	}
	if (!student) {
		cout << "The student ID could not be found" << std::endl;
	}
	else {
		cout << "Average days in courses for student " << studentID << ": " << total / days << std::endl;
	}
}

void Roster::printInvalidEmails()
{
	bool invalid = false;
	for (int i = 0; i < index; i++) {
		string email = classRosterArray[i]->getEmail();
		if (email.find(" ") != string::npos || !(email.find("@") != string::npos) || !(email.find(".") != string::npos)) {
			cout << email << "\n";
			invalid = true;

		}
	}
	if (!invalid) {
		cout << "There are no invalid email addresses" << std::endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	bool program = false;
	//Student::printHeader;
	for (int i = 0; i < index; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
			program = true;
		}
	}

	if (!program) {
		cout << "The degree program could not be found" << std::endl;
	}
}

Roster::~Roster()
{
	for (int i = 0; i < index; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}

	cout << "All students have been deleted" << std::endl;
}
