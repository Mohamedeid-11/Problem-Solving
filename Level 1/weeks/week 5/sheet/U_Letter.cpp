#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char, int> chars;
    string s1, s2; 
    getline(cin, s1);
    getline(cin, s2);

    for(char c: s1) chars[c]++;

    for(char c: s2)
    {
        if(iswspace(c)) continue;
        else if(chars[c] == 0)
        {
            cout << "NO";
            return 0;
        }
        else chars[c]--;
    }
    cout << "YES";
}