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
void get_item_details(const string& line, string* brand, double* price, int* sku, string* priceType) {
    // turn the string into an input stream
    std::istringstream sin(line);
    // read the brand, price, and sku from the string
    sin >> *brand;
    sin >> *price;
    sin >> *sku;
    sin >> *priceType;
}