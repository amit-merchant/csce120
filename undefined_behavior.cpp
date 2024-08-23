#include <iostream>
using std::cout, std::endl;

int main () {
    int x = 2147483647;
    cout << x << endl;
    x += x;
    cout << x << endl;
    x += x;
    cout << x << endl;
} 