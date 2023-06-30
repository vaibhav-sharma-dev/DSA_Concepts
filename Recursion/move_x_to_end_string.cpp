#include <iostream>
#include <string>

using namespace std;

// axxbdxcefxhix

string move_x_to_end(string str)
{
    if (str.length()==0)
        return "";

    char temp = str[0];
    string result = move_x_to_end(str.substr(1));
    
    if (temp=='x')
        return (result+temp);
    
    else
        return (temp+result);
}

int main()
{
    string str;
    cin >> str;

    cout << move_x_to_end(str);
}