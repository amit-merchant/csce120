#include<iostream>

main () {
    int i = 1;
    while (i != 0){
        std::cout << "while loop condition is true, still looping..." << std::endl;
        std::cout << "new number:";
        std::cin >> i;
    }
    std::cout << "exit looping" << std::endl;

    for (int j=0; j<5; j++){
        std::cout << j << std::endl;        
    }
}