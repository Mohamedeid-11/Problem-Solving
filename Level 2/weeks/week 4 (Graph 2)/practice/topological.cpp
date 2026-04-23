#include <bits/stdc++.h>
using namespace std;

// Depth first search
// it priority is to reach the deepest node

int const N = 1e4;
bool vis[N]{};
vector<int> adj[N]{};
stack<int> topo;

void dfs(int node)
{
    vis[node] = true;

    for (long long unsigned int i = 0; i < adj[node].size(); i++)
    {
        int v = adj[node][i];
        if (!vis[v])
            dfs(v);
    }

    topo.push(node);
}

int main()
{
    int n, m, n1, n2;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
    }

    
    for (int i = 1; i < n; i++) // 1 based braph
    {
        if (!vis[i]) dfs(i);
    }

    while(topo.size())
    {
        cout << topo.top() << ' ';
        topo.pop();
    }
}