#include<iostream>
#include<string>
using std::string, std::cout, std::endl;

struct item{
    string name;
    int sku;
    double price;
};

main () {
    item hammer;
    hammer.name = "hammer";
    hammer.sku = 1234;
    hammer.price = 9.99;
    cout << hammer.name << " " << hammer.price << endl;
}