#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    int studentID;
    string name;
    float marks1, marks2, marks3;

public:
    void getStudentData()
    {
        cout << "Enter Student ID: ";
        cin >> studentID;

        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, name);

        cout << "Enter marks in Subject 1: ";
        cin >> marks1;

        cout << "Enter marks in Subject 2: ";
        cin >> marks2;

        cout << "Enter marks in Subject 3: ";
        cin >> marks3;
    }

    float calculateAverage()
    {
        return (marks1 + marks2 + marks3) / 3;
    }
};

class EngineeringStudent : public Student
{
protected:
    string branch;

public:
    void getEngineeringData()
    {
        cout << "Enter Branch: ";
        cin >> branch;
    }

    char calculateGrade()
    {
        float average = calculateAverage();

        if (average >= 90)
            return 'A';
        else if (average >= 80)
            return 'B';
        else if (average >= 70)
            return 'C';
        else if (average >= 60)
            return 'D';
        else
            return 'F';
    }
};

class Sports
{
protected:
    float sportsScore;

public:
    void getSportsData()
    {
        cout << "Enter Sports Score: ";
        cin >> sportsScore;
    }
};

class Result : public EngineeringStudent, public Sports
{
public:
    float calculateOverallScore()
    {
        float academicAverage = calculateAverage();
        return (academicAverage * 0.70) + (sportsScore * 0.30);
    }

    void display()
    {
        cout << "\n----- Student Result -----" << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Name: " << name << endl;
        cout << "Marks in Subject 1: " << marks1 << endl;
        cout << "Marks in Subject 2: " << marks2 << endl;
        cout << "Marks in Subject 3: " << marks3 << endl;
        cout << "Average Marks: " << calculateAverage() << endl;
        cout << "Branch: " << branch << endl;
        cout << "Grade: " << calculateGrade() << endl;
        cout << "Sports Score: " << sportsScore << endl;
        cout << "Overall Performance Score: " << calculateOverallScore() << endl;
    }
};

int main()
{
    Result student;

    student.getStudentData();
    student.getEngineeringData();
    student.getSportsData();

    student.display();

    return 0;
}