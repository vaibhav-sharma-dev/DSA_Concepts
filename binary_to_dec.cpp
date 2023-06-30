// functions
#include <iostream>
using namespace std;

int binary_To_dec(int bin)
{
    int pow = 1, ans = 0;

    while (bin>0)
    {
        int rem = bin%10;
        ans = ans + rem*pow;
        pow = pow * 2;
        bin = bin/10;
    }

    return ans;
}

int main()
{
    int bin, result;
    cout << "Enter a Binary Number: \n";
    cin >> bin;

    result = binary_To_dec(bin);
    cout << result;
}