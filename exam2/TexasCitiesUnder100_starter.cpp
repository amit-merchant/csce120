#include<iostream>
#include<fstream>
using std::ifstream, std::ofstream, std::cin, std::cout, std::endl, std::string;

// read from an input file "TXCitiesUnder100.txt"
// and write into an output file backwards "TXCitiesUnder100Copy.txt"
// line 1 becomes line last, line last becomes line 1

int main(){
    const int CAPACITY = 20;
    // TODO ifstream statement
    // TODO ofstream statement

    string smallTowns[CAPACITY];
    int i=0;
    while (true) {
        // TODO read from input stream handler into smallTowns[i]
        if (smallTowns[i] == "\0") {break;}
        i++;
    }
    int max_cities = i;
    cout << max_cities;
    for (; ; i--) { // TODO define correct loop variables
        // TODO write onto output stream from smallTowns[i]
    }
}
