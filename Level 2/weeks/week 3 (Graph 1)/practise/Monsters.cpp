#include <bits/stdc++.h>
using namespace std;

int n, m;
bool valid(int i, int j, vector<vector<char>> &grid)
{
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#');
}

int main()
{
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    // md: shortest distance from any monster to each '.'
    // ad: shortest distance from player to each '.'
    vector<vector<int>> md(n, vector<int>(m, 1e9)), ad(n, vector<int>(m, 1e9));

    int ai = -1, aj = -1; // player coordinates
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'M')  q.push({i, j}), md[i][j] = 0;
            if (grid[i][j] == 'A')  ai = i, aj = j, ad[i][j] = 0;
        }
    }
            //  R  L  D   U
    int di[] = {0, 0, 1, -1};
    int dj[] = {1, -1, 0, 0};

    // BFS to fill md
    while (!q.empty())
    {
        // pair<int, int> p = q.front();
        auto [i, j] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            // next possible point
            int ni = i + di[d];
            int nj = j + dj[d];

            if (valid(ni, nj, grid) && md[ni][nj] == 1e9 /*not visited*/)
            {
                md[ni][nj] = md[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }
    
    
    vector<vector<char>> route(n, vector<char>(m, ' ')); // to store all routes
    int fi = -1, fj = -1;  // exit_point coordinates

    // BFS to fill ad
    q.push({ai, aj});
    while (!q.empty())
    {
        auto [i, j] = q.front();
        q.pop();

        int cost = ad[i][j] + 1;
        
        for (int d = 0; d < 4; d++)
        {
            int ni = i + di[d];
            int nj = j + dj[d];

            if (ni < 0 || nj < 0 || ni >= n || nj >= m) // if next point is out of bound (then we are on a boundary cell)
            {
                fi = i, fj = j;
                break;
            }

            if (valid(ni, nj, grid) && ad[ni][nj] == 1e9 && cost < md[ni][nj]) // we can reach this point before a monster
            {
                ad[ni][nj] = cost;
                q.push({ni, nj});

                if (d == 0) route[ni][nj] = 'R';
                else if (d == 1) route[ni][nj] = 'L';
                else if (d == 2) route[ni][nj] = 'D';
                else route[ni][nj] = 'U';
            }
        }

        // when a boundary cell is reached, we've found a solution(route)
        if (fi != -1) break;
    }

    //  back track to get the route.
    if (fi != -1)
    {
        string path;
        int i = fi, j = fj;
    
        // follow route to reconstruct the path
        while (i != ai || j != aj)
        {
            char dir = route[i][j];
            path += dir;
    
            // move in the opposite direction to trace back
            if (dir == 'R') j--;
            else if (dir == 'L') j++;
            else if (dir == 'D') i--;
            else if (dir == 'U') i++;
        }
    
        reverse(path.begin(), path.end());
        cout << "YES\n" << path.size() << endl;
        cout << path;
    }
    else cout << "NO";

    return 0;
    
}


