#include <iostream>
#include <fstream>
using namespace std;

void display(string*& farm, int size) {
    for (int i=0; i<size; i++) {
        cout << farm[i] << " ";
    }
    cout << endl;
}

void resizeFarm(string* farm, int size, int sizeToAdd, string newCrop){
	if(sizeToAdd < 0 or sizeToAdd > size){
    		throw std::invalid_argument("");
	}
    int newSize = size + sizeToAdd;
	string* newArr = new string[newSize];
	for(int i = 0; i < newSize; i++){
    	if(i < size){
        	newArr[i] = farm[i];
    	}
    	else{
            if (farm[i-size] == "empty") {
                newArr[i] = newCrop;
            }
            else {
        	    newArr[i] = farm[i-size];
            }
    	}
	}
	delete[] farm;
	farm = newArr;
	size = newSize;
    display(farm,size);
}

int main() {
    ifstream ifs ("input.txt");
    int size;
    ifs >> size;
    string* farm = new string[size];
    for (int i=0; i < size; i++) {
        ifs >> farm[i];
    }
    display (farm, size);
    resizeFarm(farm, size, 3, "tomato");
    cout << size << endl;
    display (farm, size);
}