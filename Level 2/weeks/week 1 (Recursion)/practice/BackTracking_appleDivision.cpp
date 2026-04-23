#include <bits/stdc++.h>
using namespace std;

int v[25];
int N;
long long min_diff = 1e15;
vector<int> ans, path;
void func(int i, long long g1, long long g2)
{
    if (i == N)
    {
        if (min_diff > abs(g1 - g2))
        {
            min_diff = abs(g1 - g2);
            ans = path;
        }
        return;
    }

    path.push_back(1);
    func(i + 1, g1 + v[i], g2);
    path.pop_back();

    path.push_back(2);
    func(i + 1, g1, g2 + v[i]);
    path.pop_back();
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> v[i];

    func(0, 0, 0);

    cout << "\nans: " << min_diff << endl;

    for (auto val : ans)
        cout << 'g' << val << ' ';
}

/*
5
3 2 7 4 1
*/
