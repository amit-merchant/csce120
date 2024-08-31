#include <iostream>
using std::cout, std::cin, std::endl;

// note the syntax of passing a 2D array into a function
int print_array (int ary[][3], int i_max, int j_max){
    cout << "printing a 2D array as a matrix:" << endl;
    for (int i=0; i < i_max; i++) { // setup debug breakpoint
        for (int j=0; j < j_max; j++) {
            cout << ary[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

main () { // note main compiles without int type
    const int ROWS = 3; 
    const int COLS = 3;
    int i;
    int eg_array[ROWS][COLS] = {{1,0,0}, {0,2,0}, {0,0,3}};
    print_array(eg_array, ROWS, COLS);
}