 #include<iostream>
#include<fstream>
int main(){
    std::fstream fs("Stream2.txt");
    int x;
    fs >> x;
    std::cout << x+1;
    fs << x+2 << "\n";
}
