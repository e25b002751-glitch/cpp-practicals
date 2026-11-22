#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Base class
class Shape
{
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

// Derived class: Circle
class Circle : public Shape
{
public:
    void draw() override
    {
        cout << "Circle object created." << endl;
        cout << "Drawing a Circle." << endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape
{
public:
    void draw() override
    {
        cout << "Rectangle object created." << endl;
        cout << "Drawing a Rectangle." << endl;
    }
};

// Factory class
class ShapeFactory
{
public:
    static unique_ptr<Shape> createShape(string type)
    {
        if (type == "circle")
            return make_unique<Circle>();

        else if (type == "rectangle")
            return make_unique<Rectangle>();

        else
            return nullptr;
    }
};

// Main function
int main()
{
    cout << "--- Factory Design Pattern ---" << endl;

    // Factory creates Circle object
    unique_ptr<Shape> s1 = ShapeFactory::createShape("circle");

    if (s1)
        s1->draw();

    cout << endl;

    // Factory creates Rectangle object
    unique_ptr<Shape> s2 = ShapeFactory::createShape("rectangle");

    if (s2)
        s2->draw();

    return 0;
}
