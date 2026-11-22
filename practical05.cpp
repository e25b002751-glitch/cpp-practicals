#include <iostream>
#include <string>
using namespace std;

// Base class
class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a)
    {
        name = n;
        age = a;
    }

    void displayPerson()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived class (Single Inheritance)
class Student : public Person
{
protected:
    int studentID;
    string course;

public:
    Student(string n, int a, int id, string c)
        : Person(n, a)
    {
        studentID = id;
        course = c;
    }

    void displayStudent()
    {
        displayPerson();
        cout << "Student ID: " << studentID << endl;
        cout << "Course: " << course << endl;
    }
};

// Derived class (Multilevel Inheritance)
class GraduateStudent : public Student
{
private:
    string researchTopic;
    string supervisor;

public:
    GraduateStudent(string n, int a, int id, string c,
                   string topic, string sup)
        : Student(n, a, id, c)
    {
        researchTopic = topic;
        supervisor = sup;
    }

    void displayGraduateStudent()
    {
        displayStudent();
        cout << "Research Topic: " << researchTopic << endl;
        cout << "Supervisor: " << supervisor << endl;
    }
};

int main()
{
    // Student object
    cout << "===== STUDENT DETAILS =====" << endl;
    Student s1("Shreya", 19, 101, "BTech Computer Science");
    s1.displayStudent();

    // GraduateStudent object
    cout << "\n===== GRADUATE STUDENT DETAILS =====" << endl;
    GraduateStudent g1("Rahul", 23, 201, "MTech Computer Science",
                      "Artificial Intelligence", "Dr. Sharma");
    g1.displayGraduateStudent();

    return 0;
}
