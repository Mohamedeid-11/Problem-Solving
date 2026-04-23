#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, w;
    cin >> n >> w;
    vector<long long> weight(n+5), val(n+5);  
    for(int i = 1; i <= n; i++)
        cin >> weight[i] >> val[i];

    long long dp[n+5][w+5] {};

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= w; j++)
        {
            long long leave = dp[i-1][j];
            long long take = (j >= weight[i]) ? val[i] + dp[i - 1][j - weight[i]] : 0;

            dp[i][j] = max(leave, take);
        }
    }

    cout << dp[n][w] << endl;

}