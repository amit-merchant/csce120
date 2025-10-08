#include<iostream>
int f(int a, int* b){
    int c = 0;
    b = &c;
    a = 2;    
    return a + *b;
}
int main(){
    int x = 1;
    int* y = &x;
    std::cout << f(x, y) << x << *y;
}
