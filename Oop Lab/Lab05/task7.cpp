#include<iostream>
using namespace std;
class MenuItem{
    string name;
    float price;
    public:
        MenuItem(){}
        MenuItem(string n, float p):name(n), price(p){}
        string getName(){return name;}
        float getPrice(){return price;}
        void setName(string n){name = n;}
        void setPrice(float p){price = p;}
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
            cout<<name<<" added in menu"<<endl;
        }
        void removeItem(string name){
            for(int i=0;i<menuItemCount;i++)
                if(menu[i].getName()==name){
                    menu[i] = menu[--menuItemCount];
                    MenuItem *mI = new MenuItem[menuItemCount];
                    for(int j=0;j<menuItemCount;j++)
                        mI[j] = menu[j];
                    menu = mI;
                    cout<<name<<" removed from Menu"<<endl;
                    return;
                }
            cout<<"No item found with this name"<<endl;
        }
        void displayMenu(){
            cout<<"Menu:"<<endl;
            for(int i=0;i<menuItemCount;i++)
                cout<<menu[i].getName()<<": "<<menu[i].getPrice()<<endl;
        }
        MenuItem getMenuItem(int no){
            return menu[no];
        }
        int getMenuItemCount(){
            return menuItemCount;
        }
        ~Menu(){
            delete[] menu;
        }
};
class Payment{
    float amount;
    public:
        Payment(float a):amount(a){}
        float getAmount(){return amount;}
        void setAmount(float a){amount = a;}
        void addBill(float a){amount+=a;}
};
class Order{
    MenuItem* items;
    Payment bill;
    int itemCount;
    public:
        Order():itemCount(0),bill(0){}
        void addItem(string name, Menu menu){
            MenuItem m;
            bool validItem = false;
            for(int mm=0;mm<menu.getMenuItemCount();mm++){
                if(name==menu.getMenuItem(mm).getName()){
                    m = menu.getMenuItem(mm);
                    validItem = true;
                    break;
                }
            }
            if(validItem){
            MenuItem *mI = new MenuItem[itemCount+1];
            for(int i=0;i<itemCount;i++)
                mI[i] = items[i];
            mI[itemCount++] = m;
            items = mI;
            bill.addBill(m.getPrice());
            cout<<name<<" added in order list"<<endl;
            }
            else
                cout<<"Item not found with this name"<<endl;
        }
        void removeItem(string name){
            for(int i=0;i<itemCount;i++)
                if(items[i].getName()==name){
                    bill.addBill(-items[i].getPrice());
                    items[i] = items[--itemCount];
                    MenuItem *mI = new MenuItem[itemCount];
                    for(int j=0;j<itemCount;j++)
                        mI[j] = items[j];
                    items = mI;
                    return;
                }
            cout<<"No item found with this name"<<endl;
        }
        void displayOrder(){
            cout<<"Order:"<<endl;
            for(int i=0;i<itemCount;i++)
                cout<<items[i].getName()<<": "<<items[i].getPrice()<<endl;
            cout<<"Total: "<<bill.getAmount()<<endl;
        }
        ~Order(){
            delete[] items;
        }
};
class Staff{
    string name;
    public:
        Staff(string n):name(n){}
        string getName(){return name;}
        void setName(string n){name = n;}
        void placeOrder(Order o){
            cout<<"Order placed by: "<<name<<endl;
            o.displayOrder();
        }
};
class Restaurant{
    string name;
    Menu menu;
    Staff *staff;
    int staffCount;
    public:
        Restaurant(){}
        Restaurant(Staff *s, string n):name(n),staff(s){}
        void addMenuItem(string name, float price){
            menu.addMenuItem(name, price);
        }
        void removeMenuItem(string name){
            menu.removeItem(name);
        }
        void displayMenu(){
            menu.displayMenu();
        }
        Staff staffMem(int mem){
            return staff[mem];
        }
        Menu getMenu(){
            return menu;
        }
};

int main(){
    Staff staff[3] = {Staff("W1"), Staff("W2"), Staff("W3")};
    Restaurant r1(staff,"Fast Foodies");
    r1.addMenuItem("Burger", 2.5);
    r1.displayMenu();
    r1.addMenuItem("Finger Fries", 2.0);
    r1.displayMenu();
    r1.removeMenuItem("Finger Fries");
    r1.displayMenu();
    r1.addMenuItem("Fries", 2.0);
    r1.displayMenu();
    Order o1;
    o1.addItem("Burger",r1.getMenu());
    o1.addItem("Finger Fries",r1.getMenu());
    o1.addItem("Fries",r1.getMenu());
    r1.staffMem(0).placeOrder(o1);
}