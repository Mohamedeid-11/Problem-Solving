#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m; cin >> n >> m;

    pair<int, int> a; // initial value, current value
    queue<pair<int, int>> q;
    for(int i = 1; i <= n; i++)
    {
        a.first = i; cin >> a.second; 
        q.push(a);
    }

    while(!q.empty())
    {
        auto front = q.front();
        q.pop();
        if(front.second > m) // will the kid enter the queue again?
        {
            front.second -= m;
            q.push(front); 
        }

        if(q.empty()) cout << front.first;
    }
}