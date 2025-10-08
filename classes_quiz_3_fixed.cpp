#include<iostream>
using namespace std;
class foo{
    private: int *x; int tmp = 1;
    public:
        foo() : x(nullptr) {}
        void setX(int *x){
            tmp += *x;
            this->x = &tmp; }
        int* getX(){
            return (x != nullptr) ? x : &tmp; 
        } };

int main(){
    foo a;
    int val = 3;
    int *x = &val;
    cout << *a.getX() << " ";
    a.setX(x);
    a.setX(a.getX());
    cout << *a.getX() << endl; }
 
