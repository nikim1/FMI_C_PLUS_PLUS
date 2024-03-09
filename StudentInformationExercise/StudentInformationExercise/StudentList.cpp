#include "StudentList.h"

#define FAILING_GRADE 65
#define HONORROLE_GRADE 90

StudentList::StudentList(std::string filePath)
{
	std::ifstream studentFile(filePath);

	std::string lineContents;
	while (!studentFile.eof())
	{
		std::getline(studentFile, lineContents);

		Student s(lineContents);
		students.push_back(s);
	}

	studentFile.close();
	std::sort(students.begin(), students.end(), [](Student &s1, Student &s2)
		                                         {
			                                         return s1.getGPA() > s2.getGPA();
		                                         });
}

Student StudentList::getValedictiorian() const
{
	if (students.empty() || students.at(0).getGPA() < FAILING_GRADE)
		throw NoValedictorianException();

	return students.at(0);
}

std::vector<Student> StudentList::getHonorRollStudents() const
{
	std::vector<Student> honorStudents;
	for (Student s: students)
	{
		if (s.getGPA() < HONORROLE_GRADE)
			break;
		else
			honorStudents.push_back(s);
	}

	return honorStudents;
}

std::vector<Student> StudentList::getFailingStudents() const
{
	std::vector<Student> failedStudents;
	for (std::vector<Student>::const_reverse_iterator iter = students.rbegin(); iter < students.rend(); iter++)
	{
		if (iter->getGPA() >= FAILING_GRADE)
			break;
		else
			failedStudents.push_back(*iter);
	}

	return failedStudents;
}
