#include <iostream>
using namespace std;

#define min(a,b) (a>b?b:a)

int main(){
    int n,i,j,mArea=0,area;
    cout<<"Enter number of lines: ";
    cin>>n;
    int *height = new int[n];
    cout<<"Enter heights: ";
    for(i=0;i<n;i++)
        cin>>height[i];
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++){
        area = min(height[i],height[j])*(j-i);
        if(area>mArea)
            mArea = area;
        }
    cout<<"Max Area: "<<mArea;
    delete[] height;
}