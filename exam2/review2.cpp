//review: exceptions, try-throw-catch
#include <iostream>
char func(int x){
    if (x<0) { throw -x; }
    return '#';
}
int main() {
    try {
        std::cout << func(2); 
        std::cout << func(-2); 
    }
    catch(int x){
        std::cout << x;
    } 
}
