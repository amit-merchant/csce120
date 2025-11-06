#include <iostream>

class IntVec {
    int*   data_; //use of trailing _ is used to signify members of a class
    size_t size_; //size_t is same as unsigned integer
    size_t cap_;

    // this is our standard upsize, private helper
    void reallocate(size_t newCap) {
        int* new_data = new int[newCap];
        for (size_t i = 0; i < size_; ++i) new_data[i] = data_[i];
        delete[] data_;
        data_ = new_data;
        cap_   = newCap;
        std::cout << "[grow] capacity -> " << cap_ << std::endl;
    }

public:
    // default constructir
    IntVec() : data_(nullptr), size_(0), cap_(0) {}

    // destructor (free heap), will talk more in rule of 3
    ~IntVec() { delete[] data_; }

    // copy constructor (deep copy)
    IntVec(const IntVec& other) : data_(nullptr), size_(other.size_), cap_(other.size_) {
        if (cap_ > 0) {
            data_ = new int[cap_];
            for (size_t i = 0; i < size_; ++i) data_[i] = other.data_[i];
        }
    }

    // push_back with doubling growth
    void push_back(int v) {
        if (size_ == cap_) reallocate(cap_ ? cap_ * 2 : 1);
        data_[size_++] = v;
        std::cout << "added new element to end of vector" << std::endl;
    }

    // reserve capacity (no shrink here for simplicity)
    void reserve(size_t n) { if (n > cap_) reallocate(n); }

    // clear (keep capacity
    void clear() { size_ = 0; }

    // pop_back (no underflow checks for simplicity)
    void pop_back() { if (size_ > 0) --size_; }

    // element access (unchecked)
    int& operator[](size_t i) { return data_[i]; }
    const int& operator[](size_t i) const { return data_[i]; }

    // access with boundary checking
    int at(size_t i) const {
        if (i >= size_) throw std::out_of_range("out of range access");
        return data_[i];
    }

    size_t size() const { return size_; }
    size_t capacity() const { return cap_; }
};

int main() {
    IntVec v;
    for (int i = 0; i < 10; ++i) v.push_back(i * 10);

    std::cout << "size=" << v.size() << " cap=" << v.capacity() << std::endl;
    for (size_t i = 0; i < v.size(); ++i) std::cout << v[i] << " ";
    std::cout << "\n";

    IntVec w = v;           // copy construct
    w.pop_back();
    w[0] = 999;

    std::cout << "v[0]=" << v[0] << " (unchanged), w[0]=" << w[0] << " (deep copy)\n";
    return 0;
}
