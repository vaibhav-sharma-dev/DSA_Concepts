#include <iostream>
#include <stack>

using namespace std;

void insert_at_bottom(stack<int> &st, int element)
{
    if (st.empty())
    {
        st.push(element);
        return;
    }

    int top_ele = st.top();

    st.pop();
    insert_at_bottom(st, element);

    st.push(top_ele);
}

void reverse_stack(stack<int> &st)
{
    if (st.empty())
        return;

    int top_ele = st.top();
    
    st.pop();
    reverse_stack(st);

    insert_at_bottom(st, top_ele);
}

int main()
{
    stack<int> st;
    int size;
    cin >> size;

    for (int i=0; i<size; i++)
    {
        int ele;
        cin >> ele;
        st.push(ele);
    }

    reverse_stack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}