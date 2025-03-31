#include<iostream>
using namespace std;
class Bar{
    public:
        int y;
        Bar() : y(7) {}
        Bar(int i) : y(i) {}
};
class Foo{
    public:
        Bar* x;
        Foo() : x(new Bar()) {}
        Foo(int i) : x(new Bar(i)) {}
        ~Foo() { delete x; }
        Foo(const Foo& obj){
            x = new Bar(4);
        }
        Foo& operator=(const Foo& obj){
            if(this != &obj){
                delete x;
                x = new Bar();
                x->y = obj.x->y; }
            return *this;
        };
};
int main(){
    Foo a(3);
    Foo b = a;
    Foo* c = new Foo(a);
    cout << a.x->y << b.x->y << (*c).x->y << endl;
    a.x->y = 6;
    (*c).x->y = 7;
    b = a;
    cout << a.x->y << b.x->y << (*c).x->y << endl;
    delete c;
    c = nullptr;
    return 0;
}
