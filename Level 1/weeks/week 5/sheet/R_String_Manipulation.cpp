#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, final_s;
    int k, n;
    cin >> k >> s >> n;

    final_s.reserve(k * s.length());  // reserve memory for the final string to avoid multiple reallocations
    for (int i=0; i<k; i++) final_s += s;

    // map to store the positions of each character in the string
    map<char, deque<int>> char_pos;  // deque is more efficient than vector for erasing elements
    for(int i=0; i < final_s.length(); i++) char_pos[final_s[i]].push_back(i);
    
    for (int i = 0; i < n; i++)
    {
        int p; char c;
        cin >> p >> c;

        final_s[char_pos[c][p - 1]] = '0';

        char_pos[c].erase(char_pos[c].begin() + p - 1);
    }

    for (char c : final_s) 
    {
        if (c != '0') cout << c;
    }
}