#include<iostream>
using std::cin, std::cout, std::endl;

//expand capacity of array 
void dnsize_capacity(int*& array, int& capacity, int new_capacity){
    if (new_capacity > capacity) { //handle new_capacity < capacity
        throw std::invalid_argument ("new capacity cannot be greater then old capacity.");
    }
    int* newArr = new int[new_capacity]();
    for(int i = 0; i < new_capacity; i++){
        newArr[i] = array[i];
    }
    delete[] array;
    array = newArr;
    capacity = new_capacity;
}

int main(){ 
    int capacity = 5, new_capacity = 4;
    int* array = new int[capacity]{1, 2, 3, 4, 5};
    try {
        dnsize_capacity(array, capacity, new_capacity);
        for (int i=0; i < capacity; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    } 
    catch (const std::invalid_argument &e) {
        cout << e.what() << endl;
    }
    delete[] array;
}
