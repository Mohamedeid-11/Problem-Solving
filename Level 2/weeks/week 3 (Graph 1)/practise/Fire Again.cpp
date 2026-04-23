#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fileio freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

//      right up left down
int dx[] = {1, 0, 0, -1};
int dy[] = {0, 1, -1, 0};

int main()
{
    fastio; fileio;

    int n, m, k;
    cin >> n >> m >> k;

    // (1 ≤ x ≤ n   |   1 ≤ y ≤ m)
    vector<vector<bool>> vis(n+1, vector<bool>(m+1, 0)); // 1 based map
    queue<pair<int, int>> q;
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        q.push({x, y});
        vis[x][y] = 1;
    }

    int last_x = 0, last_y = 0;

    // BFS
    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        last_x = x, last_y = y;     // brute force, cosider the current node is the target(last tree) 

        for(int d = 0; d < 4; d++)
        {
            int new_x = x + dx[d];
            int new_y = y + dy[d];
            bool in_bound = (new_x >= 1 && new_x <= n) && (new_y >= 1 && new_y <= m);

            if (in_bound && !vis[new_x][new_y])
            {
                vis[new_x][new_y] = 1;
                q.push({new_x, new_y});
            }
        }
    }

    cout << last_x << ' ' << last_y;

    return 0;
}

