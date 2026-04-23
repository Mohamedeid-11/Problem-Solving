#include <bits/stdc++.h>
using namespace std;

int const N = 101;
bool vis[N]{};
vector<int> adj[N]{};
void dfs(int node)
{
    vis[node] = true;
    for (long long unsigned int i = 0; i < adj[node].size(); i++)
    {
        int v = adj[node][i];
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
        adj[n2].push_back(n1);
    }

    int components = 0;
    for (int i = 1; i < n; i++)
    {
        if (!vis[i])
        {
            components++;
            dfs(i);
        }
    }
    cout << (components == 1 ? "YES" : "NO");
}