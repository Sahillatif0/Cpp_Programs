#include<iostream>
using namespace std;
class Drone{
    protected:
        float latitude, longitude, altitude, speed;
    public:
        Drone(float lat, float lon, float alti, float speed):latitude(lat), longitude(lon), altitude(alti), speed(speed){}
        void adjustAltitude(float meters){
            altitude = meters;
        }
        void setSpeed(float speed){
            this->speed = speed;
        }
        virtual void takeoff()=0;
        virtual void land() = 0;
        virtual void navigateTo(float lat, float lon, float alt)=0;
        virtual void scanArea(float radius)=0;
};
class RaconDrone: public Drone{
    string cameraResolution;
    float maxFlightTime;
    public:
        RaconDrone(float lat, float lon, float alti, float speed, string cameraResolution, float maxFlightTime):Drone(lat, lon, alti, speed), cameraResolution(cameraResolution), maxFlightTime(maxFlightTime){}
        void takeoff(){
            altitude+=speed;
        }
        void land(){
            while(altitude>0)
                altitude-=speed;
            if(altitude<0)
                altitude = 0;
        }
        bool isGPSsignalLost(){
            float latitude = rand()%(int(this->latitude)+rand()%20);
            float longitude = rand()%(int(this->longitude)+rand()%20);
            if(abs(this->latitude - latitude) > 50 || abs(this->longitude - longitude) > 71)
                return true;
            return false;
        }
        void scanArea(float radius){
            if(isGPSsignalLost())
                cout<<"GPS signal lost"<<endl;
            else{
                cout<<"Scanning the area with radius: "<<radius<<endl;
                cout<<"Found the following objects: "<<endl;
                int nObj = rand()%20;
                for(int i=0;i<nObj;i++){
                    float latitude = rand()%(int(this->latitude)+rand()%int(radius));
                    float longitude = rand()%(int(this->longitude)+rand()%int(radius));
                    cout<<"Object "<<i+1<<": "<<endl;
                    cout<<"Latitude: "<<latitude<<endl;
                    cout<<"Latitude: "<<longitude<<endl<<endl;
                }
            }
        }
        void navigateTo(float lat, float lon, float alt){
            if(alt==altitude)
                alt = rand()%(int(altitude))+altitude;
            cout<<"Differences: "<<endl;
            cout<<"Latitude: "<<abs(latitude - lat)<<endl;
            cout<<"Longitude: "<<abs(longitude - lon)<<endl;
            cout<<"Altitude: "<<abs(altitude - alt)<<endl;
            cout<<endl<<"Time to reach there: "<< speed/abs(altitude-alt)<<endl;
            if(isGPSsignalLost())
                cout<<"GPS signal lost"<<endl;
            else{
                latitude = lat, longitude = lon, altitude = alt;
                cout<<"Navigated to the given coordinates"<<endl;
            }
        }

};
int main() {
    cout<<"=============================="<<endl
        <<"|   Sahil Latif <23I0763>     |"<<endl
        <<"=============================="<<endl<<endl;
    RaconDrone rd(0, 0, 0, 10, "4k", 30);
    rd.takeoff();
    rd.navigateTo(10, 10, 10);
    rd.scanArea(10);
    rd.land();
    return 0;
}