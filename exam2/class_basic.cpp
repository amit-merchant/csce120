#include<iostream>
#include<string>
#include <sstream>
using std::cout, std::cin, std::endl, std::exception, std::invalid_argument; 
using std::getline, std::string;

// ** converted strut into class and new method to apply discount
class item{
    public:
        int sku;
        double price;
        string brand;
        string priceType;
    public:
        double discount () { // method
            price = price * 0.8;
            return 0;
        }
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

main () {
    int i = 0;
    const int MAX = 5;
    item list_of_items[MAX];
    string line;

    getline (cin, line);
    while (!line.empty()) {
        string brand;
        double price;
        int sku;
        string priceType;
        get_item_details(line, &brand, &price, &sku, &priceType);
        list_of_items[i].brand = brand;
        list_of_items[i].price = price;
        list_of_items[i].sku = sku;
        list_of_items[i].priceType = priceType;
        if (priceType == "onsale") { list_of_items[i].discount();} // ** apply discount 
        i++;
        getline(cin, line);
    }

    // initializing temporary variable for comparison
    double cheapest_hammer = 1000;
    int sel_hammer = -1;
    for (int i=0; i < MAX; i++){
        if (list_of_items[i].price < cheapest_hammer) {
            cheapest_hammer = list_of_items[i].price;
            sel_hammer = i;
        }
    };
    // printing the brand and price with lowest price
    cout << "Cheapest hammer is: " << list_of_items[sel_hammer].brand << " and the price is: " << list_of_items[sel_hammer].price << endl;
}
