// arrays
#include <iostream>
using namespace std;

// 1, 2, 0, 7, 2

int main()
{
    int size;
    cout << "Enter size of array: \n";
    cin >> size;

    int arr[size];
    cout << "Enter the array: \n";
    for (int i=0; i<size; i++)
        cin >> arr[i];
    
    int sum = 0;
    for (int i=0; i<size; i++)
    {
        sum = 0;
        for (int j=i; j<size; j++)
        {
            sum = sum + arr[j];
            cout << "Sum of Sub-array: " << sum << endl;
        }
    }
}