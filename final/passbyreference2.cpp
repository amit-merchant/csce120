#include<iostream>
void f(int a, int &b, int* c){
    a = 4;
    b = 5;
    *c = 6;
}

// This is a good program to understand pass by value and pass by reference
// x is passed by value, y and z are passed by reference
// Therefore x remains unchanged, while y and z are modified
int main(){
    int x = 1;
    int y = 2;
    int *z = new int();
    *z = 3;
    f(x, y, z);
    std::cout << x << y << *z;
    delete z;
}
