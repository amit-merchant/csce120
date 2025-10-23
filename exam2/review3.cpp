//pass by, dynamic memory, memory leak
#include<iostream>
using namespace std;
void func(int*& ptr) {
    int *x = new int(2);
    ptr = x;
}
int main() {
    int* p = new int(1);
    func(p);
    std::cout << *p << std::endl;
    delete p;
}
// what is on the stack, what is on the heap
// what should be fixed to prevent a memory leak