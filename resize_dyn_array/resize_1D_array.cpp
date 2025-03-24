#include<iostream>
using namespace std;

void upsize(int*& array, int& size, const int change){
    int newSize = size + change;
    int* newArr = new int[newSize]();
    for(int i = 0; i < size; i++){
        newArr[i] = array[i];
    }
    for(int i = size; i < newSize; i++){
        newArr[i] = 2*newArr[i-size];
    }
    delete[] array;
    array = newArr;
    size = newSize;
}

void dnsize(int*& array, int& size, const int change){
    int newSize = size - change;
    try {
        if (newSize <= 0) 
            throw runtime_error ("cannot make an array size zero or negative");
        int* newArr = new int[newSize]();
        for(int i = 0; i < newSize; i++){
            newArr[i] = array[i];
        }
        delete[] array;
        array = newArr;
        size = newSize;
    }
    catch (runtime_error &e) {
        cout << e.what() << endl; 
    }
}

void print(int*& array, const int size){
    for(int i=0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(){ 
    int size = 4;
    int* array = new int[size]{1, 2, 3, 4};
    print (array, size);
    upsize(array, size, 3);
    print (array, size);
    dnsize (array, size, 4);
    print (array, size);
    upsize(array, size, 6);
    print (array, size);
    dnsize(array, size, 12);
    print (array, size);
    delete[] array;
}
