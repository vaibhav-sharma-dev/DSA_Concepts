#include <iostream>
#include <string>

using namespace std;

// abc

void sub_strings(string str, string ans)
{
    if (str.length()==0)
    {
        cout << ans << endl;
        return;
    }

    char temp = str[0];
    sub_strings(str.substr(1), ans);
    sub_strings(str.substr(1), ans+temp);

}

int main()
{
    string str;
    cin >> str;

    string ans = "";

    sub_strings(str, ans);
    return 0;
}