#include <iostream>
using namespace std;

int main()
{
    int no;
    cin >> no;

    int spf[no];
    for (int i=1; i<=no; i++)
        spf[i] = i;

    for (int i=2; i<=no; i++)
    {
        if (spf[i]==i)
        {
            for (int j=i*i; j<=no; j=j+i)
            {
                if (spf[j]==j)
                    spf[j] = i;
            }
        }
    }

    while (no!=1)
    {
        cout << spf[no] << " ";
        no = no/spf[no];
    }
}