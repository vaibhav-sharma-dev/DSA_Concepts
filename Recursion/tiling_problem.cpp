// Given a "2 x n" board and tiles of size "2 x 1", count the number of ways to tile the given board using these tiles

#include <iostream>
using namespace std;

int fill_tile(int size)
{
    if (size==1)
        return 1;

    if (size==0)
        return 0;

    return fill_tile(size-1) + fill_tile(size-2);
}

int main()
{
    int size;
    cin >> size;

    cout << fill_tile(size);
}