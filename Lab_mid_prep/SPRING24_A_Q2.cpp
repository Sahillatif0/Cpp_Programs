#include<iostream>
using namespace std;
class Item{
    public:
        string name;
        Item(string n):name(n){}
        Item(){}      
};
class Restaurant{
    public:
        bool hasRelation(Item arr1[], Item arr2[], int r1Size, int r2Size){
            if(r1Size>r2Size)
                return false;
            int cnt = 0;
            for(int i=0;i<r1Size;i++)
                for(int j=0;j<r2Size;j++)
                    if(arr1[i].name==arr2[j].name){
                        cnt++;
                        break;
                    }
            if(cnt==r1Size)
                return true;
            else
                return false;
        }
};
int main(){
    Restaurant r1;
    int m,n;
    cout<<"Enter size of arrays: ";
    cin>>m>>n;
    Item arr1[m],arr2[n];
    for(int i=0;i<m;i++)
        cin>>arr1[i].name;
    
    for(int i=0;i<n;i++)
        cin>>arr2[i].name;
    if(r1.hasRelation(arr1,arr2,m,n))
        cout<<"has relationship exists"<<endl;
    else
        cout<<"relationship does not exist"<<endl;
}