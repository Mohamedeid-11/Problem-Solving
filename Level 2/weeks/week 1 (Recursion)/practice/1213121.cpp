#include <bits/stdc++.h>
using namespace std;

string s(int n)
{
    if (n == 1)
        return "1";
    return s(n - 1) + ' ' + to_string(n) + ' ' + s(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << s(n);
}
