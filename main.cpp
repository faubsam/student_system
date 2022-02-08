#include "roster.h"
#include <iostream>
#include <string>

int main() {

	cout << "C867 - Scripting and Programming - Applications #####" << " Written in C++ #####" << " Student ID 001385881 #####" << " Samuel Faubert" << std::endl;
	cout << "\n \n";

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Samuel,Faubert,faubertsamuel@gmail.com,29,12,17,21,SOFTWARE"
	};

	const static int classSize = 5;
	Roster classRoster;

	for (int i = 0; i < classSize; i++) {
		classRoster.parse(studentData[i]);
	}

	classRoster.printAll();
	cout << std::endl;

	classRoster.printInvalidEmails();
	cout << std::endl;

	for (int i = 0; i < classSize; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
		cout << std::endl;
	}

	classRoster.printByDegreeProgram(SOFTWARE);
	cout << std::endl;

	classRoster.remove("A3");
	cout << std::endl;

	classRoster.printAll();
	cout << std::endl;

	classRoster.remove("A3");
	cout << std::endl;
};