#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b; cin >> n;
    queue<int> q;
    while(n--)
    {
        cin >> a >> b;
        if(a == 1) q.push(b);
        else 
        {
            int front = q.front();
            q.pop();
            cout << ( (front == b)? "Yes" : "No" ) << endl;
        }
    }
}