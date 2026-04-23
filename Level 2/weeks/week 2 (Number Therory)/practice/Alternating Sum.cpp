#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;

ll mult(ll a, ll b)
{
    return (a % mod * b % mod) % mod;
}

ll add(ll a, ll b)
{
    return (a % mod + b % mod + mod) % mod;
}

ll fastPower(ll b, ll p)
{
    if (p == 0)
        return 1;

    ll hp = fastPower(b, p / 2);

    ll ans = mult(hp, hp);
    if (p % 2 == 1)
        ans = mult(ans, b);

    return ans;
}

ll inv(ll a)
{
    return fastPower(a, mod - 2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, k;
    cin >> n >> a >> b >> k;
    string s;
    cin >> s;

    ll cycle = 0;
    for (int i = 0; i < k; i++)
    {
        int cur = ((s[i] == '+') ? 1 : -1);
        ll x = mult(cur, mult(fastPower(a, n - i), fastPower(b, i)));
        cycle = add(cycle, x);
    }

    ll r = mult(fastPower(b, k), inv(fastPower(a, k)));
    ll m = (n + 1) / k;
    if (r == 1)
    {
        cout << mult(m, cycle) << endl;
    }
    else
    {
        ll ans = add(1, -fastPower(r, m));
        ll inve = inv(add(1, -r));
        ans = mult(ans, inve);
        cout << mult(ans, cycle) << endl;
    }

    return 0;
}