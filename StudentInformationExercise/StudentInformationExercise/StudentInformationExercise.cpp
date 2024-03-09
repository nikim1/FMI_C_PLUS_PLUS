#include <iostream>
#include <exception>

#include "Student.h"
#include "StudentList.h"

void printStudent(const Student& student)
{
    std::cout << "Name: " << student.getName() << std::endl;
    std::cout << "ID: " << student.getId() << std::endl;
    std::cout << "GPA: " << student.getGPA() << std::endl;
    std::cout << std::endl;
}

int main(int argc, const char* argv[])
{
    try
    {
        if (argc != 2)
        {
            std::cout << "Usage: StudentInformationExercise PATH_TO_STUDENT_FILE" << std::endl;
            return -1;
        }

        std::string path(argv[1]);
        StudentList list(path);
        
        std::cout << "Valedictorian: " << std::endl << std::endl;
        printStudent(list.getValedictiorian());

        std::cout << std::endl << "Honor roll students: " << std::endl << std::endl;
        for (Student s : list.getHonorRollStudents())
            printStudent(s);

        std::cout << std::endl << "Failing students: " << std::endl << std::endl;
        for (Student s : list.getFailingStudents())
            printStudent(s);
    }
    catch (const std::exception& e)
    {
        std::cout << "An exception was thrown." << std::endl;
        std::cout << "\t" << e.what() << std::endl;

        return -1;
    }

    return 0;
}
