// You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

// Constraints:

// 1 <= N <= 106

// -106 <= Ai <= 106

// 0, -9, 1, 3, -4, 5

#include <iostream>
using namespace std;

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i=0; i<size; i++)
        cin >> arr[i];

    int check_size = 1e6;

    bool arr_check[check_size];
    for (int i=0; i<check_size; i++)
        arr_check[i] = false;

    for (int i=0; i<size; i++)
    {
        if (arr[i]>=0)
            arr_check[arr[i]] = true;
    }

    int result;

    for (int i=1; i<check_size; i++)
    {
        if (arr_check[i] == false)
        {
            result = i;
            break;
        }
    }
    cout << result;
}