#include <iostream>
using namespace std;

class Vehicle{
    protected:
        int year;
        string make, model;
    public: 
        Vehicle(string mk,string mdl,int y): make(mk), model(mdl), year(y){}
};
class Car: public Vehicle{
    protected:
        int nDoors,fuelEff;
    public: 
        Car(string mk,string mdl,int y, int nD, int eff): Vehicle(mk, mdl, y), nDoors(nD), fuelEff(eff){}
};
class ElectricCar: public Car{
    int batteryLife;
    public:
        ElectricCar(string mk,string mdl,int y, int nD, int eff, int bL): Car(mk,mdl,y,nD,eff),batteryLife(bL){}
        void display(){
            cout<<"Electric Car Details: "<<endl;
            cout<<"make: "<<make<<endl;
            cout<<"model: "<<model<<endl;
            cout<<"Year: "<<year<<endl;
            cout<<"No of Door: "<<nDoors<<endl;
            cout<<"Fuel Effiency: "<<fuelEff<<endl;
            cout<<"Battery Life: "<<batteryLife<<endl;
        }
};
int main(){
    ElectricCar c("ke","Tesla", 2016, 4,76,88);
    c.display();

}