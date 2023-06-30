#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int arr[26];
    for (int i=0; i<26; i++)
        arr[i] = 0;

    for (int i=0; i<str.length(); i++)
        arr[str[i]-'a']++;

    int max_arr = arr[0];
    int pos = 0;
    for (int i=0; i<26; i++)
    {
        if (arr[i]>max_arr)
        {
            max_arr = arr[i];
            pos = i;
        }
    }

    string element = "a";
    element[0] = element[0] + pos;
    
    cout << element << endl;
    cout << max_arr;
}