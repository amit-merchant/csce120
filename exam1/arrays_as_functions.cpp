#include<iostream>
#include<string>
using std::string, std::cout, std::endl;

// defining a struct type which contains several members
struct item{
    int sku;
    double price;
};
double func(item x[]){
    x[0].sku = 1001;
    x[0].price = 9.99;
    return 0.00;
}

main () {
    const int CAPACITY = 3;
    item hammer[CAPACITY] = {{2000, 8.88}, {2001, 10.99}, {2002, 12.99}};
    func(hammer);
    cout << hammer[0].price << endl;
}
