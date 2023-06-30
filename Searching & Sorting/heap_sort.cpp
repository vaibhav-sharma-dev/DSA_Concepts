#include <iostream>
using namespace std;


void heapify(int arr[], int size, int idx)
{
    int temp_idx = idx;
    int left_idx = idx*2;
    int right_idx = idx*2 + 1;

    if (left_idx<size && arr[left_idx]>=arr[temp_idx])
        temp_idx = left_idx;

    if (right_idx<size && arr[right_idx]>=arr[temp_idx])
        temp_idx = right_idx;

    if (temp_idx!=idx)
    {
        swap(arr[idx], arr[temp_idx]);
        heapify(arr, size, temp_idx);
    }
}


void heap_sort(int arr[], int size)
{
    int n = size;

    while (n>1)
    {
        swap(arr[0], arr[size-1]);
        n--;

        heapify(arr, n, 0);
    }
}


int main()
{
    int arr[6] = {-1, 50, 60, 70, 55, 45};
    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i=(size-1)/2; i>=1; i--)
        heapify(arr+1, size-1, i);

    //heap_sort(arr+1, size-1);

    for (int i=1; i<size; i++)
        cout << arr[i] << " ";
}

// 70, 60, 55, 45, 50