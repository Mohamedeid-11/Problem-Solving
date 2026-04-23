#include <bits/stdc++.h>
using namespace std;

// number in the nth rank in fibonachi series
int fibonachi(int n)
{
    if (n == 0 || n == 1)
        return n;

    return fibonachi(n - 1) + fibonachi(n - 2);
}

// fibonachi series obtimizd by DP (Dynamyc Programming)
vector<int> fibonachi_series(1000, -1);
int fibonachi_obtimized(int n)
{
    if (n == 0 || n == 1)
        return n;

    if (fibonachi_series[n] == -1)
        fibonachi_series[n] = fibonachi_obtimized(n - 1) + fibonachi_obtimized(n - 2);

    return fibonachi_series[n];
}

int main()
{
    cout << fibonachi(6) << endl;
    cout << fibonachi_obtimized(6) << endl;
}
