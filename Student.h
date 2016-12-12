//
// Created by Linghan Xing on 12/6/16.
//

#ifndef CSCI333_FINAL_STUDENT_H
#define CSCI333_FINAL_STUDENT_H


#include <string>

class Student {
private:
        std::string studentName;
        std::string studentId;
        std::string yearInSchool;
        std::string department;
        double midTerm, final, hw1, hw2,
                hw3, attendance, project;
        double calcExamAverage();
        double calcHWAverage();
        double calcOverallGrade();
        std::string letterGrade();

public:
    Student(std::string studentName,
            std::string studentId,
            std::string yearInSchool,
            std::string department,
            double midterm,
            double final,
            double hw1,
            double hw2,
            double hw3,
            double attendance,
            double project
    );
    ~Student();
    void display();
};

#endif //CSCI333_FINAL_STUDENT_H
