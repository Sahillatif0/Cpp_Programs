#include<iostream>
#include<time.h>
using namespace std;
class BOGOCoupon{
    string code, restaurant_code;
    struct tm valid_from, valid_until;
    public:
        BOGOCoupon(){}
        BOGOCoupon(string c, struct tm vf, struct tm vu, string rc):code(c), valid_from(vf), valid_until(vu), restaurant_code(rc){}
        string getCode(){return code;}
        bool isValid(string rc){
            time_t ct = time(0);
            time_t vu = mktime(&valid_until);
            if((vu - ct)>0 && rc==restaurant_code)
                return true;
            return false;
        }
};
class User{
    string name, mobile;
    int age;
    BOGOCoupon* coupon_codes;
    BOGOCoupon* redemeed_coupon_codes;
    int coupon_codes_count,redeemed_coupon_count;
    public:
        User():name("Unknown"), age(19), mobile(""),coupon_codes_count(0),redeemed_coupon_count(0){}
        User(string n, int a, string m):name(n),mobile(m), age(a),coupon_codes_count(0),redeemed_coupon_count(0){}

        void accumulate_coupon(string c, time_t vf, time_t vu, string rc){
            struct tm vft=(*localtime(&vf)), vut=(*(localtime(&vu))); 
            BOGOCoupon newCop(c,vft,vut,rc);
            BOGOCoupon* new_coupon_codes = new BOGOCoupon[coupon_codes_count+1];
            for(int i=0;i<coupon_codes_count;i++)
                new_coupon_codes[i] = coupon_codes[i];
            new_coupon_codes[coupon_codes_count++] = newCop;
            coupon_codes = new_coupon_codes;
            cout<<"Coupon Accumulated"<<endl;
        }
        bool has_valid_coupon(string rc){
            for(int i=0;i<coupon_codes_count;i++){
                if(coupon_codes[i].isValid(rc))
                    return true;
            }
            return false;
        }
        bool redeem_coupon(string code, string rc){
            for(int i=0;i<redeemed_coupon_count;i++){
                if(redemeed_coupon_codes[i].getCode()==code){
                    cout<<"Code already redeemed"<<endl;
                    return false;
                }
            }
            for(int i=0;i<coupon_codes_count;i++){
                if(coupon_codes[i].getCode()==code && coupon_codes[i].isValid(rc)){
                    cout<<"Coupon is valid"<<endl;
                    BOGOCoupon* new_cop = new BOGOCoupon[redeemed_coupon_count+1];
                    for(int j=0;j<redeemed_coupon_count;j++)
                        new_cop[j] = redemeed_coupon_codes[j];
                    new_cop[redeemed_coupon_count++] = coupon_codes[i];
                    redemeed_coupon_codes = new_cop;
                    return true;
                }
            }
            

        }

};
class Restaurant{
    string name, location, restaurant_code;
    string *menu;
    float *price_list, discout;
    int menuItems;
    BOGOCoupon* valid_coupon_codes;
    int valid_coupon_codes_count;
    static int coupon_redeemed_count;
    public:
        Restaurant(){
            name = "Karachi Karahi";
            location = "Karahi";
            restaurant_code = "KK";
            menuItems = 3;
            menu = new string[menuItems];
            price_list = new float[menuItems];
            menu[0] = "Zinger Burger";
            menu[1] = "Fried Chicken";
            menu[2] = "Chicken Wings";
            price_list[0] = 250;
            price_list[1] = 500;
            price_list[2] = 300;
            valid_coupon_codes_count = 0;
            discout = 0.0;
        }
        Restaurant(string n, string l,string code, int mI, string *m, float *p):name(n), location(l),restaurant_code(code), menuItems(mI), menu(m),price_list(p),valid_coupon_codes_count(0),discout(0.0){}   
        void setName(string n){name = n;}
        string getName() {return name;}
        string getLocation() { return location;}
        int getMenuItemsCount() {return menuItems;}
        string getResturantCode(){return restaurant_code;}
        void displayMenu(){
            cout<<"Menu:"<<endl;
            for(int i = 0; i < menuItems; i++){
                cout<<i+1<<". "<<menu[i]<<" : "<<price_list[i]<<endl;
            }
        }
        void addCoupon(string code, time_t vs,time_t vu){
            struct tm vst=(*localtime(&vs)),vut=(*localtime(&vu));
            BOGOCoupon* new_coupons = new BOGOCoupon[valid_coupon_codes_count+1];
            for(int i=0;i<valid_coupon_codes_count;i++)
                new_coupons[i] = valid_coupon_codes[i];
            new_coupons[valid_coupon_codes_count++] = BOGOCoupon(code,vst,vut,restaurant_code);
            valid_coupon_codes = new_coupons;
        }
        float generateBill(string order[], int *quantity, int n){
            float bill = 0.0;
            for(int i=0;i<n;i++)
                for(int j=0;j<menuItems;j++)
                    if(menu[j]==order[i])
                        bill+=(quantity[i]*price_list[j]);
            bill-=(bill*discout);
            return bill;
        }
        void apply_discount(){
            discout+=0.1;
        }
};
int Restaurant::coupon_redeemed_count = 0;
void displayRollNum(){
    cout<<"----------------------------"<<endl<<"|  Sahil Latif <<23I0763>> |"<<endl<<"----------------------------"<<endl;
}
int main(){
    displayRollNum();
    string s1[3] = {"Sushi", "Pad Thai", "Mango Tango"}, s2[3] = {"Binary Burger", "Quantum Quinoa", "Data Donuts"};
    float p1[3] = {2.5, 3.2,5.0}, p2[3]={12.5, 10.0, 11.5};
    Restaurant r1("Food Heaven", "City Center", "FH", 3, s1, p1);
    r1.addCoupon("FH-BOGO-12345",time(0)-10800,time(0)+108000);
    Restaurant r2("Pixel Bites", "Cyber Street", "PB", 3, s2, p2);
    r2.addCoupon("PB-BOGO-67890",time(0)-10800,time(0)+108000);
    r1.displayMenu();
    User u1("Sahil", 18, "0304-1111111");
    u1.accumulate_coupon("FH-BOGO-12345",time(0)-10800, time(0)+108000,r1.getResturantCode());
    u1.has_valid_coupon(r1.getResturantCode());
    if(u1.redeem_coupon("FH-BOGO-12345", r1.getResturantCode())){
        r1.apply_discount();
    }
    int q[3] = {2,2,2};
    cout<<"Total Bill: "<<r1.generateBill(s1,q,3);

}