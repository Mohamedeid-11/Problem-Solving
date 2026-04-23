#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
int n;
string dp[N], s[N];

string solve(int idx = 0)
{
    if(idx == n) return "";

    string &ans = dp[idx];

    if(ans != "") return ans;

    string leave = solve(idx+1);
    string take = s[idx] + solve(idx+1);  // s[idx] should come before solve() to canconate correctly

    return ans max(leave, take);
    
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> s[i];
            dp[i] = "";
        }
        cout << solve() << endl;
    }

    return 0;
}