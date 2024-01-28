#include <iostream>
using namespace std;
int main(){
    int n,i,j;
    cout<<"Enter the number of colomns and rows of a NxN matrix(single input): ";
    cin>>n;
    int **mat = new int*[n];
    cout<<"Enter the numbers: ";
    for(i=0;i<n;i++){
        mat[i] = new int[n];
        for(j=0;j<n;j++)
            cin>>mat[i][j];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            int temp = *(*(mat+i)+j);
            *(*(mat+i)+j) = *(*(mat+j)+i);
            *(*(mat+j)+i) = temp; 
        }
        cout<<endl;
    }
    cout<<"Transposed"<<endl<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    for(i=0;i<n;i++)
        delete[] mat[i];
    delete[] mat;
}