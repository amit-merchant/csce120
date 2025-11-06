#include <iostream>
using std::cout, std::cin, std::endl;

class dynArr {
private:
    int* data;
    int size;

public:
    // Constructor
    dynArr(int s) : size(s) {
        data = new int[size];
        // cout << "Constructor: Allocated " << size << " integers\n";
    }

    // Destructor (Rule of 3 - part 1)
    ~dynArr() {
        delete[] data;
        // cout << "Destructor: Freed memory\n";
    }

    // Copy Constructor (Rule of 3 - part 2)
    dynArr(const dynArr& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
        cout << "Deep Copy Constructor: Created copy of size " << size << "\n";
    }

    // Copy Assignment Operator (Rule of 3 - part 3)
    dynArr& operator=(const dynArr& other) {
        if (this != &other) {
            delete[] data;  // Free existing memory
            size = other.size;
            data = new int[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
            cout << "Copy Assignment: Assigned copy of size " << size << "\n";
        }
        return *this;
    }

    // setter
    void setValue(int index, int value) {
        if (index >= 0 && index < size) {
            data[index] = value;
        }
    }

    // getter
    int getValue(int index) const {
        if (index >= 0 && index < size) {
            return data[index];
        }
        return -1;
    }

    // Helper method to print array
    void print() const {
        cout << "Array contents: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    cout << "Create arr1 \n";
    dynArr arr1(3);
    arr1.setValue(0, 10);
    arr1.setValue(1, 20);
    arr1.setValue(2, 30);
    arr1.print();

    cout << "\nCopy Constructor (arr2 = arr1) \n";
    dynArr arr2(arr1);  // Copy constructor
    arr2.print();

    cout << "\nModifying arr1 \n";
    arr1.setValue(0, 99);
    arr1.setValue(1, 99);
    arr1.setValue(2, 99);

    arr1.print();
    cout << "arr2 (should be unchanged, 10, 20, 30): ";
    arr2.print();

    dynArr arr3(2);
    arr3.setValue(0, 77);
    arr3.setValue(1, 78);
    arr3.print();

    arr1 = arr3;
    arr1.print();

    // cout << "\n Exiting main, destructors will be called \n";
    return 0;
}
