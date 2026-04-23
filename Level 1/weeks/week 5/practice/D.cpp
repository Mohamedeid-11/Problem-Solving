#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;

    string word;
    for(int i = 0; i < n; i++)
    {
        cin >> word;
        int lc = 0, uc = 0; 
        for(char c : word)
        {
            if(islower(c)) lc++;
            else uc++;
        }
        
        if(lc <= uc) cout << lc << '\n';
        else cout << uc << '\n';
    }
}