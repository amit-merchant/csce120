#include<iostream>
#include<string>
#include <sstream>
#include "class.h"
using std::cout, std::cin, std::endl, std::exception, std::invalid_argument; 
using std::getline, std::string;

double item::discount () { // method
            price = price * 0.8;
            return 0;
        };

// ignore the details of this function
// focus on what it produces as the output
void get_item_details(const string& line, int i) {
    // turn the string into an input stream
    std::istringstream sin(line);
    extern const int MAX;
    extern item* list_of_items;
    // read the brand, price, and sku from the string
    sin >> list_of_items[i].brand;
    sin >> list_of_items[i].price;
    sin >> list_of_items[i].sku;
    sin >> list_of_items[i].priceType;
    // cout << list_of_items[i].brand << endl;
}

void find_cheapest_item (int num_of_items) {
    double cheapest_hammer = 1000; // initializing temporary variable for comparison
    int sel_hammer = -1;
    extern item* list_of_items;
    for (int i=0; i < num_of_items; i++){
        if (list_of_items[i].price < cheapest_hammer) {
            cheapest_hammer = list_of_items[i].price;
            sel_hammer = i;
        }
    };
    // printing the brand and price with lowest price
    cout << "Cheapest hammer is: " << list_of_items[sel_hammer].brand << " and the price is: " << list_of_items[sel_hammer].price << endl;
}