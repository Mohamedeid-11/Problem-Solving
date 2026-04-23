#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t; cin >> t;
    while (t--)
    {
        cin >> n;
        char q1[n] ,q2[n];
        for (int i = 0; i < n; i++) 
        {
            cin >> q1[i];
            if(q1[i] == 'B') q1[i] = 'G';
        }
        for (int i = 0; i < n; i++) 
        {
            cin >> q2[i];
            if(q2[i] == 'B') q2[i] = 'G';
        }
        
        bool identical = true;
        for (int i = 0; i < n; i++)
        {
            if (q1[i] != q2[i]) 
            {
                identical = false;
                break;
            }
        }

        if(identical) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}