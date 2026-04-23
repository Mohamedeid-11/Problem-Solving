#include <bits/stdc++.h>
using namespace std;

// sort the array
// try each pair as the 2 singles (remove them from the array)
// get total sum of differences between each consecutive pair --> abs(arr[i+1] - arr[i])
// choose min_total_diffs

typedef long long ll;

int n; 
vector<int> arr;

// get total without removing and readding the nodes (i, j) to the array or constructing a new one
ll get_total_diffs(const vector<int>& arr, int i, int j) // i, j are the 2 using the single kayaks
{
    ll total = 0;
    int k = 0;
    while(k < n-1) 
    {
        if(k != i && k != j) 
        {
            int x = 1;
            while((k+x == i || k+x == j) && (k+x < n)) x++;
            total += abs(arr[k] - arr[k+x]);
            k += (x + 1);
        }
        else k++;
    }
    return total;
}


int main() 
{
    cin >> n;
    n *= 2;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    
    ll total = 1e18;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            total = min(total, get_total_diffs(arr, i, j));
        }
    }
    
    cout << total << endl;
}

// 3
// (139) 205 206 305 406 (530)
