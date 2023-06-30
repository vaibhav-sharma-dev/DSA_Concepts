#include <iostream>
using namespace std;

//0101: 2

int main()
{
    int bin;
    cin >> bin;

    int pos;
    cin >> pos;

    if ((bin & 1<<pos)!=0)
        cout << "1 is present at pos: " << pos << endl;
    
    else
        cout << "1 is not present at pos: " << pos << endl;
}