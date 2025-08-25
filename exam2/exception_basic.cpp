#include <iostream>
#include <stdexcept>
#this file has the basic try-catch structure
using std::cout, std::exception, std::invalid_argument, std::endl;
void exceptionThrower(){
    try {
        throw invalid_argument("hi"); } 
    catch (std::runtime_error const& e){ // replace exception with 
        cout << e.what() << endl; } 
    }
int main() { 
    try{
        exceptionThrower(); }
    catch(...){
        cout << "Caught in main" << endl; } 

}
