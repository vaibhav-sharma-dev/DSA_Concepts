#include <iostream>
using namespace std;

int largest_rect_histogram(int arr[], int size)
{
    int max_area = 0;
    cout << size << "\n";
    for (int i=0; i<size; i++)
    {
        int l = 0;
        int prev_largest = i;
        while (arr[prev_largest]>=arr[i] && prev_largest>=0)
        {
            l++;
            prev_largest--;
        }

        int front_largest = i;
        while (arr[front_largest]>=arr[i] && front_largest<size)
        {
            l++;
            front_largest++;
        }

        int area = (l-1)*arr[i];
        max_area = max(max_area, area);
    }

    return max_area;
}

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i=0; i<size; i++)
        cin >> arr[i];

    cout << largest_rect_histogram(arr, size);
}