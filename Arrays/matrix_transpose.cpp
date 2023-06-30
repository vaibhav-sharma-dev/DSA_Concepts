#include <iostream>
using namespace  std;

int main()
{
    int row, col;
    cin >> row >> col;

    int arr[row][col];

    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
            cin >> arr[i][j];
    }

    cout << "Interchange rows & columns: \n";
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
            cout << arr[j][i] << " ";
        
        cout << endl;
    }

    cout << "Swap through diagonals: \n";
    for (int i=0; i<row; i++)
    {
        for (int j=i; j<col; j++)
        {
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
            cout << arr[i][j] << " ";
        
        cout << endl;
    }
}