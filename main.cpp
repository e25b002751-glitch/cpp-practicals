#include <iostream>
using namespace std;

int main() {
    // Variables and data types
    int num1, num2;
    float average;
    char grade = 'A';
    bool isPositive;

    // Constant
    const int BONUS = 5;

    // Input
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    // Arithmetic operators
    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    float averageValue = (num1 + num2) / 2.0 + BONUS;

    // Relational and logical operators
    isPositive = (sum > 0 && num1 > 0 && num2 > 0);

    // Output
    cout << "\n--- C++ Fundamentals ---" << endl;
    cout << "First number: " << num1 << endl;
    cout << "Second number: " << num2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;
    cout << "Average with bonus: " << averageValue << endl;
    cout << "Grade constant: " << grade << endl;
    cout << "Bonus constant: " << BONUS << endl;
    cout << "Both numbers are positive: "
         << (isPositive ? "Yes" : "No") << endl;

    return 0;
}
