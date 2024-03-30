#include<iostream>
using namespace std;

class Player{
    protected:
        int playerID, health;
        string playerName;
    public:
        Player(int ID, string name):playerID(ID),playerName(name),health(100){}
        void decreaseHealth(int n){
            if(health>n)
                health-=n;
            else
                health = 0;
        }
        string getName(){
            return playerName;
        }
        void display(){
            cout<<"Player ID: "<<playerID<<endl;
            cout<<"Player Name: "<<playerName<<endl;
            cout<<"Player Health: "<<health<<endl<<endl;
        }
};
class Weapon{
    string *weaponList;
    int numWeapons;
    public:
        Weapon(string weapons[], int nWeapons){
            if(nWeapons>=5){
                weaponList = new string[nWeapons];
                for(int i=0;i<nWeapons;i++)
                    weaponList[i] = weapons[i];
                numWeapons = nWeapons;
            }
            else
                cout<<"Can't set weapon list, need at least 5 weapons to add"<<endl;
        }
        string use(){
            for(int i=0;i<numWeapons;i++)
                cout<<i+1<<". "<<weaponList[i]<<endl;
            int weaponInd;
            do{
                cout<<"Choose weapon that you want to use: ";
                cin>>weaponInd;
            }while(weaponInd<0 || weaponInd>numWeapons);
            return weaponList[weaponInd-1];
        }
        ~Weapon(){
            delete[] weaponList;
        }

};
class Enemy;
class Character:public Player, public Weapon{
    int level, points;
    string experience;
    static string allExperiences[4];
public:
    Character(int ID, string name, string weapons[],int nWeapon, int lvl=0, int points=0, string exp="Beginner"):Player(ID, name),Weapon(weapons, nWeapon),level(lvl),points(points),experience(exp){}
    void levelUp(){
        points+=10;
        level++;
        for(int i=0;i<3;i++)
            if(experience==allExperiences[i]){
                experience=allExperiences[i+1];
                break;
            }
    }
    void playGame(Enemy &enemy);
    void display(){
        cout<<"Character ID: "<<playerID<<endl;
        cout<<"Character Name: "<<playerName<<endl;
        cout<<"Character Health: "<<health<<endl;
        cout<<"Character Level: "<<level<<endl;
        cout<<"Character Points: "<<points<<endl;
        cout<<"Character Experience: "<<experience<<endl<<endl;
    } 
};
class Enemy:public Player, public Weapon{
    int damage;
    public:
        Enemy(int ID, string name, string weapons[],int nWeapon,int damage):Player(ID,name),Weapon(weapons,nWeapon){
            if(damage>=0 && damage<=10)
                this->damage = damage;
            else
                damage = 5;
        }
        void attack(Character &ch){
            cout<<"Enemy "<<playerName<<" choosing weapon"<<endl;
            string weapon = use();
            cout<<playerName<<" using " <<weapon<<endl<<endl;
            ch.decreaseHealth(damage);
        }
        void display(){
            cout<<"Enemy ID: "<<playerID<<endl;
            cout<<"Enemy Name: "<<playerName<<endl;
            cout<<"Enemy Health: "<<health<<endl;
            cout<<"Enemy Damage: "<<damage<<endl<<endl;
        }

};
void Character::playGame(Enemy &enemy){
    cout<<"Character "<<playerName<<" playing game with enemy "<<enemy.getName()<<endl;
    cout<<"Character choosing weapon: "<<endl;
    string weapon = use();
    cout<<getName()<<" using " <<weapon<<endl<<endl;
    levelUp();
    enemy.decreaseHealth(5);
}
string Character::allExperiences[] = {"Beginner", "Intermediate", "Advanced", "Expert"};
int main() {
    cout<<endl<<endl<<"Coded By: Sahil Latif (23i0763)"<<endl<<endl;
    string w[6] = {"Sword", "Gun", "Bow", "Knife", "Sniper", "Hammer"};
    Character Hero(12, "Superman",w,6);
    Enemy En(10, "V1", w,6,8);
    Hero.display();
    En.display();
    Hero.playGame(En);
    En.attack(Hero);
    Hero.display();
    En.display();
    Hero.playGame(En);
    Hero.display();
    En.display();
    Hero.playGame(En);
    Hero.display();
    En.display();
    Hero.playGame(En);
    Hero.display();
    En.display();
}