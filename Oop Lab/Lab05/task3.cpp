#include<iostream>
#include<string>
using namespace std;

class ValidateString{
    string str;
    public:
    ValidateString(string s){
        str = s;
    }
    //If it is not const function it can change the string, so we have to make it constant function.
    const bool isValid(){
        for(int i=0;i<str.length();i++){
            if(str[i]<65 || (str[i]>90 && str[i]<97)  || str[i] > 122 ) return false;
        }
        return true;
    }
};

int main(){
    cout<<"Enter a String : ";
    string s1;
    getline(cin, s1);
    ValidateString vs(s1);
    if(vs.isValid())
        cout << "The entered string is valid." << endl;
    else
        cout << "The entered string is not valid." << endl;

}