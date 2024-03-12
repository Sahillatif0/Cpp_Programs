#include<iostream>
using namespace std;
class Mammals{
    public:
        Mammals(){
            cout<<"I am constructor of Mammals Class"<<endl;
        }
        ~Mammals(){
            cout<<"I am destructor of Mammals Class"<<endl;
        }
        void print(){
            cout<<"I am mammal"<<endl;
        }
};
class MarineAnimals{
    public:
        MarineAnimals(){
            cout<<"I am constructor of MarineAnimals Class"<<endl;
        }
        ~MarineAnimals(){
            cout<<"I am destructor of MarineAnimals Clas"<<endl;
        }
        void print(){
            cout<<"I am MarineAnimals"<<endl;
        }
};
class BlueWhale:public Mammals, public MarineAnimals{
    public:
        BlueWhale(){
            cout<<"I am constructor of BlueWhale Class"<<endl;
        }
        ~BlueWhale(){
            cout<<"I am destructor of BlueWhale Class"<<endl;
        }
        void print(){
            cout<<"I am BlueWhale. I belong to both the categories: Mammals as well as Marine Animals"<<endl;
        }
};

int main(){
    Mammals m;
    MarineAnimals mA;
    BlueWhale bW;
    m.print();
    mA.print();
    bW.print();
    bW.Mammals::print();    
    bW.MarineAnimals::print();
}