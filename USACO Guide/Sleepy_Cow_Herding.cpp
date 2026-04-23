#include <bits/stdc++.h>
using namespace std;

int main() 
{
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int n; 
    vector<int> v;
    for(int i=0; i<3; i++) 
    {
        cin >> n;
        v.push_back(n);
    }

    // left and right margins
    int l = (v[1]-v[0] - 1), r = (v[2]-v[1] - 1); 
    int min_margin = min(l, r), max_margin = max(l, r);
    
    // The minimum number of moves can only be 0, 1, or 2.
    int min_moves;
    if(min_margin == 0) 
        min_moves = min(max_margin, 2);
    else
        min_moves = min(min_margin, 2);
    
    cout << min_moves << '\n' << max_margin << endl; // max_moves = max_margin
}