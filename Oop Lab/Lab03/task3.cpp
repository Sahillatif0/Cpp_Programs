#include <iostream>
using namespace std;

class Calendar{
    string dailyTasks[12][30];
    int cYear;
    public: 
        void setYear(int y){cYear = y;}
        int getYear() {return cYear;}
        void addTask(string task,int day,int month){
            dailyTasks[month-1][day-1] = task;
            cout<<"Task Added\n";
        }
        void removeTask(int day,int month){
            if (dailyTasks[month-1][day-1]=="") {
                cout << "No Task to Remove\n";
            } else {
                dailyTasks[month-1][day-1]="";
                cout << "Task Removed\n";
            }
        }
        void showTasks(){
            cout<<"\tAll Tasks\n";
            for(int i=0;i<12;i++){
                int tasks = 0;
                cout<<endl<<"Month : "<<i+1<<endl;
                for(int j=0;j<30;j++)
                    if(dailyTasks[i][j]!=""){
                        cout<<"Day : "<<j+1<<"\t"<<dailyTasks[i][j]<<endl;
                        tasks++;
                    }
                if(tasks==0)
                    cout<<"No tasks done in this month"<<endl;

            }
        }

};
int main(){
    Calendar cal;
    cal.setYear(2024);
    cal.addTask( "Buy Groceries", 15, 9);
    cal.addTask( "Complete Oop Assignment", 15, 2);
    cal.addTask( "Complete DLD Assignment", 25, 2);
    cal.addTask( "DLD Quiz", 13, 2);
    cal.addTask( "EW Lab", 13, 3);
    cal.addTask( "Oop Lab", 15, 3);
    int opt, day, month;
    string task;
    while (1)
    {
    cout<<"1. Show Tasks\n2. Add Task\n3. Remove Task\n4. Exit\nEnter Option: ";
    cin>>opt;
    switch (opt)
    {
    case 1:
        cal.showTasks();
        break;
    case 2:
        cout<<"Enter the month and date(m d): ";
        cin>>month>>day;
        cin.ignore();
        cout<<"Enter the task to be added: ";
        getline(cin,task);
        cal.addTask(task, day, month);
        break;
    
    case 3:
        cout<<"Enter the month and date(m d): ";
        cin>>month>>day;
        cal.removeTask(day, month);
        break;
    case 4:
        return 1;
        break;
    default:
        cout<<"Invalid input"<<endl;
        break;
    }
    }
}