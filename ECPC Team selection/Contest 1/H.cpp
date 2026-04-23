#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int LIMIT = 1e7+1;
int sum[LIMIT], ans[LIMIT];

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    // sieve to compute sum of n factors for all n
    // i=1: add 1 to sum[1], sum[2], sum[3], sum[4], sum[5], sum[6] ...
    // i=2: add 2 to        sum[2],       sum[4],       sum[6] ...
    // i=3: add 3 to               sum[3],       sum[6] ...
    // i=4: add 4 to                     sum[4] ...
    for (int n = 1; n <= LIMIT; n++) // for each number
    {   
        for (int u = n; u <= LIMIT; u += n) // add it to its multibles
        {
            sum[u] += n;
        }
    }

    // construct a map that connect each sum with its number    m[sum] = number
    for(int n = LIMIT; n >= 1; n--) 
    {
        if(sum[n] < LIMIT) ans[sum[n]] = n;
    }

    int t, c;
    cin >> t;
    while(t--)
    {
        cin >> c;
        cout << (ans[c]!=0? ans[c] : -1) << '\n';
    }
}