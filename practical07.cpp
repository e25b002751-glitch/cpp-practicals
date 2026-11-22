#include <iostream>
using namespace std;

// Function overloading
int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}

// Complex Number class
class Complex
{
private:
    float real, imag;

public:
    // Constructor
    Complex(float r = 0, float i = 0)
    {
        real = r;
        imag = i;
    }

    // Operator overloading (+)
    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.imag = imag + c.imag;
        return temp;
    }

    // Display function
    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    // Function overloading
    cout << "--- Function Overloading ---" << endl;
    cout << "Addition of integers: " << add(10, 20) << endl;
    cout << "Addition of doubles: " << add(5.5, 2.5) << endl;

    // Operator overloading
    cout << "\n--- Operator Overloading ---" << endl;

    Complex c1(3, 4);
    Complex c2(2, 5);

    cout << "First complex number: ";
    c1.display();

    cout << "Second complex number: ";
    c2.display();

    Complex c3 = c1 + c2;

    cout << "Sum of complex numbers: ";
    c3.display();

    return 0;
}
