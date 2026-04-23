#include <bits/stdc++.h>
using namespace std;

int v[25];
int N;
long long func(int i, long long g1, long long g2)
{
    if (i == N)
        return abs(g1 - g2);

    return min(func(i + 1, g1 + v[i], g2), func(i + 1, g1, g2 + v[i]));
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> v[i];
    cout << func(0, 0, 0) << endl;
}
/*
5
3 2 7 4 1
*/