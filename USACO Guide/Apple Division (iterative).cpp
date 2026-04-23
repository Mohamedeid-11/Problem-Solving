#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// divide apples into two piles, with minimal weight difference

// if n = 5 we will have 2^5 = 32 subsets, try all of them.
// we represent different sets with bitmasking, for example: 5 --> 00101 --> {0, 2} (the set of the 0th and 2nd apple)

int main() 
{
    ll min_diff = LONG_LONG_MAX;
    int n; cin >> n; // 5
    vector<int> apples(n);
    for(int i=0; i<n; i++) cin >> apples[i];

    for(int mask = 0; mask < (1 << n); mask++) // for each subset from the 2^n subsets
    {
        ll half1 = 0, half2 = 0;
        for(int i = 0; i < n; i++) 
        {
            if(mask & (1 << i)) half1 += apples[i];  // calc half1 from 1s
            else half2 += apples[i];                 // calc half2 from 0s         
        }       
        min_diff = min(min_diff, abs(half1 - half2));
    }

    cout << min_diff << endl;
}