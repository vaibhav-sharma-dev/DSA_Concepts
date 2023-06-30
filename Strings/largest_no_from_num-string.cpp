#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 5872

int main()
{
    string num_str;
    cin >> num_str;

    int size = num_str.length();
    int num_max = INT_MIN;

    int num = stoi(num_str);

    for (int i=0; i<size; i++)
    {
        num_max = max(num_max, num%10);
        num = num/10;
    }

    cout << num_max;
    
}