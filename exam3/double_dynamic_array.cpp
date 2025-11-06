#include<iostream>
using std::cin, std::cout, std::endl;

//doubles the capacity of array
void double_capacity(int*& array, int& capacity){
    int* newArr = new int[capacity*2]();
    for(int i = 0; i < capacity; i++){
        newArr[i] = array[i];
    }
    for(int i = capacity; i < 2*capacity; i++){
        newArr[i] = array[0] + i;
    }
    delete[] array;
    array = newArr;
    capacity = capacity*2;
}

int main(){ 
    int capacity = 5;
    int* array = new int[capacity]{1, 2, 3, 4, 5};
    double_capacity(array, capacity);
    for (int i=0; i < capacity; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    delete[] array;
}
