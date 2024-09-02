#include <iostream>
#include <stdexcept>

int main() {
    int a = 10;
    int b = 0;
    int adivb = a / b;
    try {
        if (b == 0) {
            throw std::runtime_error("Division by zero error!");
        }
        int result = a / b;
        std::cout << "Result: " << result << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
