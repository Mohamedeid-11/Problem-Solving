#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool found_start_node = false;

void dfs(int i, int s, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[i] = true;
    for(int n : adj[i])
    {
        if(!vis[n]) 
            dfs(n, s, adj, vis);
        else if(s == n)
        {
            found_start_node = true;
            return;
        }
    }
}

int main()
{
    fastio;

    int n, m, a, b;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    while(m--)
    {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    
    
    for(int i = 0; i < n; i++)
    {
        vector<bool> vis(n, false);
        dfs(i, i, adj, vis);
        
        if(found_start_node) break;
    }
    
    if(found_start_node) cout << 1 << endl;
    else cout << 0 << endl;
    
    return 0;
}