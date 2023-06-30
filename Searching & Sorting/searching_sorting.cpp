#include <iostream>
using namespace std;

// 2, 4, 8, 3, 9, 7

void selection_sort(int arr[], int size)
{
    // swap least element of array to 1st position.

    for (int i=0; i<size-1; i++)
    {
        for (int j=i+1; j<size; j++)
        {
            if (arr[i]>arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                break;
            }
        }
    }
    cout << "Selection Sorted Array: ";

    for (int i=0; i<size; i++)
        cout << arr[i] << " ";
    
    cout << endl;
}

void bubble_sort (int arr[], int size)
{
    // sort the array by comparing 2 adjacent elements.

    int temp_size = size;
    for (int i=1; i<size; i++)
    {
        for (int j=0; j<temp_size-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        temp_size--;
    }

    cout << "Bubble Sorted Array: ";
    for (int i=0; i<size; i++)
        cout << arr[i] << " ";
    
    cout << endl;
}

void insertion_sort(int arr[], int size)
{
    // Start from 2nd element, sort the array before it.

    for (int i=1; i<size; i++)
    {
        int temp = arr[i], j = i-1;
        while (temp<arr[j])
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    cout << "Insertion Sorted Array: ";
    for (int i=0; i<size; i++)
        cout << arr[i] << " ";
    
    cout << endl;
}

int binary_search(int arr[], int size, int key)
{
    // compare the key to mid of sorted array.
    selection_sort(arr, size);
    bubble_sort(arr, size);
    insertion_sort(arr, size);

   int s = 0, e = size-1, mid;

    while (e >= s)
    {
        mid = s+(e-s)/2;
        if (arr[mid]>key)
        {
            e = mid-1;
        }

        else if (arr[mid]<key)
            s = mid+1;

        else if (arr[mid]==key)
            return 1;

    }
    return -1;

}

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the array: \n";

    for (int i=0; i<size; i++)
        cin >> arr[i];

    int key;
    cout << "Enter the key: ";
    cin >> key;

    int position = binary_search(arr, size, key);
    cout << "Presence of Key: " << position;
}