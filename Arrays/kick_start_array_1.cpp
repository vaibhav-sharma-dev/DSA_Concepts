// An arithmetic array is an array that contains at least two integers and the differences between consecutive integers are equal. For example, [9, 10], [3, 3, 3], and [9, 7, 5, 3] are arithmetic arrays, while [1, 3, 3, 7], [2, 1, 2], and [1, 2, 4] are not arithmetic arrays.

// Sarasvati has an array of N non-negative integers. The i-th integer of the array is A. She wants to choose a contiguous arithmetic subarray from her array that has the maximum length. Please help her to determine the length of the longest contiguous arithmetic subarray.

#include <iostream>
using namespace std;

// 10, 7, 4, 6, 8, 10, 11

int main()
{
    int test;
    cin >> test;

    for (int i=0; i<test; i++)
    {
        int size;
        cin >> size;

        int arr[size], arr_res[size-1];
        for (int i=0; i<size; i++)
            cin >> arr[i];

        int counter = 1;
        for (int i=0; i<size-1; i++)
        {
            int diff = arr[i] - arr[i+1];
            counter = 1;

            for (int j=i+1; j<size-1; j++)
            {
                if ( (arr[j]-arr[j+1]) == diff )
                    counter++;
                
                else break;
            }

            arr_res[i] = ++counter;
        }

        int max_len = arr_res[0];
        for (int i=1; i<size-1; i++)
        {
            if (arr_res[i]>max_len)
                max_len = arr_res[i];
        }

        cout << "#" << i << ":" << max_len << endl;
    }
    
}