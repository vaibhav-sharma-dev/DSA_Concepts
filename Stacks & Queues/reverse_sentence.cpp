#include <iostream>
#include <stack>

using namespace std;

void rev_sentence(string str)
{
    stack<string> st;

    for (int i=0; i<str.length(); i++)
    {
        string word = "";

        while (str[i]!=' ' && i<str.length())
        {
            word = word + str[i];
            i++;
        }

        st.push(word);
    }

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    string str;
    getline(cin, str);

    rev_sentence(str);
}