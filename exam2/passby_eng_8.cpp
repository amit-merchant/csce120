#include <iostream>
std::string func(char p, char *q, char *&r) {
    std::string s = " ";
    *q = 'q';
    r = q;
    p = 'p';
    q = &p;
    s += p;
    s += *q;
    s += *r;
    return s;
}
int main() {
    char a = 'a';
    char b = 'b';
    char *c = &a;
    std::cout << func(a, &b, c) << a;
    return 0;
}
