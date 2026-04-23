#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    int q; cin >> q;
    while(q--)
    {
        int op; cin >> op;
        if(op == 1 || op == 2)
        {
            int i; cin >> i; 
            i--;

            if (op==1) s[i] = toupper(s[i]);
            else s[i] = tolower(s[i]);
        }
        else
        {
            int l, r; cin >> l >> r;
            l--, r--;

            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
        }
    }
    cout << s << endl;
}