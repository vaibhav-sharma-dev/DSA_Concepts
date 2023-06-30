#include <iostream>
using namespace std;

int main()
{
    int bin;
    cin >> bin;

    int count = 0;

    while (bin)
    {
        bin = bin & bin-1;
        count++;
    }

    cout << count;
}