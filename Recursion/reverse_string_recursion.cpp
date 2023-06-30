#include <iostream>
#include <string>
using namespace std;

void str_rev(string str)
{
    if (str.length()==0)
        return;

    str_rev(str.substr(1));
    cout << str[0];
}

int main()
{
    string str;
    cin >> str;

    str_rev(str);
}