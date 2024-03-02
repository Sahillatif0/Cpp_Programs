#include<iostream>
using namespace std;
class GraphicsEngine{
    string model;
    public:
        GraphicsEngine(string m):model(m){}
        string getModel(){return model;}
        void setModel(string m){model = m;}
};
class InputHandler{
    string model;
    public:
        InputHandler(string m):model(m){}
        string getModel(){return model;}
        void setModel(string m){model = m;}
};
class PhysicsEngine{
    string model;
    public:
        PhysicsEngine(string m):model(m){}
        string getModel(){return model;}
        void setModel(string m){model = m;}
};
class GameEngine{
    GraphicsEngine ge;
    PhysicsEngine pe;
    InputHandler ih;
    public:
    GameEngine(): ge("GTX 1080"), pe("Havok"), ih("Xbox Controller") {}
    GraphicsEngine getGraphicsEngine(){return ge;}
    PhysicsEngine getPhysicsEngine(){return pe;}
    InputHandler getInputHandler(){return ih;}
    void setGraphicsEngine(GraphicsEngine g){ge = g;}
    void setPhysicsEngine(PhysicsEngine p){pe = p;}
    void setInputHandler(InputHandler i){ih = i;}
};

int main(){
    GameEngine gameEng;
    cout<<"Graphics Engine: "<<gameEng.getGraphicsEngine().getModel()<<endl;
    cout<<"Physics Engine: "<<gameEng.getPhysicsEngine().getModel()<<endl;
    cout<<"Input Handler: "<<gameEng.getInputHandler().getModel()<<endl;
    return 0;   
}