#include <iostream>
#include <vector>
#include <deque>

using namespace std;


vector<int> sliding_window_max(vector<int> arr, int size, int k)
{
    deque<int> dq;
    vector<int> res;

    int i = 0, j = 0;

    while (i<arr.size())
    {
        if (!dq.empty() && i-k==dq.front())
            dq.pop_front();

        while (!dq.empty() && arr[i]>arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
        
        if (i-j+1==k)
        {
            res.push_back(arr[dq.front()]);
            j++;
        }
        i++;
    }

    return res;
}

int main()
{
    int arr[8] = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> a;
    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i=0; i<size; i++)
        a.push_back(arr[i]);

    int k = 3;

    vector<int> res = sliding_window_max(a, a.size(), k);
    for (int i=0; i<res.size(); i++)
        cout << res[i] << " ";
}