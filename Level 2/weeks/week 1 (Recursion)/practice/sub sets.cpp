#include <bits/stdc++.h>
using namespace std;

void subSet(int idx, const vector<int> &list, vector<int> cur)
{
    if (idx == list.size())
    {
        for (auto &i : cur)
            cout << i << " ";
        cout << endl;
        return;
    }

    // choice: leave this element
    subSet(idx + 1, list, cur);

    // choice: take this element
    cur.push_back(list[idx]);
    subSet(idx + 1, list, cur);
    cur.pop_back();
}

int main()
{
    vector<int> list = {1, 2, 3};
    vector<int> cur;
    subSet(0, list, cur);
    return 0;
}