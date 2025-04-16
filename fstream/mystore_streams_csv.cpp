#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<stdexcept>
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
    string str = "";
    ifstream ifs("myStockInCSV.txt");
    char delimiter = ',';
    string var;
    item tmp;
    while (ifs >> str) {
        istringstream iss(str);
        int i = 0;
        while(getline(iss, var, delimiter)) {
            switch(i) {
                case 0:
                    tmp.id=stoi(var);
                    break;
                case 1:
                    tmp.name=var;
                    break;
                case 2:
                    tmp.price=stof(var);
                    break;
                case 3:
                    tmp.qtyInStock=stoi(var);
                    break;
            }
            i++;
        }
        try {
            if (i==4) {
                inventory.push_back(tmp);
            }
            else {
                throw runtime_error("does not have complete record");
            } 
        }
        catch(runtime_error const e) {
            cout << e.what();
            return -1;
        }
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

