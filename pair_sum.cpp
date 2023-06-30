// find pair of numbers whose sum is equal to N

#include <iostream>
using namespace std;

void bubble_sort(int arr[], int size)
{
    int temp_size = size;
    
    for (int i=1; i<size; i++)
    {
        for (int j=0; j<temp_size-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
        temp_size--;
    }
}

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i=0; i<size; i++)
        cin >> arr[i];

    int key;
    cin >> key;

    bubble_sort(arr, size);

    int s = 0;
    int e = size-1;

    while (e>s)    {
        if (arr[s]+arr[e] == key)
        {
            cout << s << " " << e;
            return 1;
        }

        else if (arr[s]+arr[e] > key)
            e--;
        
        else if (arr[s]+arr[e] < key)
            s++;
    }
    return 0;

}