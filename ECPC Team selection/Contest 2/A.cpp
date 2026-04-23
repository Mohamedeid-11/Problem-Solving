#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull pairs(vector<ull>& lines)
{
    sort(lines.begin(), lines.end());

    ull ans = 0, cur = 0, j;
    while (cur < lines.size())
    {
        j = cur; 

        // check if that line occurs again (one more point lies on that line)
        while (j < lines.size() && lines[j] == lines[cur])
            j++; 

        // number of points on line: lines[cur]
        ull k = j - cur; 

        // each point will make a pair with all points after it
        // number of pairs = points*(points - 1)/2  --> but don't divide as we want double oairs --> because swapping points gives a new pair
        ans += k * (k - 1); 

        // update to go to a new key
        cur = j;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n, x, y;
    cin >> t;
    while (t--)
    {
        cin >> n;

        // points are valid if they lie on the same horizontal, vertical, diagonal, or anti-diagonal line.
        // same x means same vertical line
        // same y means same horizontal line, and so on...
        vector<int> ver(n), hor(n), diag(n), anti(n);

        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            ver[i] = x; // store all vertical lines in ver[]
            hor[i] = y;
            diag[i] = x - y;
            anti[i] = x + y;
        }

        ull ans = pairs(ver) + pairs(hor) + pairs(diag) + pairs(anti);

        cout << ans << '\n';
    }
}

// Summery: get all vertical, horizontal, ... lines that the points lie on, and the solution depends on the lines with multiple points on them