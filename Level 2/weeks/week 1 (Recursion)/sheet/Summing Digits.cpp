#include <bits/stdc++.h>
using namespace std;

int func(int n)
{
    if (n % 10 == n)
        return n;
    return n % 10 + func(n / 10);
}

int main()
{
    int n;
    cin >> n;
    while (n != 0)
    {
        while (n % 10 != n)
            n = func(n);
        cout << n << endl;

        cin >> n;
    }
}