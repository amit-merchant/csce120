#include <iostream>
#include <cassert>
using namespace std;

//prints the # of capital As in the input
int countAs(const char str[]) {
    char nextChar = str[0];
    int curPos = 0;
    int aCount = 0;
    while(nextChar != '\0') {
        // cout << nextChar << endl;
        aCount += nextChar == 'A' ? 1 : 0;
        nextChar = str[++curPos];
    }
    cout << aCount << endl;
    return aCount;
}

int main() {
    // char str[] = "A big cat. A big dog.";
    // countAs (str);
    cout << "Test start" << endl;
    assert(countAs("AAA")==3);
    assert(countAs("aaa")==0);
    assert(countAs("ABCDEFGHIFKLMNOPQRSTUVWXYZ")==1);
    assert(countAs("aA aA Aa Aa")==4);
    cout << "Test end" << endl;
}
