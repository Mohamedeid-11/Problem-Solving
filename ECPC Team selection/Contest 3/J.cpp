#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, h, m;
    cin >> n;
    int minutes[1440] = {};
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> h >> m;
        minutes[h*60+m]++;
        ans = max(ans,  minutes[h*60+m]);
    }

    cout << ans;
}