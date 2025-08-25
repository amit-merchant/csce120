#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> x(10);
    for (int i = 0; i<10; i++) {
        x.at(i) = i*10; 
    }
    for (int i = 0; i<10; i++) {
        cout << x.at(i) << " "; 
    }
    cout << endl;
    x.push_back(200);
    x.push_back(210);
    for (int i = 0; i<x.size(); i++) {
        cout << x.at(i) << " "; 
    }
    cout << endl;
    for (int i = 0; i<7; i++) {
        x.pop_back();
    }
    for (int i = 0; i<x.size(); i++) {
        cout << x.at(i) << " "; 
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        x.insert(x.begin()+i,i*i);
    }
    for (int i = 0; i<x.size(); i++) {
        cout << x.at(i) << " "; 
    }
    cout << endl;
}
