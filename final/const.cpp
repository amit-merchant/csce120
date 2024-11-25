#include<iostream>

// does not compile because function tries to modify a constant
int constFunc (const int& x) {
    x = 2;
    return x;
}

int main () {
    int a = 0;
    std::cout << constFunc(a) << std::endl;
    a = 1;
    std::cout << constFunc(a) << std::endl;
}