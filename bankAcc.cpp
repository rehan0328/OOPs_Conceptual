#include <iostream>
#include <string>
using namespace std;

class BankAccount {
     private:
    string accHolder;
    long long accNumber;
    double balance;
     public:
    // Constructor
    BankAccount(string name, long long accNo, double initialBalance) {
        accHolder = name;
        accNumber = accNo;
        balance = initialBalance;
    }
    // Deposit money
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount.\n";
            return;
        }

        balance += amount;
        cout << "₹" << amount << " deposited successfully.\n";
    }
    // Withdraw money
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
        }
        else if (amount > balance) {
            cout << "Insufficient balance.\n";
        }
        else {
            balance -= amount;
            cout << "₹" << amount << " withdrawn successfully.\n";
        }
    }
    // Display account details
    void displayAccount() {
        cout << "\n----- Account Details -----\n";
        cout << "Account Holder : " << accHolder << endl;
        cout << "Account Number : " << accNumber << endl;
        cout << "Balance        : ₹" << balance << endl;
    }
};

int main() {

    BankAccount account("Md Rehan Fazal", 1234567890, 10000);
     account.displayAccount();
     account.deposit(5000);
     account.withdraw(2500);
     account.displayAccount();

    return 0;
}