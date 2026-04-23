#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

long long mult(long long a, int b, int mod)
{
    return (a % mod * b % mod) % mod;
}

int fastPower(int b, int p, int mod)
{
    if (p == 0)
        return 1;

    int hp = fastPower(b, p / 2, mod);

    int ans = mult(hp, hp, mod);
    if (p % 2 == 1)
        ans = mult(ans, b, mod);

    return ans;
}

// a^(mod-1) = 1 % mod

// a^(mod-2) = a^(-1) inv

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        // b^c -> MOD-1
        // a^(b^C) ->
        cout << fastPower(a, fastPower(b, c, MOD - 1), MOD) << endl;
    }
    return 0;
}
