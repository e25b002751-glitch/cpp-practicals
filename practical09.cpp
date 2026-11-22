#include <iostream>
#include <stack>
#include <string>
using namespace std;

template <class T>
class Stack
{
private:
    stack<T> s;

public:
    void push(T value)
    {
        s.push(value);
        cout << value << " pushed" << endl;
    }

    void pop()
    {
        if (s.empty())
        {
            cout << "Stack is empty!" << endl;
        }
        else
        {
            cout << s.top() << " popped" << endl;
            s.pop();
        }
    }

    void peek()
    {
        if (s.empty())
            cout << "Stack is empty!" << endl;
        else
            cout << "Top element: " << s.top() << endl;
    }

    bool isEmpty()
    {
        return s.empty();
    }
};

int main()
{
    cout << "--- Integer Stack ---" << endl;
    Stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.peek();
    s1.pop();

    cout << "\n--- Float Stack ---" << endl;
    Stack<float> s2;
    s2.push(10.5);
    s2.push(20.5);
    s2.peek();
    s2.pop();

    cout << "\n--- String Stack ---" << endl;
    Stack<string> s3;
    s3.push("Hello");
    s3.push("World");
    s3.peek();
    s3.pop();

    cout << "\n--- Empty Stack Test ---" << endl;
    Stack<int> s4;
    s4.pop();

    return 0;
}
