#include<iostream>
using namespace std;
class SmartPhone{
    string company, model,displayResolution;
    int ram,rom,storage;
    public:
        void setCompanynModel(string c, string m){
            company = c;
            model = m;
        }
        void setData(string dR, int ra,int ro, int s) {
            displayResolution = dR;
            ram = ra;
            rom = ro;
            storage = s;
        }

        string getModel(){return model;}
        string getCompany(){return company;}
        string getResolution(){return displayResolution;}
        int getRam(){return ram;}
        int getRom(){return rom;}
        int getStorage(){return storage;}

        void showDetails() {
            cout << "Company : "<<company<<endl;
            cout << "Model : "<<model<<endl;
            cout << "Display Resolution : "<<displayResolution<<endl;
            cout << "RAM : "<<ram<<" GB\n";
            cout << "ROM : "<<rom<<" GB\n";
            cout << "Storage : "<<storage<<" GB\n";
        }

        void makePhoneCall(string number){
            cout<<"Making a phone call to "<<number<<"..."<<endl;
        }
        void sendMessage(string number, string msg){
            cout<<"sending message to "<<number<<": "<<msg<<"..."<<endl;
        }
        void connectWifi(){
            cout<<"Connecting to Wifi..."<<endl;
        }
        void browseInternet(){
            cout<<"Browsing in internet..."<<endl;
        }
};
int main(){
    SmartPhone p[3];
    p[0].setCompanynModel("Xiaomi", "Redmi Note 11");
    p[0].setData("1080x2400",6,128,128);
    p[1].setCompanynModel("Oppo", "A5");
    p[1].setData("1080x1920",3,32,64);
    p[2].setCompanynModel("Oppo", "F17");
    p[2].setData("1080x2400",8,128,256);
    //Usomg ShowDetails
    for(int i=0;i<3;i++){
        p[i].showDetails();
        cout<<"\n\n";
    }
    //Usomg GetFunctions
    for(int i=0;i<3;i++){
        cout << "Company : "<<p[i].getCompany()<<endl;
        cout << "Model : "<<p[i].getModel()<<endl;
        cout << "Display Resolution : "<<p[i].getResolution()<<endl;
        cout << "RAM : "<<p[i].getRam()<<" GB\n";
        cout << "ROM : "<<p[i].getRom()<<" GB\n";
        cout << "Storage : "<<p[i].getStorage()<<" GB\n\n\n";
    }

}