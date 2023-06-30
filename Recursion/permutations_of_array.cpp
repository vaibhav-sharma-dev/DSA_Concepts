#include <iostream>
using namespace std;

// 123

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void permutation(int arr[], int sol_arr[], int size, int idx)
{
    if (idx==size)
    {
        for (int x=0; x<size; x++)
            sol_arr[x] = arr[x];

        for (int i=0; i<size; i++)
            cout << sol_arr[i];

        cout << endl;
        return;
    }
    for (int i=idx; i<size; i++)
    {
        swap(arr[i], arr[idx]);
        permutation(arr, sol_arr, size, idx+1);
        swap(arr[i], arr[idx]);
    }
}

int main()
{
    int size;
    cin >> size;

    int arr[size];
    for (int i=0; i<size; i++)
        cin >> arr[i];

    int sol_arr[size];
    for (int i=0; i<size; i++)
        sol_arr[i] = 0;

    permutation(arr, sol_arr, size, 0);

    //for (int i=0; i<size; i++)
    //    cout << sol_arr[i];
}