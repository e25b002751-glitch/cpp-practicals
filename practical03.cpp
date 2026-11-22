#include <iostream>
#include <utility>
using namespace std;

class DynamicArray
{
private:
    int* data;
    int size;

public:
    // Default constructor
    DynamicArray()
    {
        data = nullptr;
        size = 0;
        cout << "Default constructor called" << endl;
    }

    // Parameterized constructor
    DynamicArray(int n, int value)
    {
        size = n;
        data = new int[size];

        for (int i = 0; i < size; i++)
        {
            data[i] = value;
        }

        cout << "Parameterized constructor called" << endl;
    }

    // Rule of Five - 1: Destructor
    // Releases dynamically allocated memory.
    ~DynamicArray()
    {
        delete[] data;
        cout << "Destructor called" << endl;
    }

    // Rule of Five - 2: Copy constructor
    // Creates a deep copy of another object.
    DynamicArray(const DynamicArray& other)
    {
        size = other.size;
        data = (size > 0) ? new int[size] : nullptr;

        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }

        cout << "Copy constructor called" << endl;
    }

    // Rule of Five - 3: Copy assignment operator
    // Copies data safely into an existing object.
    DynamicArray& operator=(const DynamicArray& other)
    {
        if (this != &other)
        {
            delete[] data;

            size = other.size;
            data = (size > 0) ? new int[size] : nullptr;

            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }

        cout << "Copy assignment called" << endl;
        return *this;
    }

    // Rule of Five - 4: Move constructor
    // Transfers ownership of memory from another object.
    DynamicArray(DynamicArray&& other) noexcept
    {
        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;

        cout << "Move constructor called" << endl;
    }

    // Rule of Five - 5: Move assignment operator
    // Releases old memory and takes ownership of another object's data.
    DynamicArray& operator=(DynamicArray&& other) noexcept
    {
        if (this != &other)
        {
            delete[] data;

            data = other.data;
            size = other.size;

            other.data = nullptr;
            other.size = 0;
        }

        cout << "Move assignment called" << endl;
        return *this;
    }

    // Display array contents
    void display()
    {
        cout << "Array elements: ";

        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    cout << "--- Default Constructor ---" << endl;
    DynamicArray arr1;

    cout << "\n--- Parameterized Constructor ---" << endl;
    DynamicArray arr2(5, 10);
    arr2.display();

    cout << "\n--- Copy Constructor ---" << endl;
    DynamicArray arr3(arr2);
    arr3.display();

    cout << "\n--- Copy Assignment ---" << endl;
    arr1 = arr2;
    arr1.display();

    cout << "\n--- Move Constructor ---" << endl;
    DynamicArray arr4(move(arr2));
    arr4.display();

    cout << "\n--- Move Assignment ---" << endl;
    DynamicArray arr5;
    arr5 = move(arr3);
    arr5.display();

    cout << "\nProgram completed successfully." << endl;

    return 0;
}
