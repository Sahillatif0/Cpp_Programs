#include <iostream>
#include <math.h>
using namespace std;

class Table{
    const int totalSeats;
    int emptySeats, occupiedSeats, TableNum;
    static int totalTables;
    bool clean;
    public:
        Table():totalSeats(4), emptySeats(4), occupiedSeats(0), clean(true), TableNum(++totalTables){}
        Table(int tS):totalSeats(abs(tS-4)>=abs(tS-8)?8:4),emptySeats(totalSeats), occupiedSeats(0), clean(true), TableNum(++totalTables){}
        int getTotalSeats(){return totalSeats;}
        void setEmptySts(int s){emptySeats = s;}
        void setOccupSts(int s){occupiedSeats = s;}
        void setClean(bool c){clean = c;}
        int getEmptySts(){return emptySeats;}
        int getTabNum(){return TableNum;}
        bool getClean(){return clean;}
        int getOccupSts(){return occupiedSeats;}
        void cleanTable(){if(occupiedSeats==0) clean = true;else cout<<"Table is not empty"<<endl;}
        void useTable(int ppl){
            occupiedSeats+=ppl;
            emptySeats-=ppl;
        }
        void leaveTable(){
            if(occupiedSeats>0){ 
                occupiedSeats=0;
                emptySeats = totalSeats;
            }
            else cout<<"Table is already empty"<<endl;
        }
        void haveLunch(){
            clean = false;
        }
};
void OccupyTable(Table *t,int totalTbls, int ppl, bool haveLunch){
    for(int i=0;i<totalTbls;i++){
        if(t[i].getEmptySts()>=ppl && t[i].getClean()==true){
            cout<<"Table "<<t[i].getTabNum()<<" is available, capicity: "<<t[i].getEmptySts()<<endl;
            t[i].useTable(ppl);
            if(haveLunch)
                t[i].haveLunch();
            return;
        }
    }
}
void EmptyTable(Table *t,int totalTbls, int TabNum ){
    for(int i=0;i<totalTbls;i++){
        if(t[i].getTabNum() == TabNum){
            t[i].leaveTable();
            if(!t[i].getClean()){
                t[i].cleanTable();
            }
            cout<<"Table "<<t[i].getTabNum()<<" is empty now"<<endl;
            return;
        }
    }
}

int Table::totalTables = 0;
int main(){
    Table tables[5] = {Table(8),Table(8),Table(4),Table(4),Table(4)};
    OccupyTable(tables,5,4,false);
    OccupyTable(tables,5,6,true);
    OccupyTable(tables,5,7,true);
    EmptyTable(tables,5,2);
    
}