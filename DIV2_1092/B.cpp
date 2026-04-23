#include <bits/stdc++.h>
using namespace std;

int n, m;
map<pair<int, int>, bool> states;
bool solve(vector<int>& arr, int second, int pos)
{
    if (pos > n) return true;    
    if (pos < 0) return false;
    if (pos > 0 && (arr[pos - 1]+second)%m == 0) return false;
    
    int sec_mod = second % m;
    pair<int, int> state = {sec_mod, pos};
    if (!states.count(state)) 
    {
        states[state] = false;
        states[state] = solve(arr, second + 1, pos + 1) || solve(arr, second + 1, pos) || solve(arr, second + 1, pos - 1);
    }

    return states[state];
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<int> arr(n);
        for (int& a : arr) cin >> a;
        
        states.clear();
        
        cout << (solve(arr, 0, 0) ? "YES" : "NO") << "\n";
    }
}