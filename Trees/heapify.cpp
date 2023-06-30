#include <iostream>
using namespace std;


void heapify(int arr[], int size, int idx)
{
    int temp_idx = idx;

    int left_idx = temp_idx*2;
    int right_idx = temp_idx*2 + 1;

    if (left_idx<size && arr[left_idx]>arr[temp_idx])
    {
        //swap(arr[left_idx], arr[temp_idx]);
        temp_idx = left_idx;
    }

    if (right_idx<size && arr[right_idx]>arr[temp_idx])
    {
        //swap(arr[right_idx], arr[temp_idx]);
        temp_idx = right_idx;
    }

    if (temp_idx!=idx)
    {
        swap(arr[temp_idx], arr[idx]);
        heapify(arr, size, temp_idx);
    }
}

int main()
{
    int arr[6] = {-1, 50, 60, 70, 55, 45};
    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i=(size-1)/2; i>=1; i--)
        heapify(arr, size, i);

    for (int i=1; i<size; i++)
        cout << arr[i] << " ";
}