#include<iostream>
#include<vector>
using namespace std;

struct var{
    int n;
    string s;
};

void f(vector<var> v, vector<var> &r){
    int size = v.size();
    int j = 0;
    for (size_t i=0; i<size; i++){
        j = size-i-1;
        v.at(i).n = v.at(j).n;
        r.at(i).s = r.at(j).s;
    }
    r.push_back({102,"black"});
}

int main(){
    vector<var> foo{{100,"blue"},{101,"orange"}};
    f(foo, foo);
    for (size_t i=0; i<foo.size(); i++){
        cout << foo.at(i).n << " " << foo.at(i).s << " ";
    }    
}
