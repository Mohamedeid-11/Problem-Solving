#include <bits/stdc++.h>
using namespace std;

int mod = 10;

long long mult(long long a, int b)
{
    return (a % mod * b % mod) % mod;
}

int fastPower(int b, int p)
{
    if (p == 0)
        return 1;

    int hp = fastPower(b, p / 2);

    int ans = mult(hp, hp);
    if (p % 2 == 1)
        ans = mult(ans, b);

    return ans;
}

// a^(mod-1) = 1 % mod

// a^(mod-2) = a^(-1) inv
int inv(int a)
{
    return fastPower(a, mod - 2);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << fastPower(a, b) % 10 << endl;
    }
    return 0;
}
