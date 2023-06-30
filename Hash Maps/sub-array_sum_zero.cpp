#include <iostream>
#include <map>

using namespace std;


int sub_arr_zero_sum (int arr[], int size)
{
    map<int, int> count;
    int pref_sum = 0;

    for (int i=0; i<size; i++)
    {
        pref_sum = pref_sum + arr[i];
        count[pref_sum]++;
    }

    int ans = 0;

    map<int, int> :: iterator it;

    for (it=count.begin(); it!=count.end(); it++)
    {
        int freq = it->second;
        ans = ans + freq*(freq-1)/2;

        if (it->first==0)
            ans = ans + it->second;
    }

    return ans;
}

int main()
{
    int arr[4] = {1, -1, 1, -1};
    int size = sizeof(arr)/sizeof(arr[0]);

    int result = sub_arr_zero_sum(arr, size);
    cout << result << " ";
}