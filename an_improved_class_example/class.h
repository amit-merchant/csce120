#include <iostream>
#include <string>
#include <sstream>
#ifndef CLASS_H
#define CLASS_H

using std::cout, std::cin, std::endl, std::exception, std::invalid_argument; 
using std::getline, std::string;

class item{
    public:
        int sku;
        double price;
        string brand;
        string priceType;
    public:
        double discount ();
};

void get_item_details(const string& line, int i);

void find_cheapest_item(int num_of_items);

#endif