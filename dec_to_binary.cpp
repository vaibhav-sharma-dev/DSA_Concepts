#include <iostream>
using namespace std;

int dec_To_binary(int dec)
{
    int pow = 1;
    int ans = 0;
    while (dec >= pow)
        pow = pow * 2;
    
    pow = pow/2;

    while (pow > 0)
    {
        int divisor = dec/pow;
        ans = ans*10 + divisor;

        if (divisor == 0)
            pow = pow/2;

        else
        {
            dec = dec - pow;
            pow = pow/2;
        }
    }
    
    return ans;
}

int main()
{
    int dec, result;
    cout << "Enter a Decimal No.: \n";
    cin >> dec;

    result = dec_To_binary(dec);
    cout << result;
}