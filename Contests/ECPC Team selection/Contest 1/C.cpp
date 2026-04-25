#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int max_even = 0, max_odd = 0;
    ll ans = -1;

    for(int i=0; i<n; i++) 
    {
        int temp; cin >> temp;
        if(temp % 2 == 0) max_even = max(max_even, temp);
        else max_odd = max(max_odd, temp);
    }

    ans = max_even + max_odd;
    if(!max_even || !max_odd) ans = -1;
    cout << ans;
}

