#include <iostream>

template<typename T>
class vec {
    T*   data_; 
    size_t size_; //size_t is same as unsigned integer
    size_t cap_;

    // this is our standard upsize, private helper
    void reallocate(size_t newCap) {
        T* new_data = new T[newCap];
        for (size_t i = 0; i < size_; ++i) new_data[i] = data_[i];
        delete[] data_;
        data_ = new_data;
        cap_   = newCap;
        // std::cout << "grow capacity -> " << cap_ << std::endl;
    }

public:
    // default constructor
    vec() : data_(nullptr), size_(0), cap_(0) {}

    // destructor 
    ~vec() { delete[] data_; }

    // copy constructor (deep copy)
    vec(const vec& other) : data_(nullptr), size_(other.size_), cap_(other.size_) {
        if (cap_ > 0) {
            data_ = new T[cap_];
            for (size_t i = 0; i < size_; ++i) data_[i] = other.data_[i];
        }
    }

    // push_back with doubling growth if needed
    void push_back(T v) {
        if (size_ == cap_) reallocate(cap_ ? cap_ * 2 : 1);
        data_[size_++] = v;
    }

    // reserve capacity (no shrink here for simplicity)
    void reserve(size_t n) { if (n > cap_) reallocate(n); }

    // clear (keep capacity)
    void clear() { size_ = 0; }

    // pop_back (no underflow checks for simplicity)
    void pop_back() { if (size_ > 0) --size_; }

    // element access (unchecked)
    T& operator[](size_t i) { return data_[i]; }
    const T& operator[](size_t i) const { return data_[i]; }

    // access with boundary checking
    T at(size_t i) const {
        if (i >= size_) throw std::out_of_range("out of range access");
        return data_[i];
    }

    size_t size() const { return size_; }
    size_t capacity() const { return cap_; }
};

int main() {
    vec<int> v;
    for (int i = 0; i < 5; ++i) v.push_back(i);
    for (size_t i = 0; i < v.size(); ++i) std::cout << v[i] << " ";
    std::cout << "\n";

    vec<char> v1;
    char c = 'a';
    for (int i = 0; i < 5; ++i) v1.push_back(c+i);
    for (size_t i = 0; i < v1.size(); ++i) std::cout << v1[i] << " ";
    std::cout << "\n";

    vec<float> v2;
    float f = 1.01;
    for (int i = 0; i < 5; ++i) v2.push_back(f*(i+1));
    for (size_t i = 0; i < v2.size(); ++i) std::cout << v2[i] << "   ";
    std::cout << "\n";
    return 0;
}
