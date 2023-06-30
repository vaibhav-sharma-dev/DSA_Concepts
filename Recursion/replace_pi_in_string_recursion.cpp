#include <iostream>
#include <string>
using namespace std;

void str_replace(string str)
{

    if (str.length()==0)
        return;

    if (str[0]=='p' && str[1]=='i')
    {
        cout << "3.14";
        str_replace(str.substr(2));
    }

    else
    {
        cout << str[0];
        str_replace(str.substr(1));
    }

}

int main()
{
    string str;
    cin >> str;

    str_replace(str);
    //cout << str;
}