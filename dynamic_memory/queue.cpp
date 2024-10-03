#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/* This function assigns the nextptr to a different color thus
   creating a roundrobin function */

void round_robin () {    
}

/* Main has two queues - red and blue. It assigns incoming ticket 
   (cin) to the next queue thus keeping a balance. */

int main() {
    int* red = new int();
    int* blue = new int();
    int** nextptr = &blue;
    for (int i = 0; i < 5; i++) {
        round_robin(nextptr, &red, &blue);
        cin >> **nextptr;
    }
    cout << **nextptr << endl; 
    delete red;
    delete blue;
}
