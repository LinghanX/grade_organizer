#include "Student.h"
#include <iostream>
#include <iomanip>

Student::Student(std::string studentName,
                 std::string studentId,
                 std::string yearInSchool,
                 std::string department,
                 double midterm, double final, double hw1,
                 double hw2, double hw3, double attendance,
                 double project) {
    this->studentName = studentName;
    this->studentId = studentId;
    this->yearInSchool = yearInSchool;
    this->department = department;
    this->midTerm = midterm;
    this->final = final;
    this->hw1 = hw1;
    this->hw2 = hw2;
    this->hw3 = hw3;
    this->attendance = attendance;
    this->project = project;
}

Student::~Student() { }

double Student::calcExamAverage() {
    return (midTerm + final)/2.0;
}

double Student::calcHWAverage() {
    return (hw1 + hw2 + hw3) / 3.0;
}

double Student::calcOverallGrade() {
    double examGrade = calcExamAverage();
    double hw = calcHWAverage();

    return examGrade * 0.5 + hw * 0.2 + project * 0.2 + attendance * 0.1;
}

std::string Student::letterGrade(){
    std::string grade;
    double overallGrade = calcOverallGrade();
    if(overallGrade < 60){
        grade = "F";
    } else if (overallGrade < 65){
        grade = "D-";
    } else if (overallGrade < 70){
        grade = "D";
    } else if (overallGrade < 75){
        grade = "C-";
    } else if (overallGrade < 80){
        grade = "C";
    } else if(overallGrade < 85){
        grade = "B-";
    } else if(overallGrade < 90){
        grade = "A-";
    } else if(overallGrade < 100){
        grade = "A";
    }
    return grade;
}

void Student::display() {
    double overallGrade = calcOverallGrade();
    double examAverage = calcExamAverage();
    double hwAverage = calcHWAverage();
    std::cout << std::right;
    std::cout << std::setw(12) << studentName << " |"
              << std::setw(10) << studentId << " |"
              << std::setw(10) << yearInSchool << " |"
              << std::setw(25) << department << " |"
              << std::setw(5) << std::setprecision(3) << midTerm << " |"
              << std::setw(5) << std::setprecision(3) << final << " |"
              << std::setw(5) << std::setprecision(3) << examAverage << " |"
              << std::setw(5) << std::setprecision(3) << hw1 << " |"
              << std::setw(5) << std::setprecision(3) << hw2 << " |"
              << std::setw(5) << std::setprecision(3) << hw3 << " |"
              << std::setw(5) << std::setprecision(3) << hwAverage << " |"
              << std::setw(5) << std::setprecision(3) << attendance << " |"
              << std::setw(5) << std::setprecision(3) << project << " |"
              << std::setw(5) << std::setprecision(3) << overallGrade << " |"
              << std::setw(5) << std::setw(3) << letterGrade() << " |"
              << std::endl;
}

