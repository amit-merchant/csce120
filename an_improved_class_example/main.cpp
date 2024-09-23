#include<iostream>
#include<string>
#include <sstream>
#include <fstream>
#include "class.h"
using std::cout, std::cin, std::endl, std::exception, std::invalid_argument; 
using std::getline, std::string, std::ifstream;

const int MAX = 25; // define capacity to never exceed 25 items in a file
item* list_of_items = new item[MAX]; // dynamic array allocated at runtime
int i = 0;

int main (int argc, char *argv[]) {
    string line;
    try { 
        if (argc > 1) {  
            ifstream ifs (argv[1]); // argv[1] is input filename            
            int num_of_items = 0; 
            try {
                if (!ifs.is_open()) { // check if file can be opened
                    throw std::runtime_error("cannot open file");
                }   
                do {        
                    getline (ifs, line); // getline from input file
                    get_item_details(line, i); // parse line string into array elements
                    if (list_of_items[i].priceType == "onsale") { list_of_items[i].discount();} // apply discount 
                    i++;
                } while (!line.empty()); 
                num_of_items = --i; // decrement i before assigning to num_of_items
                find_cheapest_item(num_of_items);
            }
            catch (const std::runtime_error& error_message) {
                cout << error_message.what() << endl;
            }
        }
        else {throw std::runtime_error("too few arguments");}
    }
    catch (const std::runtime_error& error_message) {
            cout << error_message.what() << endl;
    }
    delete [] list_of_items; // deallocate dynamic array
}