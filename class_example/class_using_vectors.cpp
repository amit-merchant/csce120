//This program reads a text file and creats a small invetory database
//It uses classes and follows the rule of 3
//You can also add an item in the format at the prompt
//id name price quantity
//use q to quit and print out the complete inventory
//to demonstrate copy constructor it creates a backup_copy
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
        int qtyInStock;
    public:
        item () {} // default constructor
        ~item () {} //destructor
        item (const item& object) { //copy constructor
            id = object.id;
            name = object.name;
            price = object.price;
            qtyInStock = object.qtyInStock;
        }
        item& operator=(const item& object) { //assignment constructor
            if (this != &object) { // Avoid self-assignment
                id = object.id;
                name = object.name;
                price = object.price;
                qtyInStock = object.qtyInStock;
            }
            return *this;
        }
};

// we create a class of vector if items because the original class of items
// cannot take the vector and some operations are best done on the vector
// especially search and modify
class vector_of_items { // class of vector of items
    public:
        vector<item> v_of_items;
    public:
        vector_of_items () {}
        ~vector_of_items () {} //destructor
        vector_of_items (const vector_of_items& object) { //copy constructor
            this->v_of_items = object.v_of_items;
        }
        vector_of_items& operator=(const vector_of_items& object) { //assignment constructor
            if (this != &object) { // Avoid self-assignment
                this->v_of_items = object.v_of_items;
            }
            return *this;
        }
        vector_of_items operator+(const item& object) { // adds new item to inventory
            vector_of_items result = *this;
            result.v_of_items.push_back(object);
            return result;
        }
        vector_of_items operator-(const item& object) { // decrements quantity by 1 
            vector_of_items result = *this;
            for (auto i = 0; i < result.v_of_items.size(); i++) {
                if (result.v_of_items[i].name == object.name) {
                    if (result.v_of_items[i].qtyInStock > 0) {
                        result.v_of_items[i].qtyInStock--;
                    }
                }
            }
            return result;           
        }
};


int main () {
    vector_of_items list_of_items;
    item tmp;
    // this code reads the txt into a vector
    ifstream ifs ("myStock.txt");
    while (ifs >> tmp.id >> tmp.name >> tmp.price >> tmp.qtyInStock) {
        list_of_items = list_of_items + tmp;      
    }
    cout << "Original Inventory: " << endl;
    for (auto i : list_of_items.v_of_items) {
        cout << i.id << " " << i.name << " " << i.price << " " << i.qtyInStock << endl;
    }
    // this create a deepcopy    
    vector<item> backup_copy(list_of_items.v_of_items);
    string line;
    item temp;
    while (getline(cin, line)) {
        if (line == "q") {break;}
        string str;
        item tmp;
        istringstream iss (line);
        while (iss >> str ) {
            if (str == "add") { 
                iss >> tmp.id >> tmp.name >> tmp.price >> tmp.qtyInStock;
                list_of_items = list_of_items + tmp;
            } // adds a new item to existing list
            if (str == "dec") { 
                iss >> tmp.name;
                list_of_items = list_of_items - tmp;
            } // decreases quantity by one, requires a partially populated object
        }
    }
    cout << "Inventory after transactions: " << endl;
    for (auto i : list_of_items.v_of_items) {
        cout << i.id << " " << i.name << " " << i.price << " " << i.qtyInStock << endl;
    }
    // cout << "backup copy size: " << backup_copy.size() << endl;
}
