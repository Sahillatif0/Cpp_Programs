#include<iostream>
using namespace std;

class DarazPersonData{
    string firstName, lastName, address, city, state, zip, phone;
    public:
        DarazPersonData(string fN, string lN, string add, string city, string state, string zip, string phone):firstName(fN),lastName(lN),address(add),city(city), state(state), zip(zip), phone(phone){}
        string getFirstName(){return firstName;}
        string getLastName(){return lastName;}
        string getAddress(){return address;}
        string getCity(){return city;}
        string getState(){return state;}
        string getZip(){return zip;}
        string getPhone(){return phone;}
        void setFirstName(string fN){firstName = fN;}
        void setLasttName(string lN){lastName = lN;}
        void setAddress(string add){address = add;}
        void setCity(string city){this->city = city;}
        void setState(string state){this->state = state;}
        void setZip(string zip){this->zip = zip;}
        void setPhone(string phone){this->phone = phone;}
};
class DarazCustomerData{
    static int totalCustomers;
    const int customerNumber;
    int loyaltyPoints;
    public:
        DarazCustomerData(int loyaltyPoints):customerNumber(++totalCustomers){
            if(loyaltyPoints<0){
                cout<<"invalid loyalty points!"<<endl;
                this->loyaltyPoints = 0;
            }
            else    
                this->loyaltyPoints = loyaltyPoints;
        }
        int getCustomerNumber(){return customerNumber;}
        int getLoyaltyPoints(){return loyaltyPoints;}
        void setLoyaltyPoints(int points){loyaltyPoints = points;}
};
class DarazLoyaltyProgram:public DarazPersonData, public DarazCustomerData{
    public:
        DarazLoyaltyProgram(string fN, string lN, string add, string city, string state, string zip, string phone, int points):DarazPersonData(fN,lN,add,city,state, zip, phone), DarazCustomerData(points){}
        void addLoyaltyPoints(int points){
            if(points>0){
                setLoyaltyPoints(getLoyaltyPoints()+points);
                cout<<points<<" Points added"<<endl;
            }
            else
                cout<<"Negative Points can't be added"<<endl;
        }
        void redeemLoyaltyPoints(int points){
            int cPoints = getLoyaltyPoints();
            if(points<=cPoints){
                setLoyaltyPoints(cPoints - points);
                cout<<"discount redeemed for "<<points<<" Points"<<endl;
            }
            else
                cout<<"Not enough loyalty Points to redeem discount"<<endl;
        }
        void displayLoyaltyPoints(){
            cout<<"Customer Name: "<<getFirstName()<<" "<<getLastName()<<endl;
            cout<<"Loyalty Points: "<<getLoyaltyPoints()<<endl;
        }
};
int DarazCustomerData::totalCustomers = 0;
int main() {
    cout<<endl<<endl<<"Coded By: Sahil Latif (23i0763)"<<endl<<endl;
    DarazLoyaltyProgram p1("Sahil", "Latif", "Shah Latif", "Karachi", "Town", "72727", "03123456789",10);
    p1.displayLoyaltyPoints();
    p1.addLoyaltyPoints(20);   
    p1.displayLoyaltyPoints();
    p1.redeemLoyaltyPoints(20);   
    p1.displayLoyaltyPoints();
    p1.redeemLoyaltyPoints(15);   
    p1.displayLoyaltyPoints();
    p1.addLoyaltyPoints(-20);
    p1.displayLoyaltyPoints();
    p1.redeemLoyaltyPoints(15);   
    p1.displayLoyaltyPoints();
}