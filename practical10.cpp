#include <iostream>
#include <exception>
using namespace std;

// Custom exception for invalid amount
class InvalidAmount : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Invalid amount! Amount must be greater than zero.";
    }
};

// Custom exception for insufficient balance
class InsufficientFunds : public exception
{
public:
    const char* what() const noexcept override
    {
        return "Insufficient funds! Withdrawal exceeds balance.";
    }
};

// BankAccount class
class BankAccount
{
private:
    double balance;

public:
    BankAccount(double b)
    {
        balance = b;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
            throw InvalidAmount();

        if (amount > balance)
            throw InsufficientFunds();

        balance -= amount;
        cout << "Withdrawal successful: Rs. " << amount << endl;
    }

    void displayBalance()
    {
        cout << "Current Balance: Rs. " << balance << endl;
    }
};

int main()
{
    BankAccount account(5000);

    cout << "--- Banking Transaction ---" << endl;
    account.displayBalance();

    // Successful transaction
    try
    {
        account.withdraw(1000);
        account.displayBalance();
    }
    catch (InvalidAmount& e)
    {
        cout << e.what() << endl;
    }
    catch (InsufficientFunds& e)
    {
        cout << e.what() << endl;
    }

    // Insufficient funds transaction
    try
    {
        account.withdraw(6000);
    }
    catch (InvalidAmount& e)
    {
        cout << e.what() << endl;
    }
    catch (InsufficientFunds& e)
    {
        cout << e.what() << endl;
    }

    account.displayBalance();

    // Invalid amount transaction
    try
    {
        account.withdraw(-500);
    }
    catch (InvalidAmount& e)
    {
        cout << e.what() << endl;
    }
    catch (InsufficientFunds& e)
    {
        cout << e.what() << endl;
    }

    account.displayBalance();

    return 0;
}
