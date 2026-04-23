#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int h, w;
vector<string> s;
vector<vector<int>> dp(1000, vector<int>(1000, 0));

int solve(int i, int j)
{
    if(i == h-1 && j == w-1)
        return 1;

    int right_cell = 0, down_cell = 0;
    if(j+1 < h && s[i][j+1] != '#')
        right_cell = solve(i, j+1);

    if(i+1 < w && s[i+1][j] != '#')
        down_cell = solve(i+1, j);

    return (right_cell + down_cell) % MOD;
    
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> h >> w;
    
    for(int i = 0; i < h; i++)
    {
        string temp;
        cin >> temp;

        s.push_back(temp);
    }

    cout << solve(0, 0);
}