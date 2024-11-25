#include <iostream>

// Change the underlying value pointed to by ptr
void changeValue(int* ptr) {
    *ptr = 2;
}

int main() {
    int num = 1;
    int* ptr = &num; // Create a pointer that point to variable num
    std::cout << "ptr is: " << ptr << " and ptr contents: " << *ptr << std::endl; 
    changeValue(ptr);
    // observe that although the ptr is passed by value, contents of a ptr can
    // always be changed by the function
    std::cout << "after invoking function changeValue" << std::endl;
    std::cout << "ptr is: " << ptr << " and ptr contents: " << *ptr << std::endl;
    return 0;
}
