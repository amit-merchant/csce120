#include <iostream>
#include <stdexcept>
using std::cout, std::exception, std::invalid_argument, std::endl;
int func(int a, int b){
	try{
    		if (b == 0) { 
                throw std::invalid_argument("divide by zero");
	        }
    }
	catch (std::invalid_argument e){
    	cout << e.what() << endl;;
        return -1;
	}
	return a/b;
}

int main(){
	int x = 3;
	int y = 0;
    cout << func(x, y) << endl;
    y = 1;
    cout << func(x, y) << endl;
}