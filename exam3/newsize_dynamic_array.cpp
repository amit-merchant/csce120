#include<iostream>
using std::cin, std::cout, std::endl;

void upsize_capacity(int*& array, int& capacity, int new_capacity){
    if (new_capacity < capacity) { //handle new_capacity > capacity
        throw std::invalid_argument ("new capacity cannot be less then old capacity.");
    }
    int* newArr = new int[new_capacity]();
    for(int i = 0; i < capacity; i++){
        newArr[i] = array[i];
    }
    for(int i = capacity; i < new_capacity; i++){
        newArr[i] = array[0] + i;
    }
    delete[] array;
    array = newArr;
    capacity = new_capacity;
}

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
    int capacity = 5, newSize=0;
    char it = 'y';
    int* array = new int[capacity]{1, 2, 3, 4, 5};
    try {
        while (it == 'y') {
            cout << "enter new size desired:";
            cin >> newSize;
            if (newSize > capacity) {
                upsize_capacity(array, capacity, newSize);
            }
            else if (newSize < capacity) {
                dnsize_capacity(array, capacity, newSize);
            }
            for (int i=0; i < capacity; i++) {
                cout << array[i] << " ";
            }
            cout << endl;
            cout << "do you want to change the size of the arrray? (y/n):";
            cin >> it;
        }
    } 
    catch (const std::invalid_argument &e) {
        cout << e.what() << endl;
    }
    delete[] array;
}
