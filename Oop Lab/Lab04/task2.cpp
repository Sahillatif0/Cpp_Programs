#include <iostream>
#include<initializer_list>
using namespace std;

class Office{
    string Location, furniture[3];
    int SeatingCapacity;
    public:
    Office(){
        Location = "";
        SeatingCapacity = 0;
        furniture[0] =  "Desk";
        furniture[1] =  "Chair";
        furniture[2] =  "Filing Cabinet";
    }
    Office(string l):Location(l){
        SeatingCapacity = 0;
        furniture[0] =  "Desk";
        furniture[1] =  "Chair";
        furniture[2] =  "Filing Cabinet";
    }
    Office(string l, int cap):Location(l),SeatingCapacity(cap){
        furniture[0] =  "Desk";
        furniture[1] =  "Chair";
        furniture[2] =  "Filing Cabinet";
    }
    Office(string l, int cap,  string f1):Location(l),SeatingCapacity(cap){
        furniture[0] = f1;
    }
    string getLocation(){
        return Location;
    }
    void print(){
        cout<<"Location: "<< Location<<endl;
        cout<<"SeatingCap: "<< SeatingCapacity<<endl;
        cout<<"Furniture: "<<furniture[0]<<endl;
    }
};

int main(){
    string f[3] = {"Table","Computer","Printer"};
    Office o1(), o2( "Karachi" ), o3( "Branch", 5 ),o4("din", 4, f[0]) ;
    o3.print();
    cout<<"created Object";
}