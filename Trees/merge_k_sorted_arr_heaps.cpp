#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int arr_no;
    cin >> arr_no;

    vector<vector<int> > arr(arr_no);

    for (int i = 0; i < arr_no; i++)
    {
        int size;
        cin >> size;

        arr[i] = vector<int>(size);

        for (int j = 0; j < size; j++)
            cin >> arr[i][j]; 
    }

    vector<int> idx(0);
    priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > min_heap;

    for (int i = 0; i < arr_no; i++)
        min_heap.push(arr[i][0], i);

    vector<int> result;

    while (!min_heap.empty())
    {
        pair<int, int> val = min_heap.top();
        result.push_back(val.ff);
        min_heap.pop();
    }
}

// 1, 4, 7
// 3, 5
// 2, 6, 7