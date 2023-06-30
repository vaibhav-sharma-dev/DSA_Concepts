#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 5286

int main()
{
    string str;
    cin >> str;
    
    for (int i=0; i<str.length()-1; i++)
    {
        for (int j=i+1; j<str.length(); j++)
        {
            if (str[i]<str[j])
            {
                char temp = str[j];
                str[j] = str[i];
                str[i] = temp;
            }
        }
    }

    cout << str;
}