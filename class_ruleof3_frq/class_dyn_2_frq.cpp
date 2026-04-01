#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class item{
    public:
        int id;
        string name;
        float price;
    public:
        item () {} // default constructor
        ~item () {} //destructor
        item (const item& object) { //copy constructor
            id = object.id;
            name = object.name;
            price = object.price;
        }
        item& operator=(const item& object) { //assignment constructor
                id = object.id;
                name = object.name;
                price = object.price;
                return *this;
            }
    };

// TODO
void reallocate(int newCap, int& currCap, int& size, item*& array) {
    //doubles capacity
}

void print(int size, const item* array) {
    for (int i = 0; i < size; i++) {
        cout << array[i].id << " " << array[i].name << " " << array[i].price << " " << endl;
    }
}

// TODO
void addItem(item*& array, int& size, int& currCap, int id, const string& name, float price) {
}

int searchItem(const item* array, int size, int id) {
    for (int i = 0; i < size; ++i) {
        if (array[i].id == id) {
            return i;  // return index
        }
    }
    return -1; // not found
}

// TODO
bool deleteItem(item* array, int& size, int id) {
}

int main () {
    int size = 0;
    int currCap = 4;
    item* list = new item[currCap]; // create dynamic array of a class
    int i = 0;
    // this code reads the txt into an item
    // this construct allows the list to be of an indefinite size
    ifstream ifs ("mylist.txt");
    while (ifs >> list[i].id >> list[i].name >> list[i].price) {
        i++;
        size++;
        if (i == currCap) {
            int newCap = currCap*2;
            reallocate(newCap, currCap, size, list);
        }      
    }
    cout << "Original Inventory: " << endl;
    print(size, list);
    delete[] list;

    // interactive code for user to add/search/delete/print/exit
    string line;

    while (true) {
        cout << "\nChoose operation (add/search/delete/print/exit): ";
        getline(cin, line);

        if (line == "add") {
            cout << "Enter item (id name price): ";
            getline(cin, line);

            istringstream iss(line);
            int id;
            string name;
            float price;

            if (!(iss >> id >> name >> price)) {
                cout << "Invalid input\n";
                continue;
            }

            addItem(list, size, currCap, id, name, price);
        }

        else if (line == "search") {
            cout << "Enter id to search: ";
            getline(cin, line);

            int id = stoi(line);
            int idx = searchItem(list, size, id);

            if (idx != -1) {
                cout << "Found: "
                     << list[idx].id << " "
                     << list[idx].name << " "
                     << list[idx].price << endl;
            } else {
                cout << "Item not found\n";
            }
        }

        else if (line == "delete") {
            cout << "Enter id to delete: ";
            getline(cin, line);

            int id = stoi(line);

            if (deleteItem(list, size, id)) {
                cout << "Item deleted\n";
            } else {
                cout << "Item not found\n";
            }
        }

        else if (line == "print") {
            cout << "Inventory:\n";
            for (int i = 0; i < size; ++i) {
                cout << list[i].id << " "
                     << list[i].name << " "
                     << list[i].price << endl;
            }
        }

        else if (line == "exit") {
            break;
        }

        else {
            cout << "Unknown command\n";
        }

        // show inventory after each operation
        cout << "\nInventory after transaction:\n";
        for (int i = 0; i < size; ++i) {
            cout << list[i].id << " "
                 << list[i].name << " "
                 << list[i].price << endl;
        }
    }

    delete[] list;
    
}
