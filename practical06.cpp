#include <iostream>
using namespace std;

// Abstract base class
class Shape
{
public:
    // Pure virtual function
    virtual double area() = 0;

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }

    double area() override
    {
        return 3.14 * radius * radius;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape
{
private:
    double length, breadth;

public:
    Rectangle(double l, double b)
    {
        length = l;
        breadth = b;
    }

    double area() override
    {
        return length * breadth;
    }
};

// Derived class: Triangle
class Triangle : public Shape
{
private:
    double base, height;

public:
    Triangle(double b, double h)
    {
        base = b;
        height = h;
    }

    double area() override
    {
        return 0.5 * base * height;
    }
};

// Main function
int main()
{
    Circle c(5);
    Rectangle r(4, 6);
    Triangle t(8, 5);

    // Base class pointers
    Shape* ptr;

    cout << "--- Area Calculation ---" << endl;

    ptr = &c;
    cout << "Area of Circle: " << ptr->area() << endl;

    ptr = &r;
    cout << "Area of Rectangle: " << ptr->area() << endl;

    ptr = &t;
    cout << "Area of Triangle: " << ptr->area() << endl;

    return 0;
}
