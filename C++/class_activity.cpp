#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    int sum = 0;
    
    cout << "Enter 5 elements:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Element " << i+1 << ": ";
        cin >> arr[i];
        sum += arr[i];
    }
    
    cout << "\nSum of all elements: " << sum << endl;
    
    return 0;
}
