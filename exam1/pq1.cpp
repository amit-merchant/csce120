#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct record {
    string name;
    bool isStudent;
    bool isFulltime;
};

bool func(record y) {
    return y.isStudent && !y.isFulltime;
}

int main(){
    vector<record> x = {{"Alice", true, true}, {"Bob", true, false}, {"Caroline", false, true}};
    for (int i=0; i<x.size(); i++){
        if (func(x.at(i))) cout << x.at(i).name << " ";
    }
}    
