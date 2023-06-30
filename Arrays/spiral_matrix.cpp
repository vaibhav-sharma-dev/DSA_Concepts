// 2-d arrays

#include <iostream>
using namespace std;

int main()
{
    int row = 0, col = 0;
    cin >> row >> col;
    int arr[row][col];
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            cin >> arr[i][j];

    int row_start = 0;
    int row_end = row-1;
    int col_start = 0;
    int col_end = col-1;

    while (row_start<=row_end && col_start<=col_end)
    {
        for (int i=col_start; i<=col_end; i++)
            cout << arr[row_start][i] << " ";
        
        row_start++;

        for (int i=row_start; i<=row_end; i++)
            cout << arr[i][col_end] << " ";
        
        col_end--;

        for (int i=col_end; i>=col_start; i--)
            cout << arr[row_end][i] << " ";
        
        row_end--;

        for (int i=row_end; i>=row_start; i--)
            cout << arr[i][col_start] << " ";

        col_start++;
    }
    
}