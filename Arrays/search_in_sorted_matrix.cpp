#include <iostream>
using namespace std;

// start from top right element

int main()
{
    int row, col;
    cin >> row >> col;

    int arr[row][col];
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            cin >> arr[i][j];
    
    cout << "Enter the key: \n";
    int key;
    cin >> key;

    int flag = 0;

    for (int r=0, c=col-1; r<row && c>=0; )
    {
        if (arr[r][c]==key)
        {
            flag = 1;
            break;
        }

        else if (arr[r][c]>key)
            c--;

        else if (arr[r][c]<key)
            r++;
    }
    
    if (flag==1)
        cout << "found";

    else cout << "not found";
}