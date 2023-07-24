// Codesoft SIP Task 3
// C++ Programing
/*         STUDENT GRADING SYSTEM
Create a program that manages student grades. Allow the user
to input student names and their corresponding grades.
Calculate the average grade and display it along with the highest
and lowest grades
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
    string name;
    double grade;
};

int main()
{
    vector<Student> students;
    int numStudents;

    cout << "-----------------------------------------" << endl;
    cout << "###     STUDENT GRADING SYSTEM      ###" << endl;
    cout << "-----------------------------------------" << endl;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Get input from the user
    for (int i = 0; i < numStudents; ++i)
    {
        Student student;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, student.name);

        cout << "Enter student grade: ";
        cin >> student.grade;

        students.push_back(student);
    }

    // Calculate average grade
    double totalGrade = 0;
    for (const Student &student : students)
    {
        totalGrade += student.grade;
    }
    double averageGrade = totalGrade / static_cast<double>(numStudents);

    // Find highest and lowest grades
    auto maxGradeIter = max_element(students.begin(), students.end(), [](const Student &a, const Student &b)
                                    { return a.grade < b.grade; });
    auto minGradeIter = min_element(students.begin(), students.end(), [](const Student &a, const Student &b)
                                    { return a.grade < b.grade; });

    // Display the results
    cout << "\nGrade Summary" << endl;
    cout << "---------------------------" << endl;
    cout << "Average Grade: " << averageGrade << endl;
    cout << "Highest Grade: " << maxGradeIter->grade << " (Student: " << maxGradeIter->name << ")" << endl;
    cout << "Lowest Grade: " << minGradeIter->grade << " (Student: " << minGradeIter->name << ")" << endl;

    return 0;
}
