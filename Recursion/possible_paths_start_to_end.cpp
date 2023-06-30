// Count the number of possible paths from start point to end point in gameboard using dice.

#include <iostream>
using namespace std;

int gameboard(int start, int end)
{
    if (start==end)
        return 1;

    if (start>end)
        return 0;

    int ctr = 0;
    for (int i=1; i<=6; i++)
        ctr = ctr + gameboard(start+i, end);

    return ctr;
}

int main()
{
    int size;
    cin >> size;

    //int ctr = 0;

    cout << gameboard(1, size);
}