#include <bits/stdc++.h>
using namespace std;

const int N = 3010;
string s, t;
int dp[N][N];

int solve(int i = 0, int j = 0)
{
    if(i == s.size() || j == t.size())
    return 0;


    int &ans = dp[i][j];
    if(ans != -1)
        return ans;

    if(s[i] == t[j])
        return ans = solve(i+1, j+1) + 1;   // move both curseres and add character
    return ans = max(solve(i+1, j), solve(i, j+1));     // try move each curser alone
} 

string ans;
void build(int i = 0, int j = 0)
{
    if(i == s.size() || j == t.size())
    return;

    if(s[i] == t[j])
    {
        ans.push_back(s[i]);
        build(i+1, j+1);
        return;
    }

    int one = solve(i+1, j);
    int two = solve(i, j+1);
    if(one > two)
        build(i+1, j);
    else
        build(j, i+1);
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> t;
    memset(dp, -1, sizeof dp);

    cout << solve() << endl;
    build(); cout << ans;
}