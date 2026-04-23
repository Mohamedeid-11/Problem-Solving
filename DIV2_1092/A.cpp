#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t, n; cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> arr(n), freq(101, 0);

        bool no_sol = false; 
        for(int& a : arr) 
        {
            cin >> a;
            freq[a]++;
            if(freq[a] >= 2) no_sol = true;
        }

        if(no_sol) cout << "-1\n";
        else
        {
            sort(arr.begin(), arr.end(), greater<int>());
            for(int& a : arr) cout << a << ' ';
            cout << '\n';
        }
    }
}
