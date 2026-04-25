#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() 
{
    string s; cin >> s;

    map<char, int> cons; // consecutive (v, o) counter
    map<char, vector<int>> ch; // consecutive (w, o) arrays

    // get starting and ending points ( --> vv....vv <-- )
    int size = (int)s.size();
    int first_v = size, last_v = size; 
    for(int i = 0; i < size; i++)
    {
        if(s[i] == 'v')
        {
            cons['v']++;
            if(first_v == size && cons['v'] == 2) first_v = i-1;
            else if(first_v != size && cons['v'] >= 2) last_v = i;
        }
        else cons['v'] = 0;
    }
    cons['v'] = 0;
    
    // count consecutive 'w' and 'o'
    for(int i = first_v; i <= last_v; i++)
    {
        cons[s[i]]++;
        
        // if there's a change or we reached the end of the string
        // reset the consecutive counter
        if((i && s[i] != s[i-1]) || (i == last_v)) 
        {
            if(i+1 < size && s.substr(i-1, 3) == "ovo") continue;
            
            if(s[i-1] == 'v') cons[s[i-1]]--; // num of 'w'
            if(cons[s[i-1]]) ch[s[i-1]].push_back(cons[s[i-1]]); // push to the array

            cons[s[i-1]] = 0;
        }
    }

    if(first_v == size || last_v == size || !ch['o'].size())
    {
        cout << 0;
        return 0;
    }

    // build prefix sum array for w 
    vector<int> w_presum; w_presum.push_back(ch['v'][0]);
    for(int i = 1; i < (int)ch['v'].size(); i++) w_presum.push_back(w_presum.back() + ch['v'][i]);

    // ans
    ll ans = 0;
    int w_size = (int)ch['v'].size() - 1;
    for(int i = 0; i < w_size; i++)
    {
        // left w count * right w count * intermidate o count
        ans += (1LL * w_presum[i] * (w_presum[w_size] - w_presum[i]) * ch['o'][i]);
    }

    cout << ans;
}