#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Student
{
public:
    int id;
    string name;
    float marks;
};

int main()
{
    Student s[3] = {
        {101, "Shreya", 85.5},
        {102, "Rahul", 78.0},
        {103, "Aditi", 92.5}
    };

    // 1. Write student records to CSV
    ofstream fout("students.csv");

    if (!fout)
    {
        cout << "Error opening CSV file!" << endl;
        return 1;
    }

    fout << "ID,Name,Marks\n";

    for (int i = 0; i < 3; i++)
    {
        fout << s[i].id << "," << s[i].name << ","
             << s[i].marks << endl;
    }

    fout.close();
    cout << "Student records written successfully.\n\n";

    // 2. Read student records from CSV
    ifstream fin("students.csv");

    if (!fin)
    {
        cout << "Error reading CSV file!" << endl;
        return 1;
    }

    string line;
    cout << "--- Student Records ---\n";

    getline(fin, line); // Skip header

    while (getline(fin, line))
    {
        stringstream ss(line);
        string id, name, marks;

        if (getline(ss, id, ',') &&
            getline(ss, name, ',') &&
            getline(ss, marks, ','))
        {
            try
            {
                cout << "ID: " << stoi(id)
                     << " | Name: " << name
                     << " | Marks: " << stof(marks) << endl;
            }
            catch (...)
            {
                cout << "Invalid record: " << line << endl;
            }
        }
        else
        {
            cout << "Malformed record: " << line << endl;
        }
    }

    fin.close();

    // 3. Demonstrate tellp() and seekp()
    cout << "\n--- Write Position Demo ---\n";

    fstream file("position_demo.txt",
                 ios::out | ios::in | ios::trunc);

    file << "ABCDE";

    cout << "tellp(): " << file.tellp() << endl;

    file.seekp(2);
    cout << "After seekp(2), tellp(): " << file.tellp() << endl;

    file.put('X');
    file.close();

    // 4. Demonstrate tellg() and seekg()
    cout << "\n--- Read Position Demo ---\n";

    ifstream readFile("position_demo.txt");

    cout << "tellg(): " << readFile.tellg() << endl;

    readFile.seekg(2);
    cout << "After seekg(2), tellg(): " << readFile.tellg() << endl;

    char ch;
    readFile.get(ch);

    cout << "Character at position 2: " << ch << endl;
    readFile.close();

    // Display modified file
    ifstream display("position_demo.txt");
    string text;

    getline(display, text);
    cout << "Modified file content: " << text << endl;
    display.close();

    return 0;
}
