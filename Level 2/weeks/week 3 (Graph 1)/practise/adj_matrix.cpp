#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int adj[n][n]{}; // building complexity O(n*n)
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--, v--;
        adj[u][v]++;
        adj[v][u]++; // if undirected
    }

    // print
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": ";
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j])
                cout << j + 1 << ' ';
        }
        cout << endl;
    }
}