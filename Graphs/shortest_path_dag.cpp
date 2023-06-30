#include<iostream>
#include<limits.h>
#include<list>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

class graph
{
    public:
    unordered_map<int, list<pair<int, int> > > adj_list;

    void add_edge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj_list[u].push_back(p);
    }

    void print()
    {
        for (auto i:adj_list)
        {
            cout << i.first << " -> ";
            for (auto j:i.second)
                cout << "(" << j.first << " " << j.second << ") ";

            cout << endl;
        }
    }

    void topological_dfs(vector<bool> &visited, stack<int> &s, int node)
    {
        visited[node] = true;

        for (auto i:adj_list[node])
        {
            if (!visited[i.first])
                topological_dfs(visited, s, i.first);
        }

        s.push(node);
    }

    void shortest_path(int src, vector<int> &distance, stack<int> &s)
    {
        distance[src] = 0;

        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            if (distance[top]!=INT_MAX)
            {
                for (auto i:adj_list[top])
                {
                    if (distance[top]+i.second<distance[i.first])
                        distance[i.first] = distance[top]+i.second;
                }
            }
        }
    }
};


int main()
{
    graph g;
    g.add_edge(0, 1, 5);
    g.add_edge(0, 2, 3);
    g.add_edge(1, 2, 2);
    g.add_edge(1, 3, 6);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 4, 4);
    g.add_edge(2, 5, 2);
    g.add_edge(3, 4, -1);
    g.add_edge(4, 5, -2);

    g.print();

    // Topological Sort
    int n = 6;
    vector<bool> visited(n+1);
    stack<int> s;

    for (int i=0; i<n; i++)
    {
        if (!visited[i])
            g.topological_dfs(visited, s, i);
    }

    int src = 1;
    vector<int> distance(n);

    for (int i=0; i<n; i++)
        distance[i] = INT_MAX;

    g.shortest_path(src, distance, s);

    for (int i=0; i<distance.size(); i++)
        cout << distance[i] << " ";

}