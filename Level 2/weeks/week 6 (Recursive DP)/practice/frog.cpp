#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int n;
vector<int> h(1e5 ,0);

int solve(int idx = 0)
{
    if(idx > n-1)
        return 1e9;

    if(idx == n-1)
        return 0;

    int cost1 = solve(idx+1) + abs(h[idx] - h[idx+1]);
    int cost2 = solve(idx+2) + abs(h[idx] - h[idx+2]);

    return min(cost1, cost2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> h[i];
    
    cout << solve();
}