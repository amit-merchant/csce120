//review: stringstream, flags
#include<iostream>
#include<sstream>
using std::cout, std::string, std::istringstream;
int main(){
    string s = "1001 1002 1003";
    istringstream iss(s);
    int n = 0;
    int sum = 0;
    iss.ignore(2);
    while(iss >> n){
        sum += n;
    }
    cout << sum;
}
