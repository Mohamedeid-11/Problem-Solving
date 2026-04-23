#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int pre_evens = 0, post_evens = 0, longest_arr = 0;
    bool odd_found = false;

    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
        if(arr[i] % 2 == 0) post_evens++;
        else 
        {
            odd_found = true;
            longest_arr = max(longest_arr, pre_evens + post_evens);
            pre_evens = post_evens;
            post_evens = 0;
        }
    }

    if(odd_found) 
    {
        longest_arr = max(longest_arr, pre_evens + post_evens);
        cout << (longest_arr + 1) << '\n';
    }
    else cout << -1 << '\n';
}