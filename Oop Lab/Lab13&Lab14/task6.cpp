#include <iostream>
using namespace std;
int main() {
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1>>num2;
    try{
        if(num2 == 0){
            throw num2; 
        }
        cout << "Division of " << num1 << " and " << num2<<" is " << (num1/num2);
    }
    catch(double num2){
        cout << "Cannot divide by zero.";
    }

    return 0;
}