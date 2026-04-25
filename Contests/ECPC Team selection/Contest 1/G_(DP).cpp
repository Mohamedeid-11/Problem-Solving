#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s; cin >> s;
    
    long long w_count = 0, wo_count = 0, wow_count = 0;
    
    bool prev_was_v = false;
    for (char c : s) 
    {
        if (c == 'v') 
        {
            if (prev_was_v) // Formed a new "w"
            {
                wow_count += wo_count;  // Combine the 'w' with all "wo"s
                w_count++;
            }

            prev_was_v = true;
        } 
        else // c == 'o'
        {  
            wo_count += w_count;  // Combine the 'o' with all "w"s
            prev_was_v = false;
        }
    }
    
    cout << wow_count << endl;
    
    return 0;
}