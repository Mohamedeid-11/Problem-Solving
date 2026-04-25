#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    int t, n, l, r;
    cin >> t;
    while(t--)
    {
        cin >> n >> l >> r;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];
        
        /*  Sorting won't miss anything as pairs will encounter but in different order.
            just make sure to search for elements after the current (i) element

            if  (l = 4, r = 7), and arr = [5, 1, 2]
            i=0 (value 5), search right → finds 1 (sum 6 ✓) and 2 (sum 7 ✓)
            i=1 (value 1), search right → finds 2 (sum 3, no)
            i=2 (value 2), nothing to the right

            After sorting: [1, 2, 5]: 
            i=0 (value 1), search right → finds 2 (sum 3, no) and 5 (sum 6 ✓)
            i=1 (value 2), search right → finds 5 (sum 7 ✓)
            i=2 (value 5), nothing to the right
        */
        sort(arr, arr+n);

        long long ans = 0;
        for(int i = 0; i < n; i++)
        {
            int* left = lower_bound(arr+i+1, arr+n, l-arr[i]);
            int* right = upper_bound(arr+i+1, arr+n, r-arr[i]);
            ans += (right - left);
        }

        cout << ans << '\n';
    }
}

