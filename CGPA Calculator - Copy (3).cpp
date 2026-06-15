#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    float grade, credit;
    float totalCredits = 0, totalGradePoints = 0;

    cout << "===== CGPA Calculator =====\n";
    cout << "Enter the number of courses: ";
    cin >> n;

    float grades[n], credits[n];

    // Input course details
    for (int i = 0; i < n; i++)
    {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter Grade Point: ";
        cin >> grades[i];

        cout << "Enter Credit Hours: ";
        cin >> credits[i];

        totalCredits += credits[i];
        totalGradePoints += grades[i] * credits[i];
    }

    // Calculate CGPA
    float cgpa = totalGradePoints / totalCredits;

    // Display course details
    cout << "\n===== Course Details =====\n";
    cout << "Course\tGrade\tCredits\n";

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t"
             << grades[i] << "\t"
             << credits[i] << endl;
    }

    // Display result
    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << fixed << setprecision(2);
    cout << "Final CGPA: " << cgpa << endl;

    return 0;
}