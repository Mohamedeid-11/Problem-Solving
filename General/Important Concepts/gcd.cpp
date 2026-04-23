
#include <iostream>
using namespace std;
// GCD

int const N = 1e5 + 5;
int power[N];
int powerA[N], powerB[N];

int main()
{
    int a, b;
    cin >> a >> b;

    for (int i = 2; (i * i) <= a; i++)
    {
        while (a % i == 0)
        {
            a /= i;
            powerA[i]++;
        }
    }
    if (a > 1)
        powerA[a]++;

    for (int i = 2; (i * i) <= b; i++)
    {
        while (b % i == 0)
        {
            b /= i;
            powerB[i]++;
        }
    }
    if (b > 1)
        powerB[b]++;

    int ans = 1;
    for (int i = 2; i <= N; i++)
    {
        // to get the (lcm) use max
        power[i] = min(powerA[i], powerB[i]);
        while (power[i]--)
        {
            ans *= i;
        }
    }

    cout << ans;

    return 0;
}
