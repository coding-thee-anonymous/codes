#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
double computeAverage(int scores[], int size);
char assignGrade(int score);
void displaySummary(string names[], int scores[], int size);

int main()
{
    string names[100];
    int scores[100];
    int count = 0;
    string studentName;
    int score;
    
    cout << "Enter student names and scores (0-100)" << endl;
    cout << "Type 'END' as student name to stop input" << endl;
        while (true) {
        cout << "Enter student name: ";
        cin >> studentName;
                if (studentName == "END" || studentName == "end") {
            break;
        }
                cout << "Enter score (0-100): ";
        cin >> score;
        
        while (score < 0 || score > 100) {
            cout << "Invalid score! Please enter a score between 0 and 100: ";
            cin >> score;
        }
        
        names[count] = studentName;
        scores[count] = score;
        count++;
        
        if (count >= 100) {
            cout << "Maximum number of students reached!" << endl;
            break;
        }
    }
    
    if (count == 0) {
        cout << "\nNo student data entered!" << endl;
        return 0;
    }
        displaySummary(names, scores, count);
        double average = computeAverage(scores, count);
    cout << "\nClass Average: " << fixed << setprecision(2) << average << " %" << endl;
        int highestScore = *max_element(scores, scores + count);
    int lowestScore = *min_element(scores, scores + count);
    
    cout << "Highest Score: " << highestScore << " %" << endl;
    cout << "Lowest Score: " << lowestScore << " %" << endl;
    
    return 0;
}

double computeAverage(int scores[], int size)
{
    if (size == 0) return 0;
    
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    
    return (double)sum / size;
}

char assignGrade(int score)
{
    if (score >= 70)
        return 'A';
    else if (score >= 60)
        return 'B';
    else if (score >= 50)
        return 'C';
    else if (score >= 40)
        return 'D';
    else
        return 'F';
}

void displaySummary(string names[], int scores[], int size)
{
    cout << "\n" << setw(20) << "Student Name" << setw(15) << "Score" << setw(10) << "Grade" << endl;
    
    for (int i = 0; i < size; i++) {
        char grade = assignGrade(scores[i]);
        cout << setw(20) << names[i] << setw(15) << scores[i] << setw(10) << grade << endl;
    }
}
