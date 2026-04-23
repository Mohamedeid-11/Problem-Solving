#include <bits/stdc++.h>
using namespace std;

string s[3];
int combine(int i, int j, int, x)
{
    string combined;

    int l = 0, r = 0;
    int cur_sub = 0, max_sub = 0;
    while (l < s[i].size() && r < s[j].size())
    {
        if(s[i][l] != s[j][r]) 
        {
            max_sub = max(max_sub, cur_sub)
            cur_sub = 0;
        }
        else
        {
            
        }
        l++; r++

    }
    combined = s[i].substr(0, s[i].size()-idx);
    combined += s[j];

    idx = 0;
    while (combined[idx] == s[j][idx])
    {
        idx++;
    }
    combined = s[i].substr(0, s[i].size()-idx);
    combined += s[j];

    

    return combined.size();
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s[0] >> s[1] >> s[2];

    int ans = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = i+1; j<3, j++)
        {
            ans = max(ans, combine(i, j, 3 - i - j));
        }
    }   
    cout << ans;
}