#include<iostream>
using namespace std;

bool hasSubsetSum(int arr[], int size, int targetSum){
    bool a;
    if(targetSum==0)
        return true;
    else if(size==0)
        return false;
    for(int i=size-1;i>=0;i--){
        a=hasSubsetSum(arr,i,targetSum-arr[i]);
        if(a)
            break;
    }
    return a;
}


int main(){
    int size,sum;
    cout<<"Enter the size for the array: ";
    cin>>size;
    int *num = new int[size];
    cout<<"\nEnter elements of the array:\n";
    for(int i=0;i<size;i++)
        cin>>num[i];
    cout<<"Enter the required sum: ";
    cin>>sum;
    cout<<(hasSubsetSum(num,size,sum)?"true":"false");
}
