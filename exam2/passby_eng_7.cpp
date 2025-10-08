#include<iostream>
#include<vector>
using namespace std;

struct var{
    int n;
    string s;
};

void f(var v[], var r[], int len){
    for (size_t i=0; i<len; i++){
        int j = len-i-1;
        v[i].n = r[j].n;
        v[i].s = r[j].s;
    }
}

int main(){
    int len = 2;
    var foo[len] = {{100,"blue"},{101,"orange"}};
    f(foo, foo, len);
    for (size_t i=0; i<len; i++){
        cout << foo[i].n << " " << foo[i].s << " ";
    }    
}
