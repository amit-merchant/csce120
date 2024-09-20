#include<iostream>
#include<fstream>
using std::ifstream, std::ofstream, std::cin, std::cout, std::endl, std::string;


int main(){
    const int SIZE = 5;
    // TODO declare input file stream to read from "VariousNumbers.txt"

    unsigned int Numbers[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        // TODO use the stream handler to read into the array Numbers[i]
    }

    int largest_number = 0;
    for (int i=0; i < SIZE; ++i) {
        // TODO logic to determine if the array element is larger than
        // largest_number, if yes update largest_number
    }
    cout << "largest number was... " << largest_number << endl;
}
