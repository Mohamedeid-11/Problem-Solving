#include <bits/stdc++.h>
using namespace std;

int v[25], w[25];
int N, cap;
int func(int i, int val, int weight)
{
    if (weight < 0)
        return -1e9;
    if (i == N)
        return val;
    return max(func(i + 1, val + v[i], weight - w[i]), func(i + 1, val, weight));
}

int main()
{
    cin >> N >> cap;
    for (int i = 0; i < N; i++)
        cin >> w[i] >> v[i];

    cout << func(0, 0, cap) << endl;
}
