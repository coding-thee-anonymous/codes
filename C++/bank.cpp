#include <iostream>
using namespace std;

class Bank
{
private:
    int accountNumber;
    double balance;

public:
    Bank(int accNum, double initialBalance)
    {
        accountNumber = accNum;
        balance = initialBalance;
    }
    
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited: " << amount << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }
    
    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Withdrawal amount exceeds balance!" << endl;
        }
        else if (amount > 0)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }
    
    void displayBalance()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main()
{
    Bank account1(101, 5000);
    
    cout << "--- Initial Balance ---" << endl;
    account1.displayBalance();
    
    cout << "\n--- Deposit 1500 ---" << endl;
    account1.deposit(1500);
    account1.displayBalance();
    
    cout << "\n--- Withdraw 2000 ---" << endl;
    account1.withdraw(2000);
    account1.displayBalance();
    
    cout << "\n--- Try to withdraw 10000 (exceeds balance) ---" << endl;
    account1.withdraw(10000);
    account1.displayBalance();
    
    return 0;
}
