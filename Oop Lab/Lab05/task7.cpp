#include<iostream>
using namespace std;
class MenuItem{
    string name;
    float price;
    public:
        MenuItem(string n, float p):name(n), price(p){}
};
class Menu{
    MenuItem* menu;
    int menuItemCount;
    public:
        Menu():menuItemCount(0){}
        void addMenuItem(string name, float price){
            MenuItem m(name, price);
            MenuItem *mI = new MenuItem[menuItemCount+1];
            for(int i=0;i<menuItemCount;i++)
                mI[i] = menu[i];
            mI[menuItemCount++] = m;
            menu = mI;
        }
        void removeItem(string name){
            for(int i=0;i<menuItemCount;i++)
                if(menu[i].name==name)[
                    menu[i] = menu[menuItemCount-1];
                    menu = new MenuItem[menuItemCount-1];
                ]
        }
        void displayMenu(){
            cout<<"Menu:"<<endl
            for(int i=0;i<menuItemCount;i++)
                cout<<menu[i].name<<": "<<menu[i].price<<endl;
        }

};
class Staff{


};
class Payment{
};
class Restaurant{

};

int main(){
    
}