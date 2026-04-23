#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // int adj[n][m]; // building complexity O(n*m)
    vector<int> adj[n];

    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u); // if undirected
    }

    // print
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": ";
        for (auto j : adj[i])
        {
            cout << j + 1 << ' ';
        }
        cout << endl;
    }
}