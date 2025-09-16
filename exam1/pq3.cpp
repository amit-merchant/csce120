#include <iostream>
using namespace std;

void sum(int n, int arry[], int size) {
    for (int i=0; i<size; i++) {
        n += arry[i];
    }
}

int main() {
    int n = 0;
    int array[3] = {1, 2, 3};
    sum(n, array, 3);
    cout << n;
    return 0;
}