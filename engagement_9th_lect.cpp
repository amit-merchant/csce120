#include <iostream>

using std::cout, std::endl, std::cin, std::string;

int main () {
    float discount = 0.0;
    float sum_of_cart = 0.0;
    float tax_rate = 0.1;
    float net_value = 0.0;
    float delivery = 10.0;
    bool next_customer = true;
    string yes_or_no = "yes";

    while (next_customer == true) {
        cout << "what is the cart value: ";
        cin >> sum_of_cart;
        // cout << endl;

        if (sum_of_cart >= 50.0) discount = 0.00;
            delivery = 10.0;
        if (sum_of_cart >= 100.0) discount = 0.1;
            delivery =  10.0;
        if (sum_of_cart >= 200.0) discount = 0.25;
            delivery = 0.0;

        net_value = sum_of_cart*(1-discount)*(1+tax_rate) + delivery;
        cout << "net sales: " << net_value << endl;

        cout << "is there another customer: ";
        cin >> yes_or_no;
        next_customer = yes_or_no == "y" ? true : false; 
    }
}

