#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> box;
    int n, act, id;
    cin >> n;
    while (n--)
    {
        cin >> act;
        switch (act)
        {
            case 1:
                cin >> id;
                box.push(id);
                break;
            case 2:
                if(!box.empty()) box.pop();
                break;
            case 3:
                if(!box.empty()) cout << box.top() << '\n';
                break;
        }
    }
}