#include<iostream>
using std::cin, std::cout, std::endl;

int BLOCKSIZE = 5;

void smart_upsize_capacity(int*& array, int& capacity, int new_size){
    if (new_size < capacity) { 
        throw std::invalid_argument ("new capacity cannot be less then old capacity.");
    }
    int new_capacity = capacity + BLOCKSIZE;
    int* newArr = new int[new_capacity]();
    for(int i = 0; i < capacity; i++){
        newArr[i] = array[i];
    }
    for(int i = capacity; i < new_size; i++){
        newArr[i] = array[0] + i;
    }
    for(int i = new_size; i < new_capacity; i++){
        newArr[i] = 0;
    }
    delete[] array;
    array = newArr;
    capacity = new_capacity;
    cout << "smart sized array" << endl;
}

int main(){ 
    int capacity = 5, newSize=0, oldSize=capacity;
    char it = 'y';
    int* array = new int[capacity]();
    for (int i = 0; i < capacity; i++){
        array[i] = i+1;
        cout << array[i] << " ";
    }
    cout << endl;
    try {
        while (it == 'y') {
            cout << "enter new size desired:";
            cin >> newSize;
            if (newSize > capacity) {
                smart_upsize_capacity(array, capacity, newSize);
            }
            else if ((newSize <= capacity) & (newSize > oldSize)) {
                for (int i = oldSize; i < newSize; i++){
                    array[i] = i+1;
                }
            }
            for (int i=0 ; i < newSize; i++) {
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
