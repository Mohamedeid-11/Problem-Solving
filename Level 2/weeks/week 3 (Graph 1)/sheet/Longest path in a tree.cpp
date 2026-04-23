#include <bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
pair<int, int> longest_path;

void bfs(int i, vector<vector<int>>& adj)
{
    longest_path = {0, 0};
    vector<int> rank(n, 0);     // 0 if not visited
    queue<int> q;

    q.push(i);
    rank[i] = 1;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int c : adj[node])
        {
            if(!rank[c])
            {
                q.push(c);
                rank[c] = rank[node]+1;
                if (longest_path.second < rank[c]) 
                {
                    longest_path.first = c;
                    longest_path.second = rank[c];
                }
            }
        }
    }
}

int main()
{
    fastio;

    cin >> n;
    vector<vector<int>> adj(n);

    int a, b;
    for(int i = 0; i < n-1; i++)
    {
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(0, adj);
    bfs(longest_path.first, adj);

    cout <<  longest_path.second-1 << endl;
    
    return 0;
}