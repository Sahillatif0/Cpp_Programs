#include<iostream>
using namespace std;
template<class T, class Derived>
class Matrix{
    protected:
        T **matrix;
        int rows, cols;
    public:
        Matrix(int r, int c):rows(r), cols(c){
            matrix = new T*[rows];
            for(int i=0; i<rows; i++){
                matrix[i] = new T[cols];
            }
        }
        void setElement(int i, int j, T val){
            matrix[i][j] = val;
        }
        T getElement(int i, int j){
            return matrix[i][j];
        }
        Derived operator+(Derived &m){
            if(rows==m.rows && cols==m.cols){
                Derived temp(rows, cols);
                for(int i=0; i<rows; i++)
                    for(int j=0; j<cols; j++)
                        temp.matrix[i][j] = matrix[i][j] + m.matrix[i][j];
                return temp;
            }
            cout<<"Matrices are not of same size"<<endl;
            return *static_cast<Derived*>(this);
        }
        Derived operator-(Derived &m){
            if(rows==m.rows && cols==m.cols){
                Derived temp(rows, cols);
                for(int i=0; i<rows; i++)
                    for(int j=0; j<cols; j++)
                        temp.matrix[i][j] = matrix[i][j] - m.matrix[i][j];
                return temp;
            }
            cout<<"Matrices are not of same size"<<endl;
            return *static_cast<Derived*>(this);
        }
        Derived operator*(Derived &m){
            if(cols==m.rows){
                Derived temp(rows, m.cols);
                for(int i=0; i<rows; i++)
                    for(int j=0; j<m.cols; j++){
                        temp.matrix[i][j] = 0;
                        for(int k=0; k<cols; k++)
                            temp.matrix[i][j] += matrix[i][k] * m.matrix[k][j];
                    }
                return temp;
            }
            cout<<"Matrices are not compatible for multiplication"<<endl;
            return *static_cast<Derived*>(this);
        }
        virtual void display()=0;
};
class IntMatrix: public Matrix<int, IntMatrix>{
    public:
        IntMatrix(int r, int c):Matrix(r, c){}
        void display(){
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++)
                    cout<<matrix[i][j]<<" ";
                cout<<endl;
            }
        }
};
class DoubleMatrix: public Matrix<double, DoubleMatrix>{
    public:
        DoubleMatrix(int r, int c):Matrix(r, c){}
        void display(){
            for(int i=0; i<rows; i++){
                for(int j=0; j<cols; j++)
                    cout<<matrix[i][j]<<" ";
                cout<<endl;
            }
        }
};
int main() {
    cout<<"=============================="<<endl
        <<"|   Sahil Latif <23I0763>     |"<<endl
        <<"=============================="<<endl<<endl;
    IntMatrix m1(2,2), m2(2,2);
    m1.setElement(0, 0, 1);
    m1.setElement(0, 1, 2);
    m1.setElement(1, 0, 3);
    m1.setElement(1, 1, 4);
    m2.setElement(0, 0, 5);
    m2.setElement(0, 1, 6);
    m2.setElement(1, 0, 7);
    m2.setElement(1, 1, 8);
    IntMatrix m3 = m1 + m2;
    IntMatrix m4 = m3 - m2;
    IntMatrix m5 = m1 * m2;
    m3.display();
    m4.display();
    m5.display();
    DoubleMatrix dm1(2,2),dm2(2,2),dm3(3,2);
    dm1.setElement(0, 0, 1.1);
    dm1.setElement(0, 1, 2.2);
    dm1.setElement(1, 0, 3.3);
    dm1.setElement(1, 1, 4.4);
    dm2.setElement(0, 0, 5.5);
    dm2.setElement(0, 1, 6.6);
    dm2.setElement(1, 0, 7.7);
    dm2.setElement(1, 1, 8.8);
    dm3.setElement(0, 0, 1.1);
    dm3.setElement(0, 1, 2.2);
    dm3.setElement(1, 0, 3.3);
    dm3.setElement(1, 1, 4.4);
    dm3.setElement(2, 0, 5.5);
    dm3.setElement(2, 1, 6.6);
    DoubleMatrix dm4 = dm1 + dm2;
    DoubleMatrix dm5 = dm3 - dm2;
    DoubleMatrix dm6 = dm3 * dm2;
    dm4.display();
    dm5.display();
    dm6.display();
}