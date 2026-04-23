#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
short spf[N];
void SPF()
{
    for (int i = 1; i < N; i++)
        spf[i] = i;

    for (int i = 2; i * i < N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < N; j += i) // to iterate the multiples
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

vector<int> getID(int x)
{
    vector<int> id;
    while (x > 1)
    {
        int p = spf[x];
        if (p == 0)
            p = x;

        int ct = 0;
        while (x % p == 0)
            x /= p, ct++;

        // if odd add it (ignore EVENs )
        if (ct % 2 != 0)
            id.push_back(p);
    }
    return id;
}

int main()
{
    SPF();
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int ct = 1;
        set<vector<int>> vis;
        while (n--)
        {
            int x;
            cin >> x;
            vector<int> id = getID(x);

            // clear vis to operate on the new segment
            if (vis.count(id))
            {
                ct++;
                vis.clear();
            }
            vis.insert(id);
        }
        cout << ct << endl;
    }

    return 0;
}
