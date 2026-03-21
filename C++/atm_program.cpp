#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Account {
    string name;
    int id;
    string pin;
    double balance;
};

vector<Account> accounts;
Account* currentUser = nullptr;

bool accountExists(int id) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].id == id) {
            return true;
        }
    }
    return false;
}

Account* findAccount(int id) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].id == id) {
            return &accounts[i];
        }
    }
    return nullptr;
}

void createAccount() {
    Account newAccount;
    cin.ignore();
    
    cout << "\n--- Create New Account ---" << endl;
    bool validName = false;
    while (!validName) {
        cout << "Enter your name: ";
        getline(cin, newAccount.name);
        
        if (newAccount.name.empty()) {
            cout << "Invalid input! Name cannot be empty." << endl;
            continue;
        }
        
        bool isNumeric = true;
        for (char c : newAccount.name) {
            if (!isdigit(c) && !isspace(c)) {
                isNumeric = false;
                break;
            }
        }
        
        if (isNumeric && !newAccount.name.empty() && newAccount.name.find_first_not_of(" ") != string::npos) {
            cout << "Invalid input! Name should contain letters, not just numbers." << endl;
        } else {
            validName = true;
        }
    }
    
    bool validID = false;
    while (!validID) {
        cout << "Enter your ID: ";
        if (!(cin >> newAccount.id)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter an integer." << endl;
            continue;
        }
        validID = true;
    }
    
    if (accountExists(newAccount.id)) {
        cout << "Account with this ID already exists!" << endl;
        return;
    }
    
    cin.ignore();
    bool validPIN = false;
    while (!validPIN) {
        cout << "Create a PIN: ";
        getline(cin, newAccount.pin);
        
        if (newAccount.pin.empty()) {
            cout << "Invalid input! PIN cannot be empty." << endl;
            continue;
        }
        
        bool isNumeric = true;
        for (char c : newAccount.pin) {
            if (!isdigit(c)) {
                isNumeric = false;
                break;
            }
        }
        
        if (!isNumeric) {
            cout << "Invalid input! PIN should contain only numbers." << endl;
        } else {
            validPIN = true;
        }
    }
    
    newAccount.balance = 0.0;
    accounts.push_back(newAccount);
    cout << "Account created successfully! Welcome, " << newAccount.name << endl;
}

bool login() {
    int id;
    string pin;
    
    cout << "\n--- Login ---" << endl;
    bool validID = false;
    while (!validID) {
        cout << "Enter your ID: ";
        if (!(cin >> id)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter an integer." << endl;
            continue;
        }
        validID = true;
    }
    
    Account* user = findAccount(id);
    if (user == nullptr) {
        cout << "Account not found!" << endl;
        return false;
    }
    
    cin.ignore();
    bool validPIN = false;
    while (!validPIN) {
        cout << "Enter your PIN: ";
        getline(cin, pin);
        
        if (pin.empty()) {
            cout << "Invalid input! PIN cannot be empty." << endl;
            continue;
        }
        
        bool isNumeric = true;
        for (char c : pin) {
            if (!isdigit(c)) {
                isNumeric = false;
                break;
            }
        }
        
        if (!isNumeric) {
            cout << "Invalid input! PIN should contain only numbers." << endl;
        } else {
            validPIN = true;
        }
    }
    
    if (user->pin == pin) {
        currentUser = user;
        cout << "Login successful! Welcome, " << currentUser->name << endl;
        return true;
    } else {
        cout << "Invalid PIN!" << endl;
        return false;
    }
}

void checkBalance() {
    cout << "Your balance: Ksh" << currentUser->balance << endl;
}

void deposit() {
    double amount;
    bool validAmount = false;
    while (!validAmount) {
        cout << "Enter amount to deposit: ";
        if (!(cin >> amount)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        validAmount = true;
    }
    
    if (amount > 0) {
        currentUser->balance += amount;
        cout << "Deposit successful! New balance: Ksh" << currentUser->balance << endl;
    } else {
        cout << "Invalid amount!" << endl;
    }
}

void withdraw() {
    double amount;
    bool validAmount = false;
    while (!validAmount) {
        cout << "Enter amount to withdraw: ";
        if (!(cin >> amount)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        validAmount = true;
    }
    
    if (amount > 0 && amount <= currentUser->balance) {
        currentUser->balance -= amount;
        cout << "Withdrawal successful! New balance: Ksh" << currentUser->balance << endl;
    } else if (amount > currentUser->balance) {
        cout << "Insufficient funds! Your balance: Ksh" << currentUser->balance << endl;
    } else {
        cout << "Invalid amount!" << endl;
    }
}

int main() {
    int choice;

    while (true) {
        if (currentUser == nullptr) {
            cout << "\n      ATM SYSTEM      " << endl;
            cout << "1. Create Account" << endl;
            cout << "2. Login" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter choice: ";
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Please enter an integer." << endl;
                continue;
            }

            if (choice == 1) {
                createAccount();
            } 
            else if (choice == 2) {
                if (login()) {
                    // Successfully logged in
                }
            } 
            else if (choice == 3) {
                cout << "Thank you for using ATM. Goodbye!" << endl;
                break;
            } 
            else {
                cout << "Invalid choice!" << endl;
            }
        } 
        else {
            cout << "\n----- ATM MENU -----" << endl;
            cout << "1. Check Balance" << endl;
            cout << "2. Deposit" << endl;
            cout << "3. Withdraw" << endl;
            cout << "4. Logout" << endl;
            cout << "Enter choice: ";
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Please enter an integer." << endl;
                continue;
            }

            if (choice == 1) {
                checkBalance();
            } 
            else if (choice == 2) {
                deposit();
            } 
            else if (choice == 3) {
                withdraw();
            } 
            else if (choice == 4) {
                cout << "Logout successful. Thank you!" << endl;
                currentUser = nullptr;
            } 
            else {
                cout << "Invalid choice!" << endl;
            }
        }
    }

    return 0;
}
