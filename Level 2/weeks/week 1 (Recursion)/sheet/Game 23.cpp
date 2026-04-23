#include <bits/stdc++.h>
using namespace std;

int func(int n, int m, int moves)
{
    if (n > m || (m % n != 0))
        return -1;
    if (n == m)
        return moves;

    return max(func(n * 2, m, moves + 1), func(n * 3, m, moves + 1));
}

int main()
{
    int n, m;
    cin >> n >> m;

    cout << ((n == m) ? 0 : func(n, m, 0)) << endl;
}
