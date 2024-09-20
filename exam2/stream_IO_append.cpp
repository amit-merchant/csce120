#include<iostream>
#include<fstream>
#include<string>
int main(){
    std::fstream fs("test_append.txt", std::ios::app);  
    fs << "... appending here." << std::endl;
}