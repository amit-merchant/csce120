#include<iostream>
#include<string>
using std::string, std::cout, std::endl;

// defining a struct type which contains several members
struct item{
    string name;
    int sku;
    double price;
    string brand;
};

main () {
    // defining array size
    const int MAX_ITEMS = 3;
    // instantiating an array of type "item"
    item list_of_items[MAX_ITEMS];
    // initializing the array elements
    for (int i=0; i<MAX_ITEMS; i++) {
        list_of_items[i].name = "hammer";
        list_of_items[i].sku = 1234 + i;
        if (i==0) {
            list_of_items[i].brand = "Milwaukee";
            list_of_items[i].price = 10.99;
        }
        else if (i==1) {
            list_of_items[i].brand = "Crescent";
            list_of_items[i].price = 9.99;
        }
        else if (i==2) {
            list_of_items[i].brand = "Generic";
            list_of_items[i].price = 8.99;
        }
    };
    // initializing temporary variable for comparison
    double cheapest_hammer = 1000;
    int sel_hammer = -1;
    // iterating through the list to find the lowest price
    // in each iteration the temprary variable of cheapest_hammer is replaced by the new price if
    // the item price is lower than than the last found cheapest price
    // along with this the index of the item is also stored for future access
    for (int i=0; i<MAX_ITEMS; i++){
        if (list_of_items[i].price < cheapest_hammer) {
            cheapest_hammer = list_of_items[i].price;
            sel_hammer = i;
        }
    };
    // printing the brand and price with lowest price
    cout << "Cheapest hammer is: " << list_of_items[sel_hammer].brand << " and the price is: " << list_of_items[sel_hammer].price << endl;
}