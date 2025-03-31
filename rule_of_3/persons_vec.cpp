#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person {
private:
    string* name;
    int* age;

public:
    // Default Constructor
    Person() {
        cout << "Default Constructor called" << endl;
        name = new string("");
        age = new int(0);
    }

    // Constructor
    Person(const string& n, int a) {
        cout << "Constructor called for " << n << endl;
        name = new string(n);
        age = new int(a);
    }

    // Destructor
    ~Person() {
        cout << "Destructor called for " << *name << endl;
        delete name;
        delete age;
    }

    // Copy constructor
    Person(const Person& other) {
        cout << "Copy constructor called for " << *other.name << endl;
        name = new string(*other.name);
        age = new int(*other.age);
    }

    // Copy assignment operator
    Person& operator=(const Person& other) {
        cout << "Copy assignment operator called" << *other.name << endl;
        if (this != &other) {
            delete name;
            delete age;
            name = new string(*other.name);
            age = new int(*other.age);
        }
        return *this;
    }

    void display(Person& p) const {
        cout << "Name: " << *p.name << ", Age: " << *p.age << endl;
    }
};

int main() {
    vector<Person> people;
    people.push_back(Person("Ayoka",25));
    people.push_back(Person("Bob",24));
    cout << endl << "Displaying people:" << endl;
    for (auto i: people) {
        i.display(i);
    }

    return 0;  // Destructors are automatically called
}
