// kadane's algo to find max sub-array sum

// -1, 4, 7, 2

#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i=0; i<size; i++)
        cin >> arr[i];

    int curr_sum = 0;
    int max_sum =  INT_MIN;
    for (int i=0; i<size; i++)
    {
        if (arr[i]<0)
            curr_sum = 0;

        else
            curr_sum = curr_sum + arr[i];

        max_sum = max(max_sum, curr_sum);
    }
    cout << max_sum;
}