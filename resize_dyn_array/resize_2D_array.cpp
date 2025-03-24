#include <iostream>
#include <fstream>
using namespace std;

void resize (int **&arry, int origRows, int addRows, int origCols, int addCols, int value) {
    // create and initialize array of new size
    int totalrows = origRows + addRows;
    int totalcols = origCols + addCols;
    int **new_array = new int*[totalrows];
    for (int i=0; i<totalrows; ++i) {
        new_array[i] = new int[totalcols];
    }
    
    // loop through the 2D array, copy elements from old array where needed
    // fill up with filler value
    for (int i=0; i<totalrows; ++i) {
        for (int j=0; j<totalcols; ++j) {
            if (i < origRows && j < origCols) {
                new_array[i][j] = arry[i][j];
            }
            else {
                new_array[i][j] = value;
            }
        }
    }

    // delete old array
    for (int i =0 ; i< origRows; i++) {
        delete[] arry[i];
    }
    delete[] arry;

    // point array to new array
    arry = new_array;
}

void printarray (int **array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // create and initialize the array
    int **array = new int*[2];
    for (int i=0; i < 2; i++ ) {
        array[i] = new int[3]{4,5,6};
    }

    int addRows = 0;
    int addCols = 0;
    int fillervalue = 0;

    // read input file
    ifstream ifs ("input.txt");
    ifs >> addRows >> addCols >> fillervalue;

    //calculate total rows and cols
 
    // call resize
    resize (array, 2, addRows, 3, addCols, fillervalue);

    // print array
    printarray (array, (2+addRows), (3+addCols));

    for (int i =0 ; i< 2+addRows; i++) {
        delete[] array[i];
    }
    delete[] array;

}
