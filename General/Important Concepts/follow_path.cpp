#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[501][501];
void search(int y, int x, int parent_y, int parent_x, int grand_y, int grand_x)
{
    if (x < 1 || x > m || y < 1 || y > n || (y == grand_y && x == grand_x) || grid[y][x] == '.')
    {
        return;
    }

    cout << y << ' ' << x << '\n';

    if (grid[y][x] == 'O') return;

    search(y + 1, x, y, x, parent_y, parent_x);
    search(y - 1, x, y, x, parent_y, parent_x);
    search(y, x + 1, y, x, parent_y, parent_x);
    search(y, x - 1, y, x, parent_y, parent_x);
}

int main()
{
    cin >> n >> m;
    
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
            {
                y = i;
                x = j;
            }
        }
    }
    
    search(y, x, -1, -1, -1, -1);
}
/* 
week 3 sheet
G_Heimerdinger and The Treasure.cpp
https://codeforces.com/group/g3REqA871s/contest/570641/problem/G


input:
10 10
..........
..........
.S****....
.....*....
***..*....
*.****....
*.........
*......O..
********..
..........

S --> start
* --> step
O --> finish

output : print the coordinates of each step
*/