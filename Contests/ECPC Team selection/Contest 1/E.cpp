#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, a;
    cin >> n; n++;
    vector<int> arr(n);

    for(int i = 1; i < n; i++)
    {
        cin >> a;
        arr[i] = a;
    }

    for(int i = 1; i < n; i++)
    {
        int ans = -1;
        int moves = 1;
        int target_parity = (arr[i] % 2? 0 : 1);
        bool solved = false;
        while(!solved)
        {
            int big_jump = (i+arr[i]) * moves, small_jump = (i-arr[i]) * moves;

            if(big_jump >= n && small_jump < 0) break;
            else if((big_jump < n && arr[big_jump] % 2 == target_parity) || (small_jump > 0 && arr[small_jump] % 2 == target_parity)) 
            {
                solved = true;
                ans = moves;
            }
            else moves++;
        }
        cout << ans << ' ';
    }
}