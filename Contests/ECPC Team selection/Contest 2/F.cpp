#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    ll l, r;
    int t, n;
    cin >> t;
    while (t--) 
    {
        cin >> n >> l >> r;

        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        ll sum = 0;
        int used_cards = 0, wins = 0;

        for (int cur_card = 0; cur_card < n; cur_card++) 
        {
            sum += a[cur_card];

            // discard cards from the left while (you can and sum > r)
            while (used_cards <= cur_card && sum > r) 
            {
                sum -= a[used_cards];
                used_cards++;
            }

            if (l <= sum && sum <= r) 
            {
                wins++;
                sum = 0;
                used_cards = cur_card + 1;
            }
        }

        cout << wins << '\n';
    }
}