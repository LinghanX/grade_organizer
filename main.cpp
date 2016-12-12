/*
 * This file is created in order to fulfill the course requirement of
 *      `CSCI333 Object Oriented Programming using C++`
 * from Framingham State University.
 *
 * Program description:
 *
 *      The program is designed for instructors to manage student
 *      course information, including their name, ID, year,
 *      department, exam scores and home word scores.
 *
 *      The program provides API for instructor to search through the
 *      file and return all the relevant information in a formatted way.
 *
 *      Note that the search function here is CASE SENSITIVE.
 *
 *
 * Program structure:
 *
 *      The program consists of a main function which handles user input
 *      and interaction.
 *
 *      A student class is designed to handle student abstract data type.
 *
 * Student name: Linghan Xing
 * Date created: Dec 13, 2016
 */

#include <iostream>
#include <fstream>
#include <vector>
#include "Student.h"
using namespace std;

void addInformation(string fileName);
void searchInformation(string fileName);

int main() {
    /*
     *  To begin with, the program will ask user to input the file name. This file
     *  acts as a data storage and saves all the data for students.
     *
     */
    cout << "Please enter the file name that you want to work with: " << std::endl;
    string filename;
    cin >> filename;

    ifstream readFile;
    readFile.open(filename);

    if(readFile.good()){
        cout << "Do you want to search or add information?(1 for adding information\n"
                "2 for search)" << endl;
        readFile.close();
    } else {
        cout << "File not exist, new file created. \n"
                "Do you want to add new information?(input 1 if you "
                "want to add information)" << endl;
        readFile.close();
    }

    int userResponse;
    cin >> userResponse;
    if(userResponse == 1){
        addInformation(filename);
    } else if(userResponse == 2){
        searchInformation(filename);
    }
    return 0;
}

//addInformation() function writes student information into the file.
void addInformation(string fileName){
    ofstream writeFile;
    writeFile.open(fileName, ios::app);
    if(writeFile.good()){
        string studentName, studentId, yearInSchool, department;
        double midTerm, final, hw1, hw2, hw3, attendance, project;
        cout << "Please enter student\'s name." << endl;

        // here, the first 'getline' eat unwanted blank space.
        getline(cin, studentName);
        getline(cin, studentName);
        cout << "Please enter student\'s student ID, school year." << endl;
        cin >> studentId >> yearInSchool;
        cout << "Please enter student\'s department." << endl;
        getline(cin, department);
        getline(cin, department);
        cout << "Please enter student\'s midterm, final, home work 1, home work 2"
                ", home work 3, attendance and project information." << endl;
        cin >> midTerm >> final >> hw1 >> hw2 >> hw3 >> attendance>> project;
        Student newStudent(studentName, studentId, yearInSchool, department, midTerm,
        final, hw1, hw2, hw3, attendance, project);
        cout << "Student information successfully added." << endl;
        newStudent.display();
        writeFile << studentName + ","
                  << studentId + ","
                  << yearInSchool + ","
                  << department + ","
                  << midTerm << ","
                  << final << ","
                  << hw1 << ","
                  << hw2 << ","
                  << hw3 << ","
                  << attendance << ","
                  << project << endl;
    }
    cout << "Do you want to add another student information?"
            "(input 1 for yes, otherwise to terminate)" << endl;
    int userResponse;
    cin >> userResponse;
    if(userResponse == 1){ addInformation(fileName); }
    writeFile.close();
}

//searchInformation provides a tool for user to search CASE SENSITIVE information
void searchInformation(string fileName){
    cout << "Please input the keyword that you want to search." << endl;
    string keyword;
    getline(cin, keyword);
    getline(cin, keyword);

    ifstream readFile;
    readFile.open(fileName);
    string line;

    vector<Student> students;
    int counter = 0;
    if(readFile.good()){
        while(getline(readFile, line)){
            size_t found = line.find(keyword);
            if (found != string::npos){
                string studentName, studentId, yearInSchool, department;
                double midTerm, final, hw1, hw2, hw3, attendance, project;
                string candidate;
                string strs[11]; //could also use array;
                int increment = 0;
                for(int i = 0; i < line.size(); i++){
                    if(line[i] == ','){
                        strs[increment++] = candidate;
                        candidate = "";
                    } else {
                        candidate += line[i];
                    }
                    strs[increment] = candidate;
                }

                studentName = strs[0];
                studentId = strs[1];
                yearInSchool = strs[2];
                department = strs[3];
                midTerm = stod(strs[4]);
                final = stod(strs[5]);
                hw1 = stod(strs[6]);
                hw2 = stod(strs[7]);
                hw3 = stod(strs[8]);
                attendance = stod(strs[9]);
                project = stod(strs[10]);
                students.push_back(Student(studentName, studentId, yearInSchool,
                                           department, midTerm, final,
                                           hw1, hw2, hw3, attendance, project));
                counter++;
            }
        }
    }

    if(counter == 0){
        cout << "No item is found." << endl;
        return ;
    }
    for(int i = 0; i < counter; i++){
        students[i].display();
    }
}
