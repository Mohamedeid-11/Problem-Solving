#include <bits/stdc++.h>
using namespace std;

bool isPalin(string s)
{
    if (s.size() == 0 || s.size() == 1)
        return true;

    if (s[0] == s[s.size() - 1])
        return isPalin(s.substr(1, s.size() - 2));

    return false;
}

int main()
{
    string s = "racecar";
    cout << '"' << s << "\" is " << (isPalin(s) ? "a " : "not ") << "palindrome!" << endl;
}
