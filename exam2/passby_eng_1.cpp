#include<iostream>
int f(int a, int &b){
    a = 2;    
    return a + b;
}
int main(){
    int x = 1;
    int &y = x;
    std::cout << f(x, y) << x << y;
}
