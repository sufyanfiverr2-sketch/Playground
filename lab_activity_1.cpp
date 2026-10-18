#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Person {
    string name;
    int age;
    float salary;
};

int main() {
    Person p;

    // Input name
    cout << "Enter name: ";
    getline(cin, p.name);

    // Input age with exception handling
    while (true) {
        try {
            cout << "Enter age: ";
            cin >> p.age;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid input! Please enter a numeric value.");
            }
            if (p.age <= 0) {
                throw out_of_range("Age cannot be zero or negative.");
            }
            if (p.age > 150) {
                throw out_of_range("Age cannot be greater than 150.");
            }
            break;  // valid input, exit loop
        }
        catch (const invalid_argument &e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (const out_of_range &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    // Input salary with exception handling
    while (true) {
        try {
            cout << "Enter salary: ";
            cin >> p.salary;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid input! Please enter a numeric value.");
            }
            if (p.salary < 0) {
                throw out_of_range("Salary cannot be negative.");
            }
            break;  // valid input, exit loop
        }
        catch (const invalid_argument &e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (const out_of_range &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    // Display the data
    cout << "\n--- Person Details ---" << endl;
    cout << "Name   : " << p.name << endl;
    cout << "Age    : " << p.age << endl;
    cout << "Salary : " << p.salary << endl;

    return 0;
}
