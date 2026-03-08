#include <iostream>
using namespace std;

// Global variables
int num1, num2;

int main()
{
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    
    int sum = num1 + num2;
   // cout << "Number 1: " << num1 << endl;
    //cout << "Number 2: " << num2 << endl;
    cout << "Sum: " << sum << endl;
    return 0;
}
