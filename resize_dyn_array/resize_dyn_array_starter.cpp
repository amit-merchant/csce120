#include <iostream>
#include <fstream>
using namespace std;

void resize (int **&array, const int rows, const int addRows, 
    const int cols, const int addCols, const int value) {
    // TODO complete this function

    // Resize array per instruction

    // delete old array
}

// do not touch this function
void printarray(int **array, const int rows, const int cols) {
    for (int i=0; i < rows; i++) {
        for (int j=0; j < cols; j++) {
            cout << array[i][j] << " "; 
        }
        cout << endl;
    }
}

int main () {
    // initial array size 2x3
    const int numRows = 2;
    const int numCols = 3;
    int **arry = new int*[numRows]; 
    for (int i=0; i < numRows; i++) {
        arry[i]  = new int[numCols] {3+i, 5+i, 7+i};
    }
    printarray(arry, numRows, numCols);
    // TODO read three numbers from new1.txt
    
    // TODO error message if you cannot open the file or it has less than three numbers

    // TODO error message if the number of rows to be added or number of columns to be addedd is negative

    // TODO invoke resize function

    // TODO print new array
    
}
