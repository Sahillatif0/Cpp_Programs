#include <iostream>
using namespace std;

class RollerCoaster{
    string name;
    int height, length, capacity, CurrentNumRiders;
    float speed;
    bool RideInProgress;
    public:
        RollerCoaster():name("roller coaster"), height(500), length(2000),capacity(20), RideInProgress(false), CurrentNumRiders(0),speed(0){}
        RollerCoaster(string n, int h, int l, int c):name(n), height(h), length(l),capacity(c>3?((c%2==0 || c%3==0)?c:c+1):3), RideInProgress(false),CurrentNumRiders(0),speed(0){}
        void setName(string s){name = s;}
        void setHeight(int h){height = h;}
        void setLength(int l){length = l;}
        void setCapacity(int c){capacity = c>3?((c%2==0 || c%3==0)?c:c+1):3;}
        void setCurrNumRid(int n){CurrentNumRiders = n;}
        void setSpeed(float s){speed = s;}
        void inProgress(bool i){RideInProgress = i;}
        string getname(){return name;}    
        int getHeight(){return height;}
        int getLength(){return length;}
        int getCapacity(){return capacity;}
        int getCurrNumRid(){return CurrentNumRiders;}
        float getSpeed(){return speed;}
        bool getinProgress(){return RideInProgress;}
        int loadRiders(int rdrs){
            if(RideInProgress)
                return 0;
            int cap = capacity - CurrentNumRiders;
            if(cap>rdrs){
                CurrentNumRiders += rdrs;
                return 0;
            }
            else{
                CurrentNumRiders = capacity;
                return cap;
            }
        }
        int startRide(){
            if(RideInProgress)
                return -1;
            if(capacity - CurrentNumRiders>0)
                return capacity - CurrentNumRiders;
            else{
                RideInProgress = true;
                return 0;
            }
        }
        void stopRide(){
            if(RideInProgress){
                RideInProgress = false;
                cout<<"Ride Stopped"<<endl;
            }
            else
                cout<<"Ride is not in progress"<<endl;
        }
        void unloadPass(){
            if(RideInProgress)
                cout<<"Ride is in progress"<<endl;
            else{
                CurrentNumRiders = 0;
                cout<<"Unloaded"<<endl;
            }
        }
        void accelerateCoaster(string roll){
            int sp = roll[7]-'0'==0?(roll[6]-'0'==0?(roll[5]-'0'==0?(roll[4]-'0'==0?3:roll[4]-'0'):roll[5]-'0'):roll[6]-'0'):roll[7]-'0';
            speed += sp;
        }
        void slowCoaster(string roll){
            int sp = roll[4]-'0'==0?(roll[5]-'0'==0?(roll[6]-'0'==0?(roll[7]-'0'==0?3:roll[7]-'0'):roll[6]-'0'):roll[5]-'0'):roll[4]-'0';
            speed -= sp;
        }

};

void displayRollNum(){
    cout<<"----------------------------"<<endl<<"|  Sahil Latif <<23I0763>> |"<<endl<<"----------------------------"<<endl;
}

int main(){
    displayRollNum();
    RollerCoaster r1, r2("coaster1", 600, 2200, 25);
    string rollno = "23i-0763";
    int rem = r2.loadRiders(12);
    if(rem>0)
        cout<<"capacity filled "<<rem<<" passengers cannot sit"<<endl;
    r2.stopRide();
    int cap = r2.startRide();
    if(cap>0)
        cout<<"Needed "<<cap<<" People more to start the ride"<<endl;
    else{
        cout<<"Ride started"<<endl;
        r2.setSpeed(60);
    }
    r2.loadRiders(cap);
    cap = r2.startRide();
    if(cap>0)
        cout<<"Needed "<<cap<<" People more to start the ride"<<endl;
    else{
        cout<<"Ride started"<<endl;
        r2.setSpeed(60);
    }
    cout<<"Speed: "<<r2.getSpeed()<<endl;
    r2.accelerateCoaster(rollno);
    cout<<"After Speeding Up: "<<r2.getSpeed()<<endl;
    r2.slowCoaster(rollno);
    cout<<"After Speeding Down: "<<r2.getSpeed()<<endl;
    r2.unloadPass();
    r2.stopRide();
    r2.unloadPass();
}