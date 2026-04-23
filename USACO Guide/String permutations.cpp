#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// String Permutations (n <= 8)
// O(n!) Solution

string s;
int letters[26] = {0};
vector<string> permutations;

void create_permutations(const string &current = "")
{
    if (current.size() == s.size()) 
    {
        permutations.push_back(current);
    }
    
    for(int i=0; i < 26; i++)
    {
        if (letters[i] > 0)
        {
            letters[i]--;
            create_permutations(current + char(i + 'a'));  
            // (Backtracking) --> start with an empty string and try all possibilities
            // After that function ends and add all possible permutations through this path
            // Reset the letters[] array for next paths
            letters[i]++;                                   
        }
    }
}

int main() 
{
    cin >> s;
    for(char c : s) letters[c - 'a']++;

    create_permutations();

    cout << permutations.size() << endl;
    for(string p : permutations) cout << p << endl;
}