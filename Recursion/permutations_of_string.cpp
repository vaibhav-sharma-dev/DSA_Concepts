#include <iostream>
#include <string>

using namespace  std;

void permutation_string(string str, string ans)
{
    if (str.length()==0)
    {
        cout << ans << endl;
        return;
    }
    
    for (int i=0; i<str.length(); i++)
    {
        char temp = str[i];
        string ros = str.substr(0, i) + str.substr(i+1);
        permutation_string(ros, ans+temp);
    }

}

int main()
{
    string str;
    cin >> str;

    string ans = "";

    permutation_string(str, ans);
}