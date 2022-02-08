#pragma once

#include "student.h"


class Roster {
public:
	void parse(string data);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();

public:
	const static int numStudents = 5;
	int index = 0;
	Student* classRosterArray[numStudents];

};