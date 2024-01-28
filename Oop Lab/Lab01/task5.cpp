#include <iostream>
using namespace std;
int main()
{
    int n, m, startR, endR, startC, endC, cnt = 0, i = 0, j = 0;
    cout << "Enter the rows and coloumns of the array: ";
    cin >> n >> m;
    int **arr = new int *[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
    }
    startR = 0;
    endR = n - 1;
    startC = 0;
    endC = m - 1;
    while (cnt < (m * n))
    {
        cout << arr[i][j] << " ";
        if (i == startR && (j!=startC || startR==0))
        {
            if (j == endC)
            {
                i++;
                if (startR!=0)
                    startC++;
            }
            else
                j++;
        }
        else if (j == endC)
        {
            if (i == endR)
            {
                startR++;
                j--;
            }
            else
                i++;
        }
        else if (i == endR)
        {
            if (j == startC)
            {
                endC--;
                i--;
            }
            else
                j--;
        }
        else if (j == startC)
        {
            if (i == startR)
            {
                endR--;
                j++;
            }
            else
                i--;
        }
        cnt++;
    }
}
