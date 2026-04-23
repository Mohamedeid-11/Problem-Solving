#include <bits/stdc++.h>
using namespace std;

int N, arr[10];

// all possible solutions and the current one
vector<vector<int>> v;
vector<int> currentSolution;

/*
    Major Diagonals (Bottom-Left to Top-Right):
These diagonals have the property that the difference between the row and column indices is constant.
For a cell at position (r, c), the major diagonal can be represented as r - c.

    Minor Diagonals (Top-Left to Bottom-Right):
These diagonals have the property that the sum of the row and column indices is constant.
For a cell at position (r, c), the minor diagonal can be represented as r + c.
*/

// row, major(negative) diagonal, and minor diagonal
bool row[10], d1[20], d2[20];

void solve(int col)
{

    // if we reached the last column, then we have the solution
    if (col == N)
    {
        v.push_back(currentSolution);
        return;
    }

    // try to place a queen in each row
    for (int r = 0; r < N; r++)
    {
        // check if the row or diagonals are already occupied
        if (row[r] || d1[r + col] || d2[r - col + N])
            continue;

        // place the queen and mark the row and diagonals as occupied
        row[r] = 1;
        d1[r + col] = 1;
        d2[r - col + N] = 1;
        currentSolution.push_back(r + 1);
        solve(col + 1);
        // backtrack by tring the the other possibilty (not placing the queen)
        currentSolution.pop_back();
        row[r] = 0;
        d1[r + col] = 0;
        d2[r - col + N] = 0;
    }
}

int main()
{
    N = 8;
    solve(0);
    for (int i = 1; cin >> arr[0]; i++)
    {
        // take the rest of the input
        for (int j = 1; j < 8; j++)
            cin >> arr[j];

        // for each solution in v, check how many moves were required and take the minimum
        int ans = 1e9;
        for (auto sol : v)
        {
            int moves = 0;
            for (int j = 0; j < 8; j++)
            {
                if (sol[j] != arr[j])
                    moves++;
            }
            ans = min(ans, moves);
        }
        // cout the minimum num of moves
        cout << "Case " << i << ": " << ans << '\n';
    }
}
