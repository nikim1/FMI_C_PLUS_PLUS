#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <exception>

#include "Student.h"

class StudentList
{
public:
	StudentList(std::string filePath);

	Student getValedictiorian() const;
	std::vector<Student> getHonorRollStudents() const;
	std::vector<Student> getFailingStudents() const;

private:
	std::vector<Student> students;
};

class NoValedictorianException : public std::exception
{
public:
	const char* what() const throw()
	{
		return "StudentList: No Valedictorian!";
	}
};

