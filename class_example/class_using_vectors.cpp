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
        void addtoVec (vector<item> &list_of_items, string str) { //setter
            item tmp;
            istringstream iss (str);
            while (iss >> tmp.id >> tmp.name >> tmp.price >> tmp.qtyInStock) {
                list_of_items.push_back(tmp);      
            }
        }
};

int main () {
    vector<item> list_of_items;
    item tmp;
    // this code reads the txt into a vector
    ifstream ifs ("myStock.txt");
    while (ifs >> tmp.id >> tmp.name >> tmp.price >> tmp.qtyInStock) {
        list_of_items.push_back(tmp);      
    }
    // this create a deepcopy    
    vector<item> backup_copy(list_of_items);
    string line;
    item temp;
    while (getline(cin, line)) {
        if (line == "q") {break;}
        temp.addtoVec(list_of_items, line);
    }
    for (auto i : list_of_items) {
        cout << i.id << " " << i.name << " " << i.price << " " << i.qtyInStock << endl;
    }
    cout << "backup copy size: " << backup_copy.size() << endl;
}
