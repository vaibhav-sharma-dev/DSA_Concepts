#include <iostream>
using namespace std;

int main()
{
    int bit;
    cin >> bit;

    if (bit==0)
        cout << false;

    else if ((bit&bit-1) == 0)
        cout << true;
        
    else 
        cout << false;
}