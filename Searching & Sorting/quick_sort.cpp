#include <iostream>
using namespace std;

void swap(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int divide_arr(int arr[], int s, int e)
{
    int i = s-1;

    for (int j=s; j<e; j++)
    {
        if (arr[j]<arr[e])
        {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i+1, e);
    return i+1;
}

void quick_sort(int arr[], int s, int e)
{
    if (s<e)
    {
        int pivot = divide_arr(arr, s, e);

        quick_sort(arr, s, pivot-1);
        quick_sort(arr, pivot+1, e);
    }
}

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i=0; i<size; i++)
        cin >> arr[i];

    quick_sort(arr, 0, size-1);

    for (int i=0; i<size; i++)
        cout << arr[i];
}