#pragma once

#include <string>
#include <sstream>

class Student
{
public:
	Student(std::string studentInfo);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getName() const;
	int getId() const;
	double getGPA() const;

private:
	std::string firstName;
	std::string lastName;
	int id;
	double GPA;
};

