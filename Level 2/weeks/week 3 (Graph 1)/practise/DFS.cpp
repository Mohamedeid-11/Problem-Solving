#include <bits/stdc++.h>
using namespace std;

// Depth first search
// its priority is to reach the deepest node

int const N = 1e4;
bool vis[N]{};
vector<int> adj[N]{};
void dfs(int node)
{
    vis[node] = true;
    cout << node + 1 << " ";
    // for each neighbour of node
    for (long long unsigned int i = 0; i < adj[node].size(); i++)
    {
        int v = adj[node][i];
        // get dvs if not visited
        if (!vis[v])
            dfs(v);
    }
}

int main()
{
    int n, m, n1, n2;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n1 >> n2;
        adj[n1].push_back(n2);
        adj[n2].push_back(n1); // if undirected graph
    }

    // dfs will visit all the nodes in one component
    // so each unvisited node means that it's a part of a new component
    int components = 0;
    for (int i = 1; i < n; i++) // 1 based braph
    {
        if (!vis[i])
        {
            components++;
            dfs(i);
        }
    }
    cout << "\ncomponents: " << components;
}