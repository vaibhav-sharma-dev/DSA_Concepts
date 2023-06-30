#include <iostream>
using namespace std;

bool safe(int** arr, int size, int row, int col)
{
    for (int i=0; i<row; i++)
    {
        if(arr[i][col]==1)
            return false;
    }
    int r = row;
    int c = col;

    while (r>=0 && c<size)
    {
        if(arr[r][c]==1)
            return false;
        
        r--;
        c++;
    }

    r = row;
    c = col;
    while (r>=0 && c>=0)
    {
        if(arr[r][c]==1)
            return false;
        
        r--;
        c--;
    }

    return true;
}

bool n_queen(int** arr, int size, int queen, int row, int col)
{
    if (queen==0)
        return true;

    for (col=0; col<size; col++)
    {
        if(safe(arr, size, row, col))
        {
            arr[row][col] = 1;
            if (n_queen(arr, size, queen-1, row+1, col))
                return true;
            
            arr[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int size;
    cin >> size;

    int** arr = new int* [size];
    for (int i=0; i<size; i++)
        arr[i] = new int[size];

    for (int i=0; i<size; i++)
        for (int j=0; j<size; j++)
            arr[i][j] = 0;

    n_queen(arr, size, size, 0, 0);

    for (int i=0; i<size; i++)
    {
        for (int j=0; j<size; j++)
            cout << arr[i][j] << " ";

        cout << endl;
    }
}