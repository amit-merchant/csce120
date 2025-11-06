#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    v.reserve(1);           
    v.push_back(10);
    int* p_before = &v[0];
    // This push will likely trigger reallocation 
    v.push_back(20);
    int* p_after = &v[0];

    std::cout << "address before: " << p_before << "\n";
    std::cout << "address after : " << p_after << "\n";
    std::string str = "true";
    if (p_before != p_after)  str = "false"; 
    std::cout << "same storage?  " << str << "\n";
}
