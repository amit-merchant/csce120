#include <iostream>
#include <vector>
using namespace std;

// read an input file of numbers and build a matrix 
// which has a row of 3 elements and column of size of input file / 3
int main() {
    // Declare an uninitialized 2D vector
    vector<vector<int>> matrix;

    // use getline and stoi to build a flat vector
    string line = "";
    int tmp;
    vector<int> flat; 
    while (getline (cin, line)) {
        tmp = stoi(line);
        flat.push_back(tmp);
    }

    // now build a 3x4 matrix
    int index = 0;
    for (int i=0; i<flat.size()/3; i++) {
        vector<int> row;
        index += i;
        for (int j=0; j<3; j++) {
            row.push_back(flat.at(index+j));
        }
        matrix.push_back(row);
    }

    // Access and print the elements of the 2D vector
    for (vector<int> row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}
