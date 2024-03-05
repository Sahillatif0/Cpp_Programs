#include <iostream>
using namespace std;

class Character{
    protected:
        int health, damage;
    public:
        Character(int h, int d):health(h),damage(d){}
        void display(){
            cout<<"Character Details: "<<endl;
            cout<<"Health: "<<health<<endl;
            cout<<"Damage: "<<damage<<endl;
        }

};
class Enemy: public Character{
    int KillLevel;
    public:
        Enemy(int h, int d, int l):Character(h,d),KillLevel(l){}
        void display(){
            cout<<"Enemy Details: "<<endl;
            cout<<"Health: "<<health<<endl;
            cout<<"Damage: "<<damage<<endl;
            cout<<"Kill Level: "<<KillLevel<<endl;
        }
};
class Player: public Character{
    protected:
        int swordLevel, kills;
    public:
        Player(int h, int d, int sl, int k):Character(h,d),swordLevel(sl),kills(k){}
        void display(){
            cout<<"Player Details: "<<endl;
            cout<<"Health: "<<health<<endl;
            cout<<"Damage: "<<damage<<endl;
            cout<<"Kills: "<<kills<<endl;
            cout<<"swordLevel: "<<swordLevel<<endl;
        }
};
class Wizard: public Player{
    int magicPower;
    string spells;
    public:
        Wizard(int h, int d, int sl, int k,int mP, string sp):Player(h,d,sl,k),magicPower(mP),spells(sp){}
        void display(){
            cout<<"Player Details: "<<endl;
            cout<<"Health: "<<health<<endl;
            cout<<"Damage: "<<damage<<endl;
            cout<<"Kills: "<<kills<<endl;
            cout<<"swordLevel: "<<swordLevel<<endl;
            cout<<"magicPower: "<<magicPower<<endl;
            cout<<"Spells: "<<spells<<endl;
        }
};
int main(){
    Wizard w(80,95,3,122,98,"hide, kill");
    w.display();

}