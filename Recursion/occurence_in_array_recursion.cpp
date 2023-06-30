#include <iostream>
using namespace std;

int first_occurence(int arr[], int size, int n, int c_first)
{
    if (c_first==size)
        return -1;

    if (arr[0]==n)
        return c_first;

    return first_occurence(arr+1, size-1, n, c_first+1);
}

int last_occurence(int arr[], int size, int n, int c_last)
{
    if (c_last==1)
        return -1;

    if (arr[size-1]==n)
        return c_last;

    return last_occurence(arr, size-1, n, c_last-1);
}


int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i=0; i<size; i++)
        cin >> arr[i];

    int n;
    cin >> n;

    int c_first = 0, c_last = size-1;

    cout << first_occurence(arr, size, n, c_first) << endl;
    cout << last_occurence(arr, size, n, c_last);

}