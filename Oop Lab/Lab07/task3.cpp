#include <iostream>
using namespace std;

class Position{
    protected:
        int x,y,z;
    public:
        Position(int x, int y, int z):x(x), y(y),z(z){}
        int getX(){return x;}
        int getY(){return y;}
        int getZ(){return z;}
        void setX(int x){this->x = x;}
        void setY(int y){this->y = y;}
        void setZ(int z){this->z = z;}
};
class Health{
    protected:
        int health;
    public:
        Health(int h):health(h){}
        int getHealth(){return health;}
        void setHealth(int h){health = h;}
};

class Character:public Position, public Health{
    string name;
    int damage;
    public: 
        Character(int x, int y, int z, int h, int d, string n): Position(x,y,z),Health(h),damage(d),name(n){}
        void display(){
            cout<<"Character Details: "<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Position(x,y,z): ("<<x<<", "<<y<<", "<<z<<")"<<endl;
            cout<<"Health: "<<health<<endl;
            cout<<"Damage: "<<damage<<endl;
        }
};

int main(){
    Character c(4,5,6,76,86,"DeadPool");
    c.display();

}