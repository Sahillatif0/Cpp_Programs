#include <iostream>
using namespace std;
class SuperMan{
    const int health;
    const int power;
    public:
        SuperMan(int h, int p):health(h),power(p){}
        void displaySuperManInfo(){
            cout<<"Superman Power: "<<power<<endl;
            cout<<"Superman Health: "<<health<<endl;
        }
        // void setHealth(int h){health = h;}//Assignment of read only variable error
        // void setPower(int p){power = p;}//Will show error
};
int main(){
    SuperMan s1(80,70);
    s1.displaySuperManInfo();
    // s1.setHealth(20);
    // s1.setPower(30);
}