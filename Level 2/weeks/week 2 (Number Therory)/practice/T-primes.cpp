#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
vector<bool> isPrime(N, true);

void seive()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < N; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < N; j += i)
                isPrime[j] = false;
        }
    }
}

bool isTPrime(long long x)
{
    long long root = sqrt(x);
    return root * root == x && isPrime[root];
}

int main()
{
    seive();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        if (isTPrime(a))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}