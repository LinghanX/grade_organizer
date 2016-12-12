#include <iostream>
#include <fstream>
#include <vector>
#include "Student.h"
using namespace std;

void addInformation(string fileName);
void searchInformation(string fileName);

int main() {
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

void addInformation(string fileName){
    ofstream writeFile;
    writeFile.open(fileName, ios::app);
    char whiteSpace[2];
    if(writeFile.good()){
        string studentName, studentId, yearInSchool, department;
        double midTerm, final, hw1, hw2, hw3, attendance, project;
        cout << "Please enter student\'s name." << endl;
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
    cout << "Do you want to add another student information?(input 1 for yes)" << endl;
    int userResponse;
    cin >> userResponse;
    if(userResponse == 1){ addInformation(fileName); }
    writeFile.close();
}

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
                    if(line[i] == ',' || line[i] == string::npos){
                        strs[increment++] = candidate;
                        candidate = "";
                    } else {
                        candidate += line[i];
                    }
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


/**
 * 1. Ask user to input student's information that includes: name, midterm score, final score
 *    each homework score, attendance score, project score.
 * 2. Calculates exam average, homework average, overall numeric grade, letter grade.
 * 3. Write the file down to a txt.
 * 3. Allow searching
 *
 * Behavior:
 *      When first started, ask to enter a file name.
 *          if file exist,
 *              ask whether want to
 *                  add info,
 *                  or search info
 *                      if search
 *                          ask words to be searched
 *
 *
 */