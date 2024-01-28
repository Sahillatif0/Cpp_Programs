#include <iostream>
using namespace std;
int main()
{
    int n, target;
    cout << "Enter the size of array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter target: ";
    cin >> target;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            if ((arr[i] + arr[j]) == target)
            {
                cout << "(" << i << ", " << j << ")" << endl;
                break;
            }
    delete[] arr;
}