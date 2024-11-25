#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void bubbleSort(vector<int>& x) {
    // Loop through all elements
    for (int i = 0; i < x.size() - 1; i++) {
        // as you sort the lowest element goes to the head of the vector 
        for (int j = 0; j < x.size() - i - 1; j++) {
            // swap if jth element is greater than j+1 st element
            // hence bubbling down the smallest element 
            if (x.at(j) > x.at(j + 1)) {
                swap(x.at(j), x.at(j + 1));
            }
        }
        for (int k = 0; k<x.size(); k++) {
                cout << x.at(k) << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<int> x{10,9,2,1,3,4,0,6};
    for (int i = 0; i<x.size(); i++) {
        cout << x.at(i) << " ";
    }
    cout << endl;
    bubbleSort(x);
    // for (int i = 0; i<x.size(); i++) {
    //     cout << x.at(i) << " ";
    // }
    // cout << endl;
}
