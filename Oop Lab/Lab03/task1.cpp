#include<iostream>
using namespace std;

class BoardMarker{
    string company, color;
    bool refillable, inkfilled;

    public:
        void setCompany(string c){company = c;}
        void setColor(string col) {color=col;}  
        void setRefillable(bool r) {refillable=r;}   
        void setInkFilled(bool i) {inkfilled=i;}  
        
        string getCompany() const {return company;} 
        string getColor()const { return color;}    
        bool isRefillable() const {return refillable;}     
        bool isInkFilled() const {return inkfilled;}

        void writeWiithMarker(string toWrite){
            if(isInkFilled())
                cout<<toWrite;
            else
                cout<<"The marker is out of ink.\n";
        }

        void refillMarker(){
            if(!isRefillable())
                cout << "This marker cannot be refilled." << endl;
            else{
                setInkFilled(true);
                cout << "The marker has been refilled with ink." << endl;
            }
        }
        
        void MarkerInfo(){
            cout << "Company: " << company << endl<< "Color: " << color<<endl<<"IsRefillable: "<<refillable<<endl<<"InkFilled: "<<inkfilled<<endl<<endl;
        }
};

int main(){
    BoardMarker marker1;
    marker1.setCompany("Dollar");
    marker1.setColor("Blue");
    marker1.setRefillable(false);
    marker1.setInkFilled(true);
    marker1.MarkerInfo();
    marker1.writeWiithMarker("I am filled, I can write\n");
    marker1.setInkFilled(false);
    marker1.writeWiithMarker("Let me try to write now\n");
    marker1.refillMarker();
    marker1.writeWiithMarker("Umm, I can't refill\n");
    marker1.setRefillable(true);
    marker1.refillMarker();
    marker1.writeWiithMarker("Now I can write again!\n");
}