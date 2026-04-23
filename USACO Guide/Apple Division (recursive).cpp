#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// divide apples into two piles, with minimal weight difference

int n; 
vector<int> apples(20);

// we have n nodes each one expands into another 2, so time compexity is O(2^n) --> (we try all possible subsets 2^n)
ll divide_apples(int index, ll half1, ll half2)
{
    if(index == n) return abs(half1 - half2);

    // the two paths of the recursion tree (add current apple to half1 or add to half2)
    ll path1, path2; 
    path1 = divide_apples(index + 1, half1 + apples[index], half2);
    path2 = divide_apples(index + 1, half1, half2 + apples[index]);

    // return the minimum path
    return min(path1, path2); 
}

int main() 
{
    cin >> n;
    for(int i=0; i<n; i++) cin >> apples[i];

    cout << divide_apples(0, 0, 0) << endl;
}