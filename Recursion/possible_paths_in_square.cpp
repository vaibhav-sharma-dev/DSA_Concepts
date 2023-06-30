#include <iostream>
using namespace std;

int square_path(int n, int i, int j)
{
    if (i==n-1 && j==n-1)
        return 1;

    if (i>=n || j>=n)
        return 0;
    
    return square_path(n, i+1, j) + square_path(n, i, j+1);
}

int main()
{
    int size;
    cin >> size;

    int i=0, j=0;

    cout << square_path(size, i, j);
}