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
    
    if (marks >= 70 && marks <= 100)
        grade = 'A';
    else if (marks >= 60 && marks < 70)
        grade = 'B';
    else if (marks >= 50 && marks < 60)
        grade = 'C';
    else if (marks >= 40 && marks < 50)
        grade = 'D';
    else if (marks >= 0 && marks < 40)
        grade = 'E';
    
    cout  << "Grade: " << grade << endl;
    
    return 0;
}
