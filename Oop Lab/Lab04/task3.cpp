#include <iostream>
using namespace std;

class Gym {
    string name,address,phoneNumber;
    double membershipPricePerMonth;
    string *servicesList;
    int totalServices;

public:
    Gym(int size) {
        totalServices = size;
        servicesList = new string[size];
    }

    ~Gym() {
        delete[] servicesList;
    }

    void add_service(string service) {
        totalServices++;
        string* newServices = new string[totalServices];
        for (int i = 0; i < totalServices-1; i++) {
            newServices[i] = servicesList[i];
        }
        delete[] servicesList;
        servicesList = newServices;
        servicesList[totalServices-1] = service;
        cout<<"Service Added"<<endl;
    }

    void get_services(){
        cout<<"\tServices\n\n";
        for(int i=0;i<totalServices;i++){
            cout<<servicesList[i]<<endl;
        }
    }

    void set_name(string name) {
        this->name = name;
    }

    void set_address(string address) {
        this->address = address;
    }

    void set_phoneNumber(string phoneNumber) {
        this->phoneNumber = phoneNumber;
    }

    void set_membershipPricePerMonth(double membershipPricePerMonth) {
        this->membershipPricePerMonth = membershipPricePerMonth;
    }

     string get_name() {
        return name;
    }

     string get_address() {
        return address;
    }

     string get_phoneNumber() {
        return phoneNumber;
    }

    double get_membershipPricePerMonth() {
        return membershipPricePerMonth;
    }
};

int main() {
    Gym gym(3);
    gym.set_name("Gym XYZ");
    gym.set_address("123 Main Street");
    gym.set_phoneNumber("123-456-7890");
    gym.set_membershipPricePerMonth(20.0);
    gym.add_service("Cardio");
    gym.add_service("Strength Training");
    gym.add_service("Yoga");

     cout << "Name: " << gym.get_name() <<  endl;
     cout << "Address: " << gym.get_address() <<  endl;
     cout << "Phone Number: " << gym.get_phoneNumber() <<  endl;
     cout << "Membership Price Per Month: " << gym.get_membershipPricePerMonth() <<  endl;
        gym.get_services();
     cout <<  endl;

    return 0;
}