#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    int n, m = 101;
    cin >> n;
    int arr[n];
    for(int i=0; i < n; i++) 
    {
        cin >> arr[i];
        m = min(m, arr[i]);
    }
    sort(arr, arr+n);
    auto ans = upper_bound(arr, arr+n, m);
    if (ans-arr != n) cout << *ans;
    else cout << "NO";   
}