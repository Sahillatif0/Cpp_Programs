#include<iostream>
#include<fstream>
using namespace std;
template <class U, int N> class Array{
	U arr[N];
public:
	Array(){}
    void input(){
        cout<<"Enter elements for the array: ";
        for(int i=0;i<N;i++)
            cin>>arr[i];
    }
    void sort(){
        int sorted = 1;
        while(sorted){
            sorted = 0;
            for(int i=0;i<N-1;i++)
                if(arr[i]>arr[i+1]){
                    U temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                    sorted = 1;
                }
        }
    }
    void storeInFile(string fileName){
        fstream myFile;
        myFile.open(fileName, ios::out);
        for(int i=0;i<N;i++)
            myFile<<arr[i]<<endl;
        myFile.close();
    }
    void copyFileContent(string file1, string file2){
        fstream myFile1, myFile2;
        myFile1.open(file1, ios::in);
        myFile2.open(file2, ios::out);
        while(1){
            U a;
            myFile1>>a;
            if(myFile1.eof())
                break;
            myFile2<<a<<endl;
        }
        myFile1.close();
        myFile2.close();
    }

};
int main(){
    Array<int, 5> arr1;
    arr1.input();
    arr1.sort();
    arr1.storeInFile("arr.txt");
    arr1.copyFileContent("arr.txt", "arr2.txt"); 
}