#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class item{
    protected:
        int id;
        string name;
        float price;
        int qtyInStock;
    public:
        item () {} // default constructor
        item& operator=(const item& object) { //assignment constructor
            id = object.id;
            name = object.name;
            price = object.price;
            qtyInStock = object.qtyInStock;
            return *this;
        }
        item& assign(istream& is) { // to protect variables in item
            is >> id >> name >> price >> qtyInStock;
            return *this;
        }
        void print() const { // helper function
            cout << id << " " << name << " " << price << " " << qtyInStock << endl;
        }        
};

class vector_of_items : public item { // derived class
    public:
        vector<item> v_of_items;
    public:
        vector_of_items () {}
        vector_of_items& operator=(const vector_of_items& object) { 
                this->v_of_items = object.v_of_items;
            return *this;
        }
        vector_of_items operator+(const item& object) { // adds new item to inventory
            vector_of_items result = *this;
            result.v_of_items.push_back(object);
            return result;
        }
};

int main () {
    string line;
    vector_of_items list_of_items;
    item tmp;
    ifstream ifs ("myStock.txt");
    while (getline(ifs, line)) { // this code reads the txt into a vector
        if (line.empty()) continue;
        istringstream iss(line);
        tmp.assign(iss); //assigns each line to tmp
        // list_of_items = list_of_items + tmp; //invokes operator+ overload
        list_of_items.v_of_items.push_back(tmp); //builds the list_of_items
    }
    cout << "Inventory is: " << endl;
    for (const auto& it : list_of_items.v_of_items) {
        it.print();
    }
}