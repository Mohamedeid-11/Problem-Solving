#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, a, b, c;
    cin >> t;
    vector<string> arr(t);
    while(t--)
    {
        cin >> a >> b >> c;
        string ans = "NONE";
        if(a < b && b < c) ans = "STAIR";
        else if(a < b && b > c) ans = "PEAK";
        arr.push_back(ans);
    }

    for(auto& s : arr) cout << s << '\n';
}

