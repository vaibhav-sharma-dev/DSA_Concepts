#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int node, edge;
    cin >> node >> edge;

    vector<vector<int> > adj_matrix;

    for (int i=0; i<node+1; i++)
    {
        vector<int> adj_arr;

        for (int j=0; j<node+1; j++)
            adj_arr.push_back(0);

        adj_matrix.push_back(adj_arr);
    }

    for (int i=0; i<edge; i++)
    {
        int x, y;
        cin >> x >> y;

        adj_matrix[x][y] = 1;
        adj_matrix[y][x] = 1;
    }

    for (int i=0; i<node+1; i++)
    {
        for (int j=0; j<node+1; j++)
            cout << adj_matrix[i][j] << " ";

        cout << endl;
    }
}

