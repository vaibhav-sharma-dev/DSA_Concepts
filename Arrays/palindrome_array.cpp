#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;

    char arr[size+1];
    cin >> arr;
    
    int s = 0, e = size-1, flag = 0;

    while (s<=e)
    {
        if (arr[s]==arr[e])
        {
            s++;
            e--;
            flag = 1;
        }
        else
        {
            flag = 0;
            break;
        }
    }

    if (flag==1)
        cout << true;

    else 
        cout << false;

}