#include <bits/stdc++.h>
using namespace std;

// In one shot it can can destroy all the stormtroopers, situated on some line that crosses point (x0, y0).
// avoid storing dy/dx directly as it can cause precision issues,
// instead store the pair directly after reducing it by their gcd. 

int main ()
{
    int lines = 0;
    set<pair<int, int>> slopes;
    int n, x0, y0;
    cin >> n >> x0 >> y0;

    while(n--)
    {
        int x, y; cin >> x >> y;

        int dx = x - x0, dy = y - y0;
        int gcd = __gcd(dx, dy);
        dx /= gcd; dy /= gcd;

        auto result = slopes.insert(pair(dy, dx));
        if(result.second) lines++;
    }
    cout << lines << "\n";
}