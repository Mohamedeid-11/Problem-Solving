#include <bits/stdc++.h>
using namespace std;

int n = 3; // Size of the set {0, 1, 2}
vector<int> subset;
void method1_search(int k = 0)  // first step: start the recursion from the first element (0) 
{
    if (k == n) 
    {
        // Process subset (e.g., print it)
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
    } 
    else 
    {
        // Choice 1: Exclude element k from the subset
        method1_search(k + 1);
        
        // Choice 2: Include element k in the subset
        subset.push_back(k);
        method1_search(k + 1);
        
        // Backtrack: Remove k to restore state for previous choices
        subset.pop_back();
    }
}

void method2_bits()
{
    // b < 1000  || b <= 111 
    for (int b = 0; b < (1 << n); b++)
    {
        vector<int> subset;
        for (int i = 0; i < n; i++)
        {
            // checks whether the i-th bit of the integer b is set to 1.
            if (b & (1 << i)) subset.push_back(i);
        }
        cout << "{ ";
        for (int x : subset) cout << x << " ";
        cout << "}\n";
    }
}

int main() 
{
    method1_search();
    cout << endl;
    method2_bits();
}