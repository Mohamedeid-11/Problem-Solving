#include <bits/stdc++.h>
using namespace std;

// Breadth first search
// explores the graph level by level, and gets the shortest path (optimal solution)
// but takes longer time on average


int main()
{
    int n, m, u, v;
    cin >> n >> m;

    // vector<int> adj[n]{};
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u); // if undirected
    }

    // calculate the minimum distance from the starting node to all other nodes (in a connected component)
    vector<int> dist(n, 1e9); 
    dist[0] = 0;

    vector<bool> visited(n, 0);
    visited[0] = 1;

    // start with a frontier that contains the initial state.
    queue<int> q; 
    q.push(0);

    // if the frontier is empty --> no solution.
    while (!q.empty()) 
    {
        // remove a node from the frontier.
        int node = q.front(); 
        q.pop();

        // expand it (add its not explored neighbours to the frontier)
        for (auto child : adj[node])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = 1;
                dist[child] = dist[node] + 1;
            }
        }
    }

}