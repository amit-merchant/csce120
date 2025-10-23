// review: classes, this, size_t (unsigned integer)
// size_t makes code portable
#include<iostream>
class jaz {
    size_t *x;
    public: 
        jaz (size_t *x): x(x){};
        jaz& f(jaz other) {
            this->x = other.x;
            return *this;} 
        int  getx() const { return x ? *x : 0; }};
int main(){
    size_t x = 0;
    size_t y = 1;
    jaz A(&x);
    A.f(jaz(&y));
    std::cout << A.getx();
}
//observe - creating a temporary jaz object to pass into "f"