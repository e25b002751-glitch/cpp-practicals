#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    // Private data members cannot be accessed directly outside the class
    string accountHolder;
    int accountNumber;
    double balance;

public:
    // Constructor to initialize account details
    BankAccount(string name, int number, double initialBalance)
    {
        accountHolder = name;
        accountNumber = number;
        balance = (initialBalance >= 0) ? initialBalance : 0;
    }

    // Public member function to display account details
    void displayDetails()
    {
        cout << "\nAccount Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    // Public member function to deposit money
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successful: Rs. " << amount << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Public member function to withdraw money
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful: Rs. " << amount << endl;
        }
        else
        {
            cout << "Insufficient balance or invalid amount!" << endl;
        }
    }
};

int main()
{
    // Creating two objects of BankAccount class
    BankAccount account1("Shreya", 101, 5000);
    BankAccount account2("Rahul", 102, 3000);

    cout << "===== ACCOUNT 1 =====" << endl;
    account1.displayDetails();
    account1.deposit(1000);
    account1.withdraw(500);
    account1.displayDetails();

    cout << "\n===== ACCOUNT 2 =====" << endl;
    account2.displayDetails();
    account2.deposit(500);
    account2.withdraw(1000);
    account2.displayDetails();

    return 0;
}
