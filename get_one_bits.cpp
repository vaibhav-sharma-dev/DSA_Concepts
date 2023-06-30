#include <iostream>
#include <vector>
using namespace std;

vector<int> getOneBits(int n) 
{
    int pow = 1;
    vector <int> bin(32);

    while (n>=pow)
        pow = pow*2;
        
    pow = pow/2;
    
    int i = 0, ctr = 0;
    while (pow>0)
    {
        int divisor = n/pow;
        bin[i] = divisor;
        i++;
        
        if (divisor!=0)
        {
            n = n - pow;
            ctr++;
        }
        pow = pow/2;
    }

    vector <int> result(ctr+1);

    result[0] = ctr;
    int j = 1;
    
    for (int i=0; i<bin.size(); i++)
    {
        if (bin[i]==1)
        {
            result[j] = i+1;
            j++;
        }
    }
    
    return result;
}


int main()
{
    int n;
    cin >> n;

    vector<int> result = getOneBits(n);

    for (int i=0; i<result.size(); i++)
        cout << result[i];

    return 0;
}
