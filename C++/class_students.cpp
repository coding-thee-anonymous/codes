#include <iostream>
#include <string>
using namespace std;

class students
{
private:
    string name;
    int registrationNumber;
    float marks;
public:
    void inputDetails()
    {
        cout << "Enter student name: ";
        getline(cin, name);   
        cout << "Enter registration number: ";
        cin >> registrationNumber;   
        cout << "Enter marks: ";
        cin >> marks; 
        cin.ignore();
    }
    void displayDetails()
    {
        cout << "\n--- Student Details ---" << endl;
        cout << "Name: " << name << endl;
        cout << "Registration Number: " << registrationNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};
int main()
{
    students student1;
    cout << "Enter Student Information:" << endl;
    student1.inputDetails();
    student1.displayDetails();
    
    return 0;
}
