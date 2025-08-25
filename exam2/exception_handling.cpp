#include <iostream>
#include <stdexcept> // please note new library stdexcept
#include <cmath>

double called_function (double x) {
    // called function detects inavlid input
    if (x < 0) {
        throw std::invalid_argument ("argument is negative");
    }
    return sqrt(x);
}   

int main () {
    double x;
    std::cout << "Enter a positive number with decimal point "; 
    std::cin >> x;
    //try block
    try {
        std::cout << called_function(x) << std::endl;
    }
    //catch block/
    catch (std::invalid_argument e) {
        std::cout << e.what() << std::endl;
    }
}
