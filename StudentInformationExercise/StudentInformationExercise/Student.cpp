#include "Student.h"

Student::Student(std::string studentInfo)
{
	std::stringstream studentStream(studentInfo);
	studentStream >> firstName;
	studentStream >> lastName;
	studentStream >> id;
	studentStream >> GPA;
}

std::string Student::getFirstName()  const
{
	return firstName;
}

std::string Student::getLastName()  const
{
	return lastName;
}

std::string Student::getName()  const
{
	return firstName + " " + lastName;
}

int Student::getId() const
{
	return id;
}

double Student::getGPA() const
{
	return GPA;
}
