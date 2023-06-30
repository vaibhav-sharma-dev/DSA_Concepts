#include <iostream>
#include <vector>
using namespace std;

void swap(vector <int> &arr, int mid, int element)
{
    int temp = arr[mid];
    arr[mid] = arr[element];
    arr[element] = temp;
}

void dnf_sort(vector <int> &arr, int size)
{
    int low = 0;
    int mid  = 0;
    int high = size-1;

    while (mid<=high)
    {
        if (arr[mid]==0)
        {
            swap(arr, mid, low);
            mid++;
            low++;
        }

        else if(arr[mid]==2)
        {
            swap(arr, mid , high);
            high--;
        }

        else
            mid++;
    }
}

int main()
{
    int size;
    cin >> size;

    vector <int> arr(size, 0);
    for (int i=0; i<size; i++)
        cin >> arr[i];

    dnf_sort(arr, size);

    for (int i=0; i<size; i++)
        cout << arr[i] << " ";
}