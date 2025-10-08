#include <iostream>
#include <string>
using namespace std;
 
class Counter {
    string name; //private by default
    int value;   //private by default
public:
    Counter(string n, int v = 0) : name(n), value(v) {}
    void inc(Counter& c, int step = 1) {
        c.value += step; } //pass by ref
    void print(const Counter& c) {
        cout << c.name << ": " << c.value << '\n';} 
        //pass by const ref
};

int main() {
    Counter c("Queue", 3);
    c.print(c);           
    c.inc(c);            
    c.print(c);           
    c.inc(c, -2);
    c.print(c);            
}
