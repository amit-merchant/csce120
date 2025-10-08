#include <iostream>
class Circle { 
    double rad; 
    public: Circle(double v) : rad(v) {}; 
    friend double area (const Circle& c); };
class Rect   { 
    double w, h; 
    public: Rect(double w, double h) : w(w), h(h) {}; 
    friend double area (const Rect& r); };

// Non-member function overloads 
double area(const Circle& c) { return 3.14 * c.rad * c.rad; }
double area(const Rect&   r) { return r.w * r.h; }

// A non-member with a different signature
double area(double width, double height) { return width * height; }

int main() {
    Circle c(1.0);
    Rect   r{3.0, 4.0};
    std::cout << area(c) << " ";        // picks area(const Circle&)
    std::cout << area(r) << " ";        // picks area(const Rect&)
    std::cout << area(5.0, 6.0) << " "; // picks area(double,double)
}
