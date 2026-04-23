#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> dp;
bool func(int n, int m)
{
    if (n == m)
        return true;

    if (n % 3 != 0)
        return false;

    // if the unique key (n * 5 + m) is not in the map, calculate it
    if (dp.find(n * 5 + m) == dp.end())
        dp[n * 5 + m] = func(n / 3, m) || func(2 * n / 3, m);

    return dp[n * 5 + m];
}

int main()
{
    int t;
    cin >> t;

    int n, m;
    while (t--)
    {
        cin >> n >> m;
        dp.clear();
        cout << (func(n, m) ? "YES" : "NO") << endl;
    }
}
