#include <iostream>
using namespace std;

int main()
{
    int marks;
    char grade;
    
    cout << "Enter marks: ";
    cin >> marks;
    
    if (marks < 0 || marks > 100) {
        cout << "Marks must be between 0 and 100" << endl;
        return 0;
    }
    
    int gradeValue = marks / 10;
    
    switch (gradeValue) {
        case 10:
        case 7:
            grade = 'A';
            break;
        case 6:
            grade = 'B';
            break;
        case 5:
            grade = 'C';
            break;
        case 4:
            grade = 'D';
            break;
        case 3:
        case 2:
        case 1:
            grade = 'E';
            break;
        default:
            grade = 'F';
            break;
    }
    
    cout << "Grade: " << grade << endl;
    
    return 0;
}
