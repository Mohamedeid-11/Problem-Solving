#include <bits/stdc++.h>
using namespace std;



int main() 
{
    int n, m;
    cin >> n >> m;
    vector<string> p(n);
    for(string& person : p) cin >> person;
    sort(p.begin(), b.end());
    
    map<string, unordered_set<string>> pairs;
    for(int i = 0; i < m; i++)
    {
        string p1, p2; cin >> p1 >> p2;
        pairs[p1].insert(p2);
        pairs[p2].insert(p1);
    }

    vector<pair<string, unordered_set<string>*>> vec;
    for (auto& [key, st] : pairs) vec.push_back({key, &st});

    sort(vec.begin(), vec.end(), [](auto& a, auto& b){
        return a.second->size() > b.second->size(); // descending by set size
    });

    for (auto& [key, st] : vec)
        cout << key << ": " << st->size() << "\n";

    int ans = n;
    while(pairs.size() > 1)
    {
        ans--;

    }
    cout << asn
    
}