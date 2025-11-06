#include <iostream>
#include <vector>
using std::cout; 

class vec {
private:
    std::vector<int> data;

public:    
    vec() {} // Constructor

    // Constructor with initial values, using initialization list
    vec(const std::vector<int>& values) : data(values) {}

    ~vec() {}     // Destructor (Rule of 3)

    vec(const vec& other) : data(other.data) {} // Copy Constructor (Rule of 3)

    vec& operator=(const vec& other) { // Copy Assignment Operator (Rule of 3 - part 3)
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }

    void add(int value) {// Add value to vector
        data.push_back(value);
    }

    // Replace all occurrences of oldValue with newValue
    void replaceAll(int oldValue, int newValue) {
        for (size_t i = 0; i < data.size(); i++) {
            if (data[i] == oldValue) {
                data[i] = newValue;
            }
        }
        cout << "Replaced all occurrence(s) of " << oldValue 
                  << " with " << newValue << "\n";
    }

    void print() const {     // Print vector contents
        cout << "Vector contents: ";
        for (size_t i = 0; i < data.size(); i++) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }

    size_t getSize() const {     // Get size
        return data.size();
    }
};

int main() {
    cout << "Creating vec1\n";
    vec vec1({5, 2, 5, 8, 2, 5, 1});
    vec1.print();

    cout << "\nCopy Constructor (vec2 = vec1)\n";
    vec vec2 = vec1;  // Copy constructor
    vec2.print();

    cout << "\nUsing replaceAll on vec1 (replace 5 with 99)\n";
    vec1.replaceAll(5, 99);
    vec1.print();
    cout << "vec2 (should be unchanged): ";
    vec2.print();

    cout << "\nCreating vec3\n";
    vec vec3;
    vec3.add(10);
    vec3.add(20);
    vec3.add(10);
    vec3.print();

    cout << "\nCopy Assignment (vec3 = vec1)\n";
    vec3 = vec1;  // Copy assignment operator
    vec3.print();

    cout << "\nUsing replaceAll on vec3 (replace 99 with 777)\n";
    vec3.replaceAll(99, 777);
    vec3.print();
    cout << "vec1 (should be unchanged): ";
    vec1.print();

    cout << "\nDestructors called\n";
    return 0;
}
