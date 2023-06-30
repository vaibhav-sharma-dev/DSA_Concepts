#include<iostream>
using namespace std;

int min_sum(int arr[], int size, int k)
{
    int sum = 0;
    for (int i=0; i<k; i++)
        sum = sum + arr[i];

    int temp_sum = sum;

    for (int i=1; i<size-k+1; i++)
    {
        temp_sum = temp_sum - arr[i-1];
        temp_sum = temp_sum + arr[i+k-1];

        sum = min(sum, temp_sum);
        //cout << temp_sum << " ";
    }
    return sum;
}


int main()
{
    int arr[8] = {-2, 10, 1, 3, 2, -1, 4, 5};
    int size = sizeof(arr)/sizeof(arr[0]);

    int k = 3;
    int ans = min_sum(arr, size, k);

    cout << ans;
}