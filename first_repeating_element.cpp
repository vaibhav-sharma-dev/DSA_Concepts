//Given an array arr[] of size_arr N. The task is to find the first repeating element in the array of integers, i.e., an element that occurs more than once and whose index of first occurrence is smallest.

//Constraints:

//1 <= N <= 10^6 
//0 <= Ai <= 10^6

#include <iostream>
using namespace std;

int main()
{
    int size_arr;
    cin >> size_arr;

    int arr[size_arr];
    for (int i=0; i<size_arr; i++)
        cin >> arr[i];

    int size_idx = 10e6;
    int arr_idx[size_idx];

    for (int i=0; i<size_idx; i++)
        arr_idx[i] = -1;

    int min_idx = INT_MAX;

    for (int i=0; i<size_arr; i++)
    {
        if (arr_idx[i] != -1)
            arr_idx[i] = min(arr[i]);
    }
}