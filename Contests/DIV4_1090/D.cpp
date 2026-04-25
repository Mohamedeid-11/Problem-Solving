#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ull limit = 150000;
    vector<int> primes;
    vector<bool> is_prime(limit+1, true);
    is_prime[0] = is_prime[1] = false;
    for (ull i = 2; i <= limit; i++)
    {
        if (is_prime[i]) 
        {
            primes.push_back(i);
            for (ull j = i*i; j <= limit; j += i) 
                is_prime[j] = false;
        }
    }

    int t, n; cin >> t;
    while(t--)
    {
        cin >> n;
        cout << primes[0] << ' ';
        for(int i = 1; i < n; i++)
        {
            cout << 1ULL * primes[i-1] * primes[i] << ' ';
        }
        cout << '\n';
    }
}