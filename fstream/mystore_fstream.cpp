#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

// read a file and create an internal database
int main () {
    struct item {
        int id;
        string name;
        float price;
        int qtyInStock;
    };
    vector<item> inventory;
    item tmp;
    // TODO1: declare an fstream to read from a file "mystock.txt"
    ...
    // TODO2: input data from the file into variable tmp
    // TODO3: construct vector inventory defined above from the ingested data
    while (...) {
        ...
    }

    string x = "";
    bool input = true;
    char c = 'y';
    bool itemfound;
    while (input) {
        itemfound = false;
        cout << "Enter name of item you are interested in: "; 
        cin >> x;
        try {
            for (item i: inventory) {
                if (i.name == x) {
                    cout << "found item" << endl;
                    cout << "id: " << i.id << " price: " << i.price << " qty in stock: " << i.qtyInStock << endl;
                    itemfound = true;
                }
            }
            if (!itemfound) {throw runtime_error ("item not found: "); }
        }
        catch (runtime_error e) {
            cout << e.what() << x << endl;
        }
        cout << "Do you want to search another item (y/n): "; 
        cin >> c;
        if (c == 'n') { input = false;}
            else {input = true;}
        }
    }
