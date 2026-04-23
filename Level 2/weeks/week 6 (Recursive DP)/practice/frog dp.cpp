#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int n;
int N = 1e5;
vector<int> h(N ,0);
vector<int> dp(N ,0);

int solve(int idx)
{
    if(idx > n-1)
        return 2e9;

    if(idx == n-1)
        return 0;

    if(dp[idx] != 2e9)
        return dp[idx];

    int cost1 = solve(idx+1) + abs(h[idx] - h[idx+1]);
    int cost2 = solve(idx+2) + abs(h[idx] - h[idx+2]);

    return dp[idx] = min(cost1, cost2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> h[i];
        dp[i] = 2e9;
    }
    
    cout << solve(0);
}