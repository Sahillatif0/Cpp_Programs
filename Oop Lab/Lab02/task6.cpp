#include <iostream>

using namespace std;

int calGCD(int a, int b) {
    if (b == 0) 
        return a;
    return calGCD(b, a % b);
}

int calLCM(int a, int b) {
    if (b == 0) 
        return a;
    return (a * b) / calGCD(a, b);
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    int gcd = calGCD(num1, num2);
    int lcm = calLCM(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is " << gcd << endl;
    cout << "LCM of " << num1 << " and " << num2 << " is " << lcm << endl;
    return 0;
}