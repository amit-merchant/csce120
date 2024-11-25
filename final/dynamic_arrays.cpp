#include<iostream>
void func(int* a, int*& b, int& c){
    a = new int(2);
    b = new int(3);
    c = *a;
}
int main(){
    int** x = new int*[3]();
    x[0] = new int();
    x[1] = new int;
    x[2] = new int(1);
    std::cout << *x[0] << "," << *x[1] << "," << *x[2] << std::endl;
    func(x[0],x[1],*x[2]);
    std::cout << *x[0] << "," << *x[1] << "," << *x[2] << std::endl;
}
