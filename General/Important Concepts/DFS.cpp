#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[N];
bool visited[N];

void dfs(int node)
{
    // visited[node] = true;
    // cout << node + 1 << " ";

    // for (auto neighbour : adj[node])
    // {
    //     if (!visited[neighbour])
    //        dfs(neighbour);
    // }
    stack<int> frontier;
    frontier.push(node);

    while(!frontier.empty())
    {
        int node = frontier.top();
        frontier.pop();
        if(!visited[node])
        {
            visited[node] = true;
            cout << node + 1 << " ";

            for(auto child : adj[node])
            {
                if(!visited[child])
                    frontier.push(child);
            }
        }
    }
}

int main() 
{
    cin >> n >> m;
    
    int n1, n2;
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
        if (!visited[i])
        {
            components++;
            dfs(i);
        }
    }
    cout << "\ncomponents: " << components;
}