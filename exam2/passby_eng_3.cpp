#include<iostream>
int f(int a, int* &b, int *c){
    b = c;
    a = 2;    
    return a + *b;
}
int main(){
    int x = 1;
    int* y = &x;
    int z = 5;
    std::cout << f(x, y, &z) << x << *y;
}
