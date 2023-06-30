// cumulative sum approach

// -1, 4, 7, 2

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i=0; i<size; i++)
        cin >> arr[i];
    
    int arr_cum[size+1];
    arr_cum[0] = 0;

    for (int i=1; i<=size; i++)
        arr_cum[i] = arr_cum[i-1] + arr[i-1];

    int max_sum = INT_MIN;

    for (int i=1; i<=size; i++)
    {
        int sum = 0;
        for (int j=0; j<i; j++)
        {
            sum = arr_cum[i] - arr_cum[j];
            max_sum = max(max_sum, sum);
        }
    }

    cout << max_sum;

}