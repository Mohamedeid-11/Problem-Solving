#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<string> chats;
    stack<string> s;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string tmp; cin >> tmp;
        s.push(tmp);
    }
    while (!s.empty())
    {
        if (!chats.count(s.top()))
        {
            cout << s.top()<< "\n";
            chats.insert(s.top());
        }
        s.pop();
    }
}