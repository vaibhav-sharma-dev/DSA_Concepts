#include <iostream>
#include <stack>

using namespace std;

// {([]})

bool balanced_paranthesis(string str)
{
    stack<char> st;

    for (int i=0; i<str.length(); i++)
    {
        if (str[i]=='(' || str[i]=='[' || str[i]=='{')
            st.push(str[i]);

        else if (!st.empty() && str[i]-st.top()>0 && str[i]-st.top()<=2) 
            st.pop();

        else break;
    }

    return (st.empty());
}

int main()
{
    string str;
    cin >> str;

    cout << balanced_paranthesis(str);
}