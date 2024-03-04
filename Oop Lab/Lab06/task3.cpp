#include<iostream>
using namespace std;

class Appointment{
    int appointmentId;
    string serviceType;
    double cost;
    static double totalEarning, avgCost;
    static int totalAppointments;
    public:
        string customerName;
        Appointment(int id, string name, string type, double c): appointmentId(id), customerName(name), serviceType(type), cost(c){
            totalEarning+=cost;
            totalAppointments++;
            avgCost = totalEarning/totalAppointments;
        }
        void display(){
            cout<<"Appointment ID: "<<appointmentId<<endl;
            cout<<"Customer Name: "<<customerName<<endl;
            cout<<"Service Type: "<<serviceType<<endl;
            cout<<"Cost: "<<cost<<endl;
        }
        static void setTotalEarning(double e){
            totalEarning = e;
        }
        static void setAvgCost(double a){
            avgCost = a;
        }
        static void setTotalAppointments(int t){
            totalAppointments = t;
        }
        static double getTotalEarning(){
            return totalEarning;
        }
        static double getAvgCost(){
            return avgCost;
        }
        static int getTotalAppointments(){
            return totalAppointments;
        }
        static double calcAvg(){
            avgCost = totalEarning/totalAppointments;
            return avgCost;
        }
        int getAppointmentId(){
            return appointmentId;
        }
        string getServiceType(){
            return serviceType;
        }
        double getCost(){
            return cost;
        }
        void setCost(double c){
            totalEarning-=cost;
            cost = c;
            totalEarning+=cost;
        }
        
};

double Appointment::totalEarning = 0.0;
double Appointment::avgCost = 0.0;
int Appointment::totalAppointments = 0;
int main() {
    Appointment a1(1, "Ali", "Haircut", 1000), a2(2, "Ahmed", "Shave", 500), a3(3, "Asad", "Massage", 1500);
    a1.display();
    cout << "\n\n";
    a2.display();
    cout << "\n\n";
    a3.display();
    cout << "\n\n";
    cout<<"Total Appointments: "<<Appointment::getTotalAppointments()<<endl;
    cout<<"Total Earning: "<<Appointment::getTotalEarning()<<endl;
    cout<<"Avg Cost: "<<Appointment::calcAvg()<<endl;
}