#include<iostream>
using std::cout, std::endl;

int greaterThan(int x, int y){
    if (x > y){
        cout << "x is greater than y" << endl;
    }
    else if(x < y){
        cout << "x is less than y" << endl;
    }
    else {
        cout << "both are equal" << endl;
    }
    return 0;
}

// this code is intentionally incorrect
// the point is that it is the programmer's responsibility to
// ensure the integrity of the code when using overload

int greaterThan(double x, double y) {
    if (x < y){
        cout << "executing second instance of overloaded function, " << "x is greater than y" << endl;
    }
    else if(x > y){
        cout << "executing second instance of overloaded function, " << "x is less than y" << endl;
    }
    else {
        cout << "executing second instance of overlaoded function," << "both are equal" << endl;
    }
    return 0;
}

int greaterThan(char x, char y) {
    if (x > y){
        cout << "executing third instance of overloaded function, " << "x is greater than y" << endl;
    }
    else if(x < y){
        cout << "executing third instance of overloaded function, " << "x is less than y" << endl;
    }
    else {
        cout << "executing third instance of overlaoded function," << "both are equal" << endl;
    }
    return 0;
}

// int greaterThan(int x, int y, int z) {
//     if (x > y){
//         if (y > z) {
//             cout << "x is greater than y which is greater than z" << endl;
//         }
//         else {
//             cout << "x is greater than y which is less than z" << endl;
//         }
//     }
//     else if(x < y){
//         if (y > z) {
//             cout << "x is less than y which is greater than z" << endl;
//         }
//         else {
//             cout << "x is less than y which is less than z" << endl;
//         }
//     }
//     else {
//         cout << "several other conditions" << endl;
//     }
//     return 0;
// }

main (){
    greaterThan(3,4);
    greaterThan(0.1,0.0);
    greaterThan('a','b');
    // greaterThan(3,2,1);
}