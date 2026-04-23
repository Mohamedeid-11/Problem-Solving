#include <bits/stdc++.h>
using namespace std;

// get the smallest prive factor of a number (spf)

const int N = 1e6 + 7;
vector<int> spf(N);

void seive()
{
    for (int i = 1; i < N; i++)
        spf[i] = i;

    for (int i = 2; i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < N; j += i) // to iterate the multiples
                spf[j] = min(spf[j], i);
        }
    }
}

void neverLand()
{
    seive();
    for (int i = 1; i < 20; i++)
        cout << i << ": " << spf[i] << endl;
}

int main()
{
    neverLand();

    return 0;
}