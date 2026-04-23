#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main()
{
    int n, m; cin >> n >> m;
    priority_queue<ull, vector<ull>, greater<ull>> cubes;

    ull tmp;
    for (int i=0; i<n; i++)
    {
        cin >> tmp;
        cubes.push(tmp);
    }

    ull sum = 0;
    while(m--)
    {
        tmp = cubes.top();
        cubes.pop();
        sum += tmp;
        cubes.push(tmp*2);
    }

    cout << sum << endl;
}