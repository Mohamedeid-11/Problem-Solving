#include <bits/stdc++.h>
using namespace std;

vector<int> component(int start, auto& graph, auto& vis)
{
    queue<int> q;
    q.push(start);
    vis[start] = true;

    vector<int> comp;
    while (!q.empty()) 
    {
        int node = q.front();
        q.pop();
        comp.push_back(node);

        for (int v : graph[node]) 
        {
            if (!vis[v]) 
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    
    return comp;
}

int main() 
{
    int n, m;
    cin >> n >> m;

    int ans = 0;
    vector<vector<int>> graph(n);
    vector<bool> vis(n, false);

    int u, v;
    for (int i = 0; i < m; i++) 
    {
        cin >> u >> v;
        --u; --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // expand each component and chech if cyclic
    for (int i = 0; i < n; i++) 
    {
        if (vis[i]) continue;

        vector<int> comp = component(i, graph, vis);

        // cyclic if (nodes >= 3 && each node has 2 edges)
        bool cycle = (comp.size() >= 3);
        if(!cycle) continue;
        
        for (int v : comp) 
        {
            if(graph[v].size() != 2)
            {
                cycle = false;
                break;
            }
        }
        if(cycle) ans++;
    }

    cout << ans << '\n';
}