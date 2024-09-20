#include<iostream>
#include<fstream>
using std::ifstream, std::ofstream, std::cin, std::cout;
using std::fstream, std::endl, std::string, std::ios;

// imrpoved code, allows file of variable size to be read in
int main(){
    const int CAPACITY = 20;
    fstream fs("amtrak.txt", ios::in | ios::out | ios::app);
    ifstream ifs("code.txt");
    ofstream ofs("amtrak_coded.txt");
    
    struct station { 
        string city = "";
        int code = 0;
    };

    station amtrak[CAPACITY];
    int i = 0;
     
    while (fs >> amtrak[i].city) {
        ifs >> amtrak[i].code; 
        i++;
    }
    int max_cities = i;
    for (i=0; i < max_cities; i++) {
        cout << amtrak[i].city << " " << amtrak[i].code << endl;
    }
    
    for (i=0; i < max_cities; i++) {
        fs << amtrak[i].city << " " << amtrak[i].code << endl;
    }
}
