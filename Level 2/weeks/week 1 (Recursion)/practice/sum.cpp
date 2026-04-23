#include <bits/stdc++.h>
using namespace std;

// sum from 1 to n
int sum(int n)
{
    if (n == 1)
        return n;

    return n + sum(n - 1);
}

int main()
{
    cout << sum(10);
}
