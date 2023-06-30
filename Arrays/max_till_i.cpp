// arrays
#include <iostream>
using namespace std;

// 1, 0, 5, 4, 6, 8;

int max_i(int arr[], int size)
{
    int maximum = arr[0];
    for (int i=0; i<=size; i++)
    {
        if (arr[i]>maximum)
            maximum = arr[i];
    }

    return maximum;
}

int main()
{
    int size;
    cout << "Enter Size of array: \n";
    cin >> size;

    int arr[size];
    cout << "Enter elements of array: \n";
    for (int i=0; i<size; i++)
        cin >> arr[i];
    
    int max;
    for (int i=0; i<size; i++)
    {
        max = max_i(arr, i);
        cout << "Max till position " << i << " in array: " << max << endl;
    }
}