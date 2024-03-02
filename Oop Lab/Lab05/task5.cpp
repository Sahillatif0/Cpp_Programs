#include <iostream>
using namespace std;

class Engine{
    string model;
    int power;
    public:
        Engine(string m, int p):model(m),power(p){}
        string getModel(){return model;}
        int getPower(){return power;}
        void setModel(string m){model = m;}
        void setPower(int po){power=po;}
};
class Wheel{
    string model;
    int length;
    public:
        Wheel(string m, int l):model(m), length(l){}
        string getModel(){return model;}
        int getLength(){return length;}
        void setModel(string m){model = m;}
        void setLength(int l){length = l;}
};
class Headlight{
    string model;
    int brightness;
    public:
        Headlight(string m, int b):model(m), brightness(b){}
        string getModel(){return model;}
        int getBrightness(){return brightness;}
        void setModel(string m){model = m;}
        void setBrightness(int b){brightness = b;}
};
class Steering{
    string model;
    public:
        Steering(string m){model = m;}
        string getModel(){return model;}
        void setModel(string m){model = m;}
};

class Car{
    string model,color;
    Engine *engine;
    Wheel *wheels;
    Headlight *headlights;
    Steering *steering;
    public:
        Car(string m, string c, Engine *engine, Wheel *whs, Headlight *hls, Steering *str):model(m), color(c), engine(engine),wheels(whs),headlights(hls),steering(str){}
        void setModel(string m){model = m;}
        void setColor(string c){color = c;}
        string getModel(){return model;}
        string getColor(){return color;}
        Engine getEngine(){return *engine;}
        Wheel *getWheels(){return wheels;}
        Headlight *getHeadLights(){return headlights;}
        Steering getSteering(){ return *steering;}
        void displayDetails(){
            cout<<"Model: "<<model<<endl<<"Color: "<<color<<endl<<"Engine Model"<<engine->getModel()<<endl<<"Engine Power: "<<engine->getPower()<<endl<<"Wheels: "<<wheels[0].getModel()<<endl<<"Lights: "<<headlights[0].getBrightness()<<endl<<"Steering"<<steering->getModel()<<endl;
        }
};

int main(){
    Engine e1("model1",120);
    Wheel wheels[4] = {Wheel("w1", 10), Wheel("w1", 10),Wheel("w1", 10),Wheel("w1", 10)};
    Headlight headlights[2] = {Headlight("h12", 85), Headlight("h12", 50)};
    Steering s1("ds");
    Car c1("toyota", "black", &e1,wheels,headlights,&s1);
    c1.displayDetails();

}