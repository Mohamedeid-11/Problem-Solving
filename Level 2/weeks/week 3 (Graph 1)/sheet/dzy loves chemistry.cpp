#include <bits/stdc++.h>
using namespace std;
#define fastio               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);


long long ans = 1;

void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[i] = true;
    for (int ch : adj[i])
    {
        if (!vis[ch])
        {
            ans *= 2;
            dfs(ch, adj, vis);
        }
    }
}

int main()
{
    fastio;
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (m == 1) ans = 2;

    if(m != 1 && m != 0)
    {
        vector<bool> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                dfs(i, adj, vis);
        }
    }
    
    cout << ans << endl;
    return 0;
}