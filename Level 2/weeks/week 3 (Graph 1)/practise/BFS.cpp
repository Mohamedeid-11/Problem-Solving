#include <bits/stdc++.h>
using namespace std;

// Breadth first search
// its priority is to end level by level
// process nodes level by level
// gets the shortest path

int main()
{
    int n, m, u, v;
    cin >> n >> m;

    vector<int> adj[n]{};
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u); // if undirected
    }

    vector<int> dist(n, 1e9);
    dist[0] = 0;
    vector<bool> vis(n, 0);
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto ch : adj[cur])
        {
            if (!vis[ch])
            {
                q.push(ch);
                vis[ch] = 1;
                dist[ch] = dist[cur] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << i + 1 << " level is: " << dist[i] << endl;
}