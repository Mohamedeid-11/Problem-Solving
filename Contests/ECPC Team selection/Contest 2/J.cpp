#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t, n, k;
    cin >> t;
    while (t--) 
    {
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        string ans = "NO";
        if (k == 1) 
        {
            if (is_sorted(a.begin(), a.end())) ans = "YES";
        } 
        else ans = "YES";
        
        cout << ans << '\n';
    }

    return 0;
}