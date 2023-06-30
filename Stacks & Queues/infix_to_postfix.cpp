#include <iostream>
#include <stack>

using namespace std;

int precedence(char sign)
{
    if (sign=='^')
        return 3;

    else if (sign=='/' || sign=='*')
        return 2;

    else if (sign=='+' || sign=='-')
        return 1;

    else return 0;
}

string infix_to_postfix(string str)
{
    stack<char> st;
    string res;

    for (int i=0; i<str.length(); i++)
    {
        if (str[i]=='(')
            st.push(str[i]);

        else if (str[i]>='0' && str[i]<='9')
            res = res + str[i];

        else if (str[i]==')')
        {
            while (!st.empty() && st.top()!='(')
            {
                res = res + str[i];
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }

        else 
        {
            while (!st.empty() && precedence(str[i])<precedence(st.top()))
            {
                res = res + st.top();
                st.push(str[i]);
            }
        }
    }

    while (!st.empty())
    {
        res = res + st.top();
        st.pop();
    }

    return res;
}

int main()
{
    string str;
    cin >> str;

    cout << infix_to_postfix(str);
}