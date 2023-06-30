#include <iostream>
using namespace std;

int kadane_algo (int arr[], int size)
{
    int curr_sum = 0;
    int max_sum = INT_MIN;

    for (int i=0; i<size; i++)
    {
        if (arr[i]<0)
            curr_sum = 0;

        else
            curr_sum = curr_sum + arr[i];

        max_sum = max(max_sum, curr_sum);
    }
    return max_sum;
}

int main()
{
    int size;
    cin >> size;

    int arr[size];
    int sum = 0;
    for (int i=0; i<size; i++)
        {
            cin >> arr[i];
            sum = sum + arr[i];
        }

    int wrap_sum;
    int non_wrap_sum = kadane_algo(arr, size);

    int negative_arr[size];
    for (int i=0; i<size; i++)
        negative_arr[i] = 0 - (arr[i]);

    int max_sum_negative_arr = kadane_algo(negative_arr, size);
    max_sum_negative_arr = 0 - max_sum_negative_arr;
    wrap_sum = sum - max_sum_negative_arr;
    
    int max_circular_sum = max(wrap_sum, non_wrap_sum);
    cout << max_circular_sum;
}