#pragma once
#include <string>
#include "degree.h"

using namespace std;



class Student {
	public:
		const static int arraySize = 3;
		/*Constructors and destructors*/
		Student();
		~Student();
		Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDays[], DegreeProgram degreeProgram);
		
		/*Getter methods for the Student class*/
		string getStudentID() const;
		int getAge() const;
		string getFirstName() const;
		string getLastName() const;
		string getEmail() const;
		DegreeProgram getDegreeProgram() const;
		int* getNumDays();
		
		/*Setter methods for the Student class attributes*/
		void setStudentID(int studentID);
		void setAge(int age);
		void setFirstName(string name);
		void setLastName(string name);
		void setEmail(string email);
		void setDegreeProgram(DegreeProgram program);
		void setNumDays(int days1, int days2, int days3);
		
		void printHeader();
		void print();

	private:
		string studentID;
		string firstName;
		string lastName;
		string email;
		int age;
		int numDays[arraySize];
		DegreeProgram degreeProgram;
};