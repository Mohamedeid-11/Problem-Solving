#include <bits/stdc++.h>
using namespace std;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr);

int h, w; // array dimensions
vector<vector<bool>> vis;

// what adds to i, j after moving a step in each of the four directions
int di[] = {1, 0, 0, -1};
int dj[] = {0, 1, -1, 0};

void dfs(int i, int j, vector<string> &arr)
{
    vis[i][j] = 1;
    for (int d = 0; d < 4; d++)
    {
        int new_i = i + di[d];
        int new_j = j + dj[d];
        bool in_bound = (new_i >= 0 && new_i < h) && (new_j >= 0 && new_j < w);

        if (in_bound && !vis[new_i][new_j] && arr[new_i][new_j] == arr[i][j])
            dfs(new_i, new_j, arr);
    }
}

int main()
{
    fastio;

    int t;
    cin >> t;
    for (int world = 1; world <= t; world++)
    {
        cin >> h >> w;

        vis.clear();
        vis.resize(h);

        vector<string> arr(h);
        for (int i = 0; i < h; i++)
            cin >> arr[i], vis[i].resize(w);

        int states['z' + 1] = {};
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (!vis[i][j])
                {
                    states[arr[i][j]]++;
                    dfs(i, j, arr);
                }
            }
        }

        vector<pair<int, char>> ans;
        for (char c = 'a'; c <= 'z'; c++)
        {
            if (states[c])
                ans.push_back({-states[c], c}); // order states descendingly 3 2 1 and characters ascendingly a b c
        }
        // sort according to num of states, if equal according to lettes
        sort(ans.begin(), ans.end());

        cout << "World #" << world << endl;
        for (auto &p : ans)
            cout << p.second << ": " << -p.first << endl;
    }
}
