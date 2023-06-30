#include <iostream>
using namespace std;

int sorted_array(int arr[], int size)
{
    if (size==1)
        return 1;

    if (arr[size-1]>=arr[size-2])
        return sorted_array(arr, size-1);

    else
        return 0;
}

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i=0; i<size; i++)
        cin >> arr[i];

    cout << sorted_array(arr, size);
}