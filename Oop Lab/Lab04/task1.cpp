#include<iostream>
#include<string>
using namespace std;

class WeekDays{
    string days[7];
    int currentDay;

    public:
    WeekDays(){
        string Wdays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        copy(Wdays,Wdays+7,days);
        currentDay=0;
    }
    WeekDays(int c){
        string Wdays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        copy(Wdays,Wdays+7,days);
        currentDay=c%7;
    }
    string getCurrentDay(){
        return days[currentDay];
    }
    string getNextDay(){
        return days[currentDay+1];
    }
    string getPrevDay(){
        if(currentDay==0)
            currentDay = 7;
        return days[currentDay-1];
    }
    string getNthDayFromToday(int n){
        n += currentDay; 
        return days[(n%7)];
    }


};

int main(){
    WeekDays a(5);
    while(1){
        int opt,n;
        cout<<"1. GetCurrentDay\n2. GetNextDay\n3. GetPrevDay\n4. GetNthDayFromToday\n5. Exit\nEnter the choice: ";
        cin>>opt;
        switch(opt){
            case 1:
                cout<<a.getCurrentDay()<<endl;
                break;
            case 2:
                cout<<a.getNextDay()<<endl;
                break;
            case 3:
                cout<<a.getPrevDay()<<endl;
                break;
            case 4:
                cout<<"Enter n: ";
                cin>>n;
                cout<<a.getNthDayFromToday(n)<<endl;
                break;
            case 5:
                return 1; 
                break;
        }
    }
}