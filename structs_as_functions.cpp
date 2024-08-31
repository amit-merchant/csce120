#include<iostream>
#include<string>
using std::string, std::cout, std::endl;

// defining a struct type which contains several members
struct item{
    int sku;
    double price;
};
double func(item x){
    x.sku = 1001;
    x.price = 9.99;
    return x.price;
}

main () {
    item hammer = {1000, 8.88};
    hammmer.price = func(hammer);
    cout << hammer.price << endl;
}
