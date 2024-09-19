#include <iostream>
using std::cout, std::endl;

main () {
    int arx[2][3] = {{0,1,2},{3,0,1}};
    int ary[2][3] = {{0,0,-2},{-2,0,0}};
    int arz[2][3] = {{0,0,0}, {0,0,0}};

    int i = 0;
    int j = 0;
    for (i=0; i<2; i++) {
        for (j=0; j<3; j++) {
                arz[i][j] += arx[i][j] + ary[i][j];          
        }
    }
    for (i=0; i<2; i++) {
                cout << arz[i][0] << " " << arz[i][1] << " " << arz[i][2] << " " << endl;        
        }
}
