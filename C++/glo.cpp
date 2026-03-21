#include <iostream>
#include <string>
#include <iomanip> // For the table layout

using namespace std;

// 1. ALL FUNCTIONS MUST BE ABOVE MAIN
char assigngrade(int score) {
    if(score >= 70) return 'A';
    if(score >= 60) return 'B';
    if(score >= 50) return 'C';
    if(score >= 40) return 'D';
    return 'F';
}

void displaysummary(string names[], int scores[], int total) {
    cout << "\n--- FINAL REPORT ---" << endl;
    cout << left << setw(20) << "NAME" << setw(10) << "SCORE" << "GRADE" << endl;

    for(int i = 0; i < total; i++) {
        cout << left << setw(20) << names[i]
             << setw(10) << scores[i]
             << assigngrade(scores[i]) << endl;
    }
}

// 2. MAIN RUNS LAST
int main() {
    string studentnames[100];
    int scores[100];
    int count = 0;
    string input;

    cout << "Type student names. Type 'end' to see the table.\n";

    while(count < 100) {
        cout << "Name: ";
        getline(cin >> ws, input); // 'ws' clears the "Enter" key traffic jam

        if(input == "end" || input == "END") break;

        studentnames[count] = input;

        cout << "Score: ";
        cin >> scores[count];

        count++;
    }

    // This checks if we actually have data to show
    if(count > 0) {
        displaysummary(studentnames, scores, count);
    } else {
        cout << "No data entered!";
    }

    return 0;
}