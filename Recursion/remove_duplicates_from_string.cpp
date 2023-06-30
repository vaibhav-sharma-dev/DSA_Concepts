#include <iostream>
#include <string>

using namespace std;

// aabbccdd

string remove_duplicates(string str)
{
    if (str.length()==0)
        return "";

    char x = str[0];
    string new_str = remove_duplicates(str.substr(1));

    if (new_str[0]==x)
        return new_str;
    
    else
        return (x+new_str);

}

int main()
{
    string str;
    cin >> str;

    cout << remove_duplicates(str);
}