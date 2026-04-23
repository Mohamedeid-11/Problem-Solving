#include <bits/stdc++.h>
using namespace std;

int const N = 1e5;
bool cycle;
vector<int> adj[N]{}, deg(N); // in degree
vector<int> topo;

int main()
{
    int n, m, u, v;
    cin >> n >> m;

    vector<int> adj[n]{};
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }

    priority_queue<int> q;

    for(int node = 1; node <= n; n++)
    if(!deg[node]) q.push(-node);

    while(q.size())
    {
        int node = -q.top();
        q.pop();

        topo.push_back(node);

        for (auto ch : adj[node])
        {
            if (!deg[ch])
            {
                deg[ch]--;
                if(!deg[ch]) q.push(ch);
            }
        }
    }

    //
}