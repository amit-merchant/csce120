#include <iostream>
int add(int x, int y);
int main() {
    std::cout << add(3,5) << std::endl;
    return 0;
}
int add(int x, int y) {
    return x + y;
}
