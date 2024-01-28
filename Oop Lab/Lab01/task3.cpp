#include <iostream>
using namespace std;
int main(){
    int n,i;
    cout<<"Enter the number of strings: ";
    cin>>n;
    string *strs = new string[n];
    cout<<"Enter strings"<<endl;
    for(i=0;i<n;i++){
        cout<<i+1<<". ";
        cin>>strs[i];
    }
    for(i=0;i<n/2;i++){
        string temp = strs[i];
        strs[i] = strs[n-i-1];
        strs[n-i-1] = temp;
    }
    for(i=0;i<n;i++){
        int len = strs[i].length();
        for(int j=0;j<len/2;j++){
            char t = strs[i].at(j);
            strs[i].at(j) = strs[i].at(len-j-1);
            strs[i].at(len-j-1) = t;
        }
    }
    for(i=0;i<n;i++){
        cout<<strs[i]<<" ";
    }
}