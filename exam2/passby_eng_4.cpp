#include<iostream>
void f(int a, int &b, int* &c){
    *c = 0;
    c = &a;
    (*c)--;
    c = &b;
    (*c) += 4;
}
int main(){
    int x = 2;
    int y = 3;
    int* p = &y;
    std::cout << x << y << *p;
    f(x, x, p);
    std::cout << x << y << *p;
}
