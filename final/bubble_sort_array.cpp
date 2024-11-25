#include<iostream>
using namespace std;

void swapfunc(int&x, int&y) {
    int temp = x;
    x = y;
    y = temp;
}

void bubbleSort(int x[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (x[j] > x[j + 1]) {
                swapfunc(x[j], x[j + 1]);
            }
        }
        for (int k = 0; k<n; k++) {
                cout << x[k] << " ";
        }
        cout << endl;
    }
}

int main(){
    int x[] = {10,7,9,12,8,1,3,4,0,6};
    int n = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i<n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    bubbleSort(x, n);
}
