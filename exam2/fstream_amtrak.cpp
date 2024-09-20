#include<iostream>
#include<fstream>
using std::ifstream, std::ofstream, std::cin, std::cout, std::endl, std::string;

// This construct reads a file into an array
int main(){
    const int NUM_CITIES_SERVED = 10;
    ifstream ifs("./amtrak.txt");
    string amtrak[NUM_CITIES_SERVED];
    int i = 0;
    while (ifs >> amtrak[i]) {
        i++;
        cout << amtrak[i] << " ";
    }
    cout << endl;
}
