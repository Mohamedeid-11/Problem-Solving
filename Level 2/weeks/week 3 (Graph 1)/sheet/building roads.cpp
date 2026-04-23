#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[i] = true;
    for(int n : adj[i]) 
        if(!vis[n]) dfs(n, adj, vis);
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
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n, false);
    vector<int> new_road;
    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            dfs(i, adj, vis);
            if(i != 0) new_road.push_back(i+1);
        }
    }
    

    // num of new routes
    cout << new_road.size() << endl;

    for(int i = 0; i < new_road.size(); i++)
        cout << new_road[i]-1 << ' ' << new_road[i] << endl;

}