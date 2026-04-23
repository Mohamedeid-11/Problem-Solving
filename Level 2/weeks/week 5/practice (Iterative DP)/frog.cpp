#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int h[n];
    for(int i = 0; i < n; i++)
        cin >> h[i];

    int dp[n];
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    for(int i = 2; i < n; i++)
    {
        int cost1 = abs(h[i] - h[i-1]);
        int cost2 = abs(h[i] - h[i-2]);
        dp[i] = min(dp[i-1] + cost1, dp[i-2]+cost2);
    }
    cout << dp[n-1];
}