// functions
#include <iostream>
using namespace std;

int factorial(int);
void row_C_col(int, int);

int main()
{
    int row;
    cout << "Enter Rows of Triangle\n";
    cin >> row;
    cout << endl;
    
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<=i; j++)
        {
            row_C_col(i, j);
        }
        cout << endl;
    }

}

void row_C_col(int row, int col)
{
    cout << " " << factorial(row)/(factorial(col)*factorial(row-col));
}

int factorial(int x)
{
    int fact=1;

    for (int i=1; i<=x; i++)
        fact = fact*i;
    
    return fact;
}