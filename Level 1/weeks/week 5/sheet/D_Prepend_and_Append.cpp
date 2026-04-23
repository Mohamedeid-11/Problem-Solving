#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int arr[n];
        string s; cin >> s;
        for(int i = 0; i < n; i++) arr[i] = s[i] - '0';

        int starting_size = n;

        for(int l=0, r=n-1; l < r; l++, r--)
        {
            // (0 ... 1)   or (1 ... 0)
            if(arr[l]+arr[r] == 1) starting_size -= 2;
            else break;
        }

        cout << starting_size << endl;
    }
}