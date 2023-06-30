#include <iostream>
#include <string>

using namespace std;

void sub_strings_ascii(string str, string ans)
{
    if (str.length()==0)
    {
        cout << ans << endl;
        return;
    }

    char temp_str = str[0];
    int temp_int = str[0];
    string temp = to_string(temp_int);
    sub_strings_ascii(str.substr(1), ans);
    sub_strings_ascii(str.substr(1), ans+temp_str);
    sub_strings_ascii(str.substr(1), ans+temp);
}

int main()
{
    string str;
    cin >> str;

    string ans = "";

    sub_strings_ascii(str, ans);
}