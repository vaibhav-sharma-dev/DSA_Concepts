#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


void vertical_print (int arr[], int size, int idx, int h_distance, map<int, vector<int> > &result)
{
    if (idx>(size-1))
        return;

    int left_node = idx * 2 + 1;
    int right_node = idx * 2 + 2;

    result[h_distance].push_back(arr[idx]);

    vertical_print(arr, size, left_node , h_distance - 1, result);
    vertical_print(arr, size, right_node, h_distance + 1, result);
}


int main()
{
    int bt_arr[7] = {10, 7, 4, 3, 11, 14, 6};
    map<int, vector<int> > result;

    vertical_print(bt_arr, 7, 0, 0, result);

    map<int, vector<int> > :: iterator i;
    for (i=result.begin(); i!=result.end(); i++)
    {
        for (int j=0; j<(i->second).size(); j++)
            cout << (i->second)[j] << " ";

        cout << endl;
    }
}