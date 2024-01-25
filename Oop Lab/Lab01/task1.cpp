#include <iostream>
using namespace std;
int main()
{
    int *num = new int;
    int *numC = new int;
    int *b = new int;
    int *c = new int;
    cout << "Enter the number: ";
    cin >> *num;
    (*numC) = (*num);
    *c = 10;
    for (; (*numC) > 0; (*numC) /= 10)
    {
        *b = *num % *c;
        (*num) = (*num / (*c)) * (*c);
        (*b)=((*b)/((*c)/10))!=9? *b + (*c) / 10:*b%((*c)/10);
        (*num) += (*b);
        *c *= 10;
    }
    cout << *num << endl;
    delete num, numC, b, c;
}