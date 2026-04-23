#include <bits/stdc++.h>
using namespace std;

vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
map<string, int> idx;

vector<int> g[8];
bool vis[8];

/*  In a path, each node has ≤ 2 neighbors
    One neighbor is the previous node (already visited)
    At most one other neighbor exists → (the correct next node)
*/ 
void walk(int node, vector<int>& comp)
{
    vis[node] = true;
    comp.push_back(node);

    for (int next : g[node]) {
        if (!vis[next]) {
            walk(next, comp);
        }
    }
}

int main() 
{
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    for (int i = 0; i < 8; i++) idx[cows[i]] = i;

    // input
    int n; cin >> n;
    for (int i = 0; i < n; i++) 
    {
        string x, t, y;
        cin >> x >> t >> t >> t >> t >> y;

        int u = idx[x], v = idx[y];
        g[u].push_back(v);
        g[v].push_back(u);
    }

    map<int, vector<int>> components; // order components by their smallest endpoint
    
    // walk through each component (starting from the smallest endpoint)
    for (int i = 0; i < 8; i++) 
    {
        // if unvisited endpoint --> walk through its component
        if (!vis[i] && g[i].size() <= 1) 
        {   
            vector<int> comp;
            walk(i, comp);
            components[comp.front()] = comp;
        }
    }

    // print 
    for (auto &[start, component] : components) 
    {
        for (int u : component) cout << cows[u] << '\n';
    }
}