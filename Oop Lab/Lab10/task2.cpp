#include<iostream>
using namespace std;
class Character{
    int health, strength, speed;
    public:
        Character(int h, int s, int sp):health(h), strength(s), speed(sp){}
        void print(){
            cout<<"Health: "<<health<<endl;
            cout<<"Strength: "<<strength<<endl;
            cout<<"Speed: "<<speed<<endl;
        }
        Character operator+(Character &c){
            Character temp(health+c.health, strength+c.strength, speed+c.speed);
            return temp;
        }
        friend bool compareCharacters(Character &c1, Character &c2);
        friend class Game;

};

class Game{
    Character *currChar;
    public:
        Game(Character& p):currChar(&p){}
        void setCurrentChar(Character* c){
            currChar = c;
        }
};
bool compareCharacters(Character &ch1, Character &ch2){
    if(ch1.health > ch2.health && ch1.strength > ch2.strength && ch1.speed > ch2.speed)
        return true;
    else 
        return false;
}

int main() {
    Character c1(100, 50, 30);
    Character c2(90, 40, 20);
    c1.print();
    c2.print();
    if(compareCharacters(c1, c2))
        cout<<"Character 1 is better than Character 2"<<endl;
    else
        cout<<"Character 2 is better than Character 1"<<endl;
    Game g(c1);
    g.setCurrentChar(&c2);
    Character c3 = c1 + c2;
    c3.print();
    return 0;   
}