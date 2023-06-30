#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

class graph
{
    public:
    unordered_map <int, list<int> > adj_list;

    void add_edge(int u, int v, bool direction)
    {
        adj_list[u].push_back(v);

        // direction -> false :: uni-directional
        // direction -> true :: bi-directional
        if (!direction)
            adj_list[v].push_back(u);
    }

    void print_graph()
    {
        for (auto i:adj_list)
        {
            cout << i.first << " -> ";

            for (auto j:i.second)
                cout << j << " ";

            cout << endl;
        }
    }
};

int main()
{
    graph g;

    int node;
    cin >> node;

    int edge;
    cin >> edge;

    for (int i=0; i<edge; i++)
    {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v, false);
    }

    g.print_graph();
}