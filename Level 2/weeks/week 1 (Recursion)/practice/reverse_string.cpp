#include <bits/stdc++.h>
using namespace std;

string strRev(string s)
{
    if (s.size() == 0)
        return "";

    return strRev(s.substr(1)) + s[0];
}

int main()
{
    string s = "Hello";
    cout << strRev(s);
}
