#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t, n, x;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        vector<int> arr(n+1), prefix_sum(n+1);
        for(int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            prefix_sum[i] = prefix_sum[i-1] + arr[i];
        } 

        // get maximum consecutive subarray of length (1 <= len <= n)
        vector<int> max_sub(n+1, -1e9); // any -1e9 so that any subarray can beat it
         max_sub[0] = 0;
        for(int len = 1; len <= n; len++)
        {
            for(int i = 1; (i+len-1) <= n; i++)
            {
                int cur_sub = prefix_sum[i+len-1] - prefix_sum[i-1];
                max_sub[len] = max(max_sub[len], cur_sub);
            } 
        }
        
        // for each k --> check each max_sum[len] with the new (x * min(len, k)) --> as k got updated
        for(int k = 0; k <= n; k++)
        {
            int ans = 0;
            for(int len = 0; len <= n; len++)
            {
                ans = max(ans, max_sub[len] + x*min(len, k));
            } 
            cout << ans << ' ';
        } 
        cout << '\n';
    }
}
