#include <bits/stdc++.h>
using namespace std;

void printPath(int node, vector<int>& parent) {
    if (node == -1) return;
    printPath(parent[node], parent);
    cout << node << " ";
}

int main() {
    int n, m, u, v, w; 
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];
    while (m--) {
        cin >> u >> v >> w;
        adj[u].emplace_back(w, v);
        adj[v].emplace_back(w, u);
    }

    int src = 1;
    vector<int> dist(n + 1, INT32_MAX);
    dist[src] = 0;

    vector<int> parent(n + 1, -1); //store parent of each node in the shortest path

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, src);

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int weight = edge.first;
            int v = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }

    // Print all paths and distances
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT32_MAX) {
            cout << "Node " << i << " is unreachable from node " << src << ".\n";
        } else {
            cout << "Shortest path to node " << i << " (distance " << dist[i] << "): ";
            printPath(i, parent);
            cout << endl;
        }
    }

    return 0;
}