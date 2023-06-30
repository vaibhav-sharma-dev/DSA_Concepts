#include <iostream>
using namespace std;

void merge_arr(int arr[], int s, int mid, int e)
{
    int n1 = mid+1-s;
    int n2 = e-mid;

    int temp_1[n1];
    int temp_2[n2];

    for (int i=0; i<n1; i++)
        temp_1[i] = arr[s+i];

    for (int i=0; i<n2; i++)
        temp_2[i] = arr[mid+1+i];

    int i = 0; 
    int j = 0;
    int k = s;

    while (i<n1 && j<n2)
    {
        if (temp_1[i]>temp_2[j])
        {
            arr[k] = temp_2[j];
            j++;
            k++;
        }
        
        else
        {
            arr[k] = temp_1[i];
            i++;
            k++;
        }
    }

    while (i<n1)
    {
        arr[k] = temp_1[i];
        i++;
        k++;
    }

    while (j<n2)
    {
        arr[k] = temp_2[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int s, int e)
{
    if (s<e)
    {
        int mid = (s+e)/2;

        merge_sort(arr, s, mid);
        merge_sort(arr, mid+1, e);

        merge_arr(arr, s, mid, e);
    }
}

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i=0; i<size; i++)
        cin >> arr[i];

    merge_sort(arr, 0, size-1);

    for (int i=0; i<size; i++)
        cout << arr[i] << " ";
}