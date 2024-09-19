#include<iostream>
#include<limits>
using std::cout, std::cin, std::endl, std::numeric_limits, std::streamsize;

int main() {
    int ft;
    int inches;
    int num_of_tries = 1;

    try { 
        cout << "Enter height in ft and inches\n";
        cin >> ft >> inches;
        while(1)
        {
            if (ft < 3 || ft > 8 || inches > 11) {
                cout << "You have entered the wrong input for height" << endl;
                if (num_of_tries > 3) {
                    throw num_of_tries;
                }
                cin >> ft >> inches;
                num_of_tries++; 
            }
            else {break;}
        }
        cout << "The height is " << ft << " ft " << inches << " inches " << endl;
    } 
    catch (...) {
        cout << "too many attempts... " << num_of_tries << endl; 
    }
    return 0;
}
