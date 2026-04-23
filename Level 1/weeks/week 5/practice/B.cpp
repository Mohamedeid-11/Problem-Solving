#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> table;
    int n; cin >> n;
    string team; char state;
    
    while(n--)
    {
        cin >> team >> state;
        switch (state) 
        {
            case 'W':
                table[team] += 3;
                break;
            case 'D':
                table[team] += 1;
                break;
            case 'L':
                table[team] += 0;
                break;
        }
    }

    cout << table.size() << endl;
    for (auto team : table)
    {
        cout << team.first << ' ' << team.second << '\n';
    }
}