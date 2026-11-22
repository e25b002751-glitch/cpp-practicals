#include <iostream>
#include <memory>
using namespace std;

// A simple class to demonstrate smart pointers
class Resource
{
public:
    Resource(string name)
    {
        cout << name << " created" << endl;
    }

    ~Resource()
    {
        cout << "Resource destroyed" << endl;
    }

    void show()
    {
        cout << "Resource is being used." << endl;
    }
};

int main()
{
    // Example 1: Raw pointer
    cout << "--- Raw Pointer ---" << endl;
    Resource* raw = new Resource("Raw resource");
    raw->show();
    delete raw;  // Manual memory release

    // Example 2: unique_ptr
    cout << "\n--- unique_ptr ---" << endl;
    {
        unique_ptr<Resource> ptr1(new Resource("Unique resource"));
        ptr1->show();

        // unique_ptr has only one owner
        cout << "unique_ptr has single ownership." << endl;
    } // Automatically destroyed here

    // Example 3: unique_ptr array
    cout << "\n--- unique_ptr Array ---" << endl;
    {
        unique_ptr<int[]> numbers(new int[5]);

        for (int i = 0; i < 5; i++)
        {
            numbers[i] = (i + 1) * 10;
        }

        cout << "Array values: ";
        for (int i = 0; i < 5; i++)
        {
            cout << numbers[i] << " ";
        }
        cout << endl;
    } // Array memory is automatically released

    // Example 4: shared_ptr
    cout << "\n--- shared_ptr ---" << endl;
    {
        shared_ptr<Resource> ptrA = make_shared<Resource>("Shared resource");

        {
            shared_ptr<Resource> ptrB = ptrA;

            cout << "Ownership count: " << ptrA.use_count() << endl;

            ptrA->show();
            ptrB->show();
        }

        cout << "Ownership count after ptrB scope: "
             << ptrA.use_count() << endl;
    } // Resource destroyed when the last shared_ptr is gone

    // Example 5: Many iterations
    cout << "\n--- Repeated Allocation Test ---" << endl;

    for (int i = 0; i < 1000; i++)
    {
        unique_ptr<int> p = make_unique<int>(i);
        shared_ptr<int> s = make_shared<int>(i);
    }

    cout << "1000 iterations completed successfully." << endl;

    cout << "\nProgram completed successfully." << endl;

    return 0;
}
