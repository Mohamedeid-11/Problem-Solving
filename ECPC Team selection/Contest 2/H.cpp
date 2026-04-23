#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    int key[4] = {};
    int t; cin >> t;

    while(t--)
    {
        cin >> key[0] >> key[1] >> key[2] >> key[3];

        bool ans = true;

        int x = key[key[0]];
        int y = key[x];
        int z = key[y];

        if(!x || !y || z) ans = false;
        cout << (ans? "YES" : "NO") << '\n';
    }
}