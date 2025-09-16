#include <iostream>
using namespace std;

void sum(int n, int arry[], int size) {
    int i = 1;
    do  {
        arry[i] = i - n;
        i++;
    } while (i < size);
}

int main() {
    int n = 0;
    int array[3] = {1, 2, 3};
    sum(n, array, 3);
    for (auto i : array) cout << i;
    return 0;
}