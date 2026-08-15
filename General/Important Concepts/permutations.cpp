#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    vector<int> permutation;
    for (int i = 0; i < n; i++)
    {
        permutation.push_back(i);
    }

    do
    {
        for (int i : permutation)
            cout << i << " ";
        cout << '\n';
    } 
    while (next_permutation(permutation.begin(), permutation.end()));
}