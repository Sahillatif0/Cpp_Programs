#include<iostream>
using namespace std;
void recursiveSwap(int &a,int &b, int diff){
    if (diff==0)
        return;
    else if(diff>0){
        a++;
        b--;
        diff--;
    }
    else if(diff<0){
        a--;
        b++;
        diff++;
    }
    recursiveSwap(a,b,diff);
}

int main(){
    int a,b;
    cout<<"Enter the values of a and b: ";
    cin>>a>>b;
    recursiveSwap(a,b,b-a);
    cout<<"After swapping a="<<a<<" and b="<<b<<endl;
}