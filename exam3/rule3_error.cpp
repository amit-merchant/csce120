#include <iostream>
class Array {
    int* data;
    int size;
public:
    Array(int s) : size(s) { 
        data = new int[size]; 
        for(int i=0; i<size; i++) data[i] = i; }
    ~Array() { delete[] data; }
    Array(const Array& other) : size(other.size) { 
        data = new int[size]; 
        for(int i=0; i<size; i++) data[i] = other.data[i]; }
    Array& operator=(const Array& other) { 
        if(this!=&other) { 
            delete[] data; 
            size=other.size; 
            data=new int[size]; 
            for(int i=0; i<size; i++) data[i]=other.data[i]; } 
        return *this; }
    void print() { 
        for(int i=0; i<size; i++) std::cout << data[i] << " "; 
        std::cout << "\n"; }
    void set(int i, int v) { data[i] = v; }
};
int main() {
    Array a(5);
    Array b(1);
    a.print();
    b.print();
    b = a;
    a.print();
    b.print();
    a.set(0, 999);
    a.print();
    b.print();
    return 0;
}



































