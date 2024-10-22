#include <iostream>
#include <fstream>
using namespace std;

void resize (int **&array, const int rows, const int addRows, 
    const int cols, const int addCols, const int value) {

}

void printarray(int **array, const int rows, const int cols) {
    for (int i=0; i < rows; i++) {
        for (int j=0; j < cols; j++) {
            cout << array[i][j] << " "; 
        }
        cout << endl;
    }
}

int main () {
    const int numRows = 2;
    const int numCols = 3;
    int **arry = new int*[numRows]; 
    for (int i=0; i < numRows; i++) {
        arry[i]  = new int[numCols] {3+i, 5+i, 7+i};
    }
    printarray(arry, numRows, numCols);
}
