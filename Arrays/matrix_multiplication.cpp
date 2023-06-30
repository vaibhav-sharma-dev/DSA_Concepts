#include <iostream>
using namespace std;

int main()
{
    int row_1, col_1, col_2;
    cin >> row_1 >> col_1 >> col_2;

    int arr_1[row_1][col_1], arr_2[col_1][col_2], arr_result[row_1][col_2];

    cout << "Enter 1st array: \n";

    for (int i=0; i<row_1; i++)
        for (int j=0; j<col_1; j++)
            cin >> arr_1[i][j];

    cout << "Enter 2nd array: \n";

    for (int i=0; i<col_1; i++)
        for (int j=0; j<col_2; j++)
            cin >> arr_2[i][j];

    int sum = 0;

    for (int i=0; i<row_1; i++)
    {
        for (int col_no=0; col_no<col_2; col_no++)
        {
            for (int j=0; j<col_1; j++)
                sum = sum + arr_1[i][j]*arr_2[j][col_no];
            
            arr_result[i][col_no] = sum;
            sum = 0;
        }
    }

    for (int i=0; i<row_1; i++)
    {
        for (int j=0; j<col_2; j++)
            cout << arr_result[i][j] << " ";

        cout << endl;
    }
}
