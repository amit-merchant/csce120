#include<iostream>

using std::string;

int main() {
    int x = 0;
    int y = 1;
    std::cout << x+y << std::endl;
    x++;
    y--;
    std::cout << 2*x+y << std::endl;
    x = 0.1;
    y = 0.2;
    std::cout << x+y << std::endl;
    double z = 0.1;
    double w = 0.2;
    std::cout << z + w << std::endl;
    string a = "a";
    string b = "b";
    std::cout << a + b << std::endl;
}