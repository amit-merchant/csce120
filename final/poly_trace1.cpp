#include <iostream>
using namespace std;

class car{
	public:
    		string brand;
			int mileage;
    		car(): brand(""), mileage(100) {}
    		virtual int odo(){
        		return mileage;
    		}
};
class Toyota : public car{
	public:
    		string model;
    		Toyota(string s): model(s) {}
    		int odo() override{
        		return 0;
    		}
};
int main(){
	Toyota MyToyota("Corolla");
    car HisCar = MyToyota;
	HisCar.brand = "Toyota";
	car& HerCar = MyToyota;
    car* YourCar = &MyToyota;
	cout << "My: " << MyToyota.model << "," << MyToyota.odo() << endl;
	cout << "His: " << HisCar.brand << "," << HisCar.odo() << endl;
	cout << "Her: " << HerCar.brand << "," << HerCar.odo() << endl;
	cout <<	"Your: " << YourCar->brand << "," << YourCar->odo() << endl;
}
