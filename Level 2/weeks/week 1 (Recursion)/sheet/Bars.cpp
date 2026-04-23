#include <iostream>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;

int bars[20];
int bars_num;

bool func(int idx, int target)
{

    if (target == 0)
        return true;

    // if we passed the target or we reached the last idx but we still couldn't acheive the target
    if ((target < 0) || (idx >= bars_num))
        return false;

    return (func(idx + 1, target - bars[idx]) || func(idx + 1, target));
}

int main()
{
    int t, target;
    cin >> t;
    while (t--)
    {
        cin >> target >> bars_num;
        for (int i = 0; i < bars_num; i++)
            cin >> bars[i];

        cout << (func(0, target) ? "YES" : "NO") << endl;
    }
}
