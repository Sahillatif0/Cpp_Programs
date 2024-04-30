#include<iostream>
#include<fstream>
using namespace std;
template<class T>
int createFile(T data, string fileName){
    fstream myFile;
    myFile.open(fileName, ios::out);
    myFile<<data;
    cout<<"Data stored"<<endl;
    myFile.close();
    return 0;
}
template<class U>
int readFile(string fileName){
    fstream myFile;
    myFile.open(fileName, ios::in);
    if(!myFile){
        cout<<"File doesn't exist"<<endl;
        return -1;
    }
    U data;
    myFile>>data;
    cout<<data<<endl;
    myFile.close();
    return 0;
}
int main(){
    createFile<int>(123, "test.txt");
    readFile<int>("test.txt");
}