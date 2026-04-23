#include <bits/stdc++.h>
using namespace std;

// The greedy solution 
// is to continually flip the longest possible ranges of mismatching cows.

int main() 
{
    int n; cin >> n;
    string a, b;
    cin >> a >> b;

    int counter = (a[0] != b[0]); // != --> 1 || == --> 0
    for(int i = 1; i < n; i++)
    {
        // update sunstrings counter at the start of a new substring 
        if(a[i] != b[i] && a[i-1] == b[i-1]) counter++; 
    }

    cout << counter << endl;
}