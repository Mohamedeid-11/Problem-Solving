#include <bits/stdc++.h>
using namespace std;

// get the smallest prime factor of a number (spf)

// reduce N
const int N = 1e6 + 7;
short spf[N];

void seive()
{
    spf[1] = 1;

    for (int i = 2; i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < N; j += i) // to iterate the multiples
            {
                if (spf[j] == 0)
                    spf[j] = i;

                if (i < spf[j])
                    spf[j] = i;
            }
        }
    }
}

void neverLand()
{
    seive();

    for (int i = 1; i < 20; i++)
    {
        while (i > 1)
        {
            int p = spf[i];
            if (p == 0)
                p = i;
        }
        cout << i << ": " << spf[i] << endl;
    }
}

int main()
{
    neverLand();
    return 0;
}