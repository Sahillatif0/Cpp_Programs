#include<iostream>
#include<vector>
using namespace std;
class Date{
    int day, month, year;
    public:
        Date(int d, int m, int y):day(d), month(m), year(y){}
        void setDay(int d){day=d;}
        void setMonth(int m){month=m;}
        void setYear(int y){year=y;}
        int getDay()const{return day;}
        int getMonth()const{return month;}
        int getYear()const{return year;}
        void display()const{
            cout<<day<<"/"<<month<<"/"<<year<<endl;
        }
};

class Medicine{
    string name, formula;
    Date MFD, EXPD;
    double retailPrice;
    public:
        Medicine(string n, string f, Date md, Date ed, double rp):name(n), formula(f), MFD(md), EXPD(ed), retailPrice(rp){}
        void setName(string n){name=n;}
        void setFormula(string f){formula=f;}
        void setMFD(Date md){MFD=md;}
        void setEXPD(Date ed){EXPD=ed;}
        void setRetailPrice(double rp){retailPrice=rp;}
        string getName()const{return name;}
        string getFormula()const{return formula;}
        Date getMFD()const{return MFD;}
        Date getEXPD()const{return EXPD;}
        double getRetailPrice()const{return retailPrice;}
        virtual void display()const{
            cout<<"Name: "<<name<<endl;
            cout<<"Formula: "<<formula<<endl;
            cout<<"MFD: ";
            MFD.display();
            cout<<"EXPD: ";
            EXPD.display();
            cout<<"Retail Price: "<<retailPrice<<endl;
        }
        bool operator ==(Medicine med){
            return EXPD.getYear()==med.EXPD.getYear();
        }
};
class Tablet: public Medicine{
    float sucroseLvl;
    public:
        Tablet(string n, string f, Date md, Date ed, double rp, float sl):Medicine(n, f, md, ed, rp), sucroseLvl(sl){}
        void setSucroseLvl(float sl){sucroseLvl=sl;}
        float getSucroseLvl()const{return sucroseLvl;}
        void display()const{
            Medicine::display();
            cout<<"Sucrose Level: "<<sucroseLvl<<endl;
        }
};
class Capsule: public Medicine{
    int absorptionPercentage;
    public:
        Capsule(string n, string f, Date md, Date ed, double rp, int ap):Medicine(n, f, md, ed, rp), absorptionPercentage(ap){}
        void setAbsorptionPercentage(int ap){absorptionPercentage=ap;}
        int getAbsorptionPercentage()const{return absorptionPercentage;}
        void display()const{
            Medicine::display();
            cout<<"Absorption Percentage: "<<absorptionPercentage<<endl;
        }
};
class Syrup: public Medicine{
    string color;
    public:
        Syrup(string n, string f, Date md, Date ed, double rp, string c):Medicine(n, f, md, ed, rp), color(c){}
        void display()const{
            Medicine::display();
            cout<<"Color: "<<color<<endl;
        }
};
class Pharmacist{
    string name;
    public:
        Pharmacist(string n):name(n){}
        void Search_Medicine(vector<Medicine> med, string formula);
};
class Counter{
    double revenue;
    public:
        Counter():revenue(0){}
        void Search_Medicine(vector<Medicine> med, string name);
        void Update_Revenue(double newBillPayment);
};
int main(){
    cout<<"=============================="<<endl
        <<"|   Sahil Latif <23I0763>     |"<<endl
        <<"=============================="<<endl<<endl;
}