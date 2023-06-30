//Given an unsorted array A of size N of non-negative integers, find a continuous subarray which adds to a given number S.

//Constraints:

//1 <= N <= 10^5

//0 <= Ai <= 10¹⁰

// 1, 2, 3, 7, 5 : 12

#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i=0; i<size; i++)
        cin >> arr[i];

    int sum;
    cin >> sum;

    int i = 1, j = 1, e = 0;
    int s = arr[0];
    int curr_sum = s + e;

    if (curr_sum == sum)
    {
        cout << "s = " << 1 << "e = " << 1;
        return 0;
    }

    while (curr_sum<=sum)
    {
        e = arr[j];
        curr_sum = curr_sum + e;
        j++;
    }

    if (curr_sum == sum)
    {
        cout << "s = " << i-1 << "e = " << j-1;
        return 0;
    }

    while (curr_sum>sum)
    {
        curr_sum = curr_sum - s;
        s = arr[i];
        i++;
    }

        cout << "s = " << i-1 << "e = " << j-1;
    
    return 0;
}