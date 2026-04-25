#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n; cin >> n;
    vector<pair<int,int>> segments(n);
    for (auto& [l, r] : segments) 
    {
        cin >> l >> r;
        if (l > r) swap(l, r);
    }

    sort(segments.begin(), segments.end(), [](auto& a, auto& b) {
        return a.second < b.second;
    });

    vector<int> nails;
    int i = 0;
    while (i < n) 
    {
        int nail = segments[i].second;
        nails.push_back(nail);
        while (i < n && segments[i].first <= nail && nail <= segments[i].second) i++;
    }
    reverse(nails.begin(), nails.end());

    cout << nails.size() << "\n";
    for (int nail : nails) cout << nail << " ";
}