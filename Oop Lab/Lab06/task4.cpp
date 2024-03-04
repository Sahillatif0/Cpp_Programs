#include<iostream>
using namespace std;

inline double battingAvg(int runs, int dismissed){
    return double (runs)/dismissed;
}
inline double battingStrikeRate(int runs, int balls){
    return double (runs)/balls*100.0;
}

int main() {
    int runs, dismissed, balls;
    cout<<"Enter runs scored: ";
    cin>>runs;
    cout<<"Enter times dismissed: ";
    cin>>dismissed;
    cout<<"Enter balls faced: ";
    cin>>balls;
    cout<<"Batting Average: "<<battingAvg(runs, dismissed)<<endl;
    cout<<"Batting Strike Rate: "<<battingStrikeRate(runs, balls)<<endl;
}