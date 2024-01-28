#include <iostream>
using namespace std;
int main()
{
    int n, max, smax;
    cout << "Enter size of the array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    max = arr[0];
    smax = max > arr[1] ? arr[1] : arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            smax = max;
            max = arr[i];
        }
        else if (arr[i] > smax && arr[i] < max)
            smax = arr[i];
    }
    cout << "Second Highest Number: " << smax << endl;
    delete[] arr;
}
