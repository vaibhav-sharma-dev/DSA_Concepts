#include <iostream>
#include <vector>
using namespace std;

vector <int> count_sort(vector <int> arr, int size)
{
    int max_arr = *max_element(arr.begin(), arr.end());

    vector <int> count_arr(max_arr+1, 0);

    for (int i=0; i<arr.size(); i++)
        count_arr[arr[i]]++;

    for (int i=1; i<count_arr.size(); i++)
        count_arr[i] = count_arr[i] + count_arr[i-1];

    vector <int> result(size);

    for (int i=size-1; i>=0; i--)
    {
        result[count_arr[arr[i]]-1] = arr[i];
        count_arr[arr[i]]--;
    }
    
    return result;
}

int main()
{
    int size;
    cin >> size;

    vector<int> arr(size);
    for (int i=0; i<arr.size(); i++)
        cin >> arr[i];

    vector <int> result = count_sort(arr, size);    
    for (int i=0; i<result.size(); i++)
        cout << result[i] << " ";

}