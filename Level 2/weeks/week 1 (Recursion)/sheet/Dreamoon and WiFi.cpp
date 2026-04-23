#include <bits/stdc++.h>
using namespace std;
// int acheived;
int func(int check, int target)
{
    if (check == 0)
    {
        if (target == 0)
            return 1;
        else
            return 0;
    }

    return (func(check - 1, target - 1) + func(check - 1, target + 1));
}

int main()
{
    cout << fixed << setprecision(10);
    string s1, s2;
    cin >> s1 >> s2;

    int fin_pos = 0;
    for (char c : s1)
    {
        if (c == '+')
            fin_pos++;
        else
            fin_pos--;
    }

    int cur_pos = 0, check = 0;
    for (char c : s2)
    {
        if (c == '+')
            cur_pos++;
        else if (c == '-')
            cur_pos--;
        else
            check++;
    }
    int target = fin_pos - cur_pos;

    if (!check)
    {
        if (!target)
            cout << 1;
        else
            cout << 0;

        return 0;
    }

    int acheived = func(check, target);
    double total_possible_combinations = pow(2, check);
    cout << acheived / total_possible_combinations << endl;
    return 0;
}
