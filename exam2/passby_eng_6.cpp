#include<iostream>
void f(int &a, int* b, int* &c){
    c = &a;
    (*c)++;
    *b = 0;
    c = &a;
}
int main(){
    int x = 3;
    int y = 1;
    int* p = &y;
    int* q = p;
    std::cout << x << y << *p << *q;
    f(x, p, q);
    std::cout << x << y << *p << *q;
}
