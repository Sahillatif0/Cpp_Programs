#include <iostream>
#include <cmath>
using namespace std;
int main() {
    double number;
    cout << "Enter a number: ";
    cin >> number;
    try{
        if(number < 0){
            throw runtime_error("negative"); 
        }
        cout << "Square root of " << number << " is " << sqrt(number);
    }
    catch(...){
        cout << "Number is negative.";
    }

    return 0;
}