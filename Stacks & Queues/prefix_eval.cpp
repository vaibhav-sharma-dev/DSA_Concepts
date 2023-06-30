#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

// - + 7 * 4 5 + 2 0

int operation(int a, int b, char operand)
{
    if (operand=='+')
        return a+b;

    else if (operand=='-')
        return a-b;

    else if (operand=='*')
        return a*b;

    else if (operand=='/')
        return a/b;

    else if (operand=='^')
        return pow(a,b);
    else 
        return a+b;
}

int prefix_eval(string str)
{
    int l = str.length();
    int op1 = 0, op2 = 0;
    stack<int> res;

    for (int i=l-1; i>=0; i--)
    {
        if (str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
        {
            op1 = res.top();
            res.pop();

            op2 = res.top();
            res.pop();

            int opr_res = operation(op1, op2, str[i]);
            //cout << opr_res << endl;
            res.push(opr_res);
        }
        
        else
            res.push(str[i]-'0');
    }

    return res.top();
}

int main()
{
    string str;
    cin >> str;

    int res = prefix_eval(str);

    cout << res;

}