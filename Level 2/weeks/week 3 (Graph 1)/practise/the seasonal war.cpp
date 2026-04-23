#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


vector<vector<bool>> vis(25, vector<bool>(25, false));
vector<string> arr(25);

// picture side length  (picture is a square)
int lng;

// from left top to right down
int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int i, int j, vector<string> &arr, vector<vector<bool>> &vis)
{
    vis[i][j] = true;

    for(int d = 0; d < 8; d++)
    {
        int new_i = i + di[d];
        int new_j = j + dj[d];
        bool in_bound = new_i >= 0 && new_i < lng && new_j >= 0 && new_j < lng; 
        
        if(in_bound && arr[new_i][new_j] == '1' && !vis[new_i][new_j])
            dfs(new_i, new_j, arr, vis);
    }
}
int main()
{
    fastio;

    int pic_num = 0;
    while (cin >> lng)
    {
        pic_num++;
        for (int i = 0; i < lng; i++) 
        {
            cin >> arr[i];
            fill(vis[i].begin(), vis[i].begin() + lng, false);
        }

        int war_eagles = 0;
        for (int i = 0; i < lng; i++)
        {
            for (int j = 0; j < lng; j++)
            {
                if (arr[i][j] == '1' && !vis[i][j])
                {
                    dfs(i, j, arr, vis); 
                    war_eagles++; 
                }
            }
        }

        cout << "Image number " << pic_num << " contains " << war_eagles << " war eagles." << endl;
    }

    return 0;
}

