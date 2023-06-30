#include <iostream>
#include <vector>
using namespace std;

void swap(vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void wave_sort(vector<int> &arr, int size)
{
    for (int i=1; i<size-1; i+=2)
    {
        if (arr[i]>arr[i-1])
            swap(arr, i, i-1);

        if (arr[i]>arr[i+1])
            swap(arr, i, i+1);
    }
}

int main()
{
    int size;
    cin >> size;

    vector<int> arr(size);
    for (int i=0; i<size; i++)
        cin >> arr[i];

    wave_sort(arr, size);

    for (int i=0; i<size; i++)
        cout << arr[i] << " ";
}