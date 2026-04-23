#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<vector<char>> board(8, vector<char>(8));

bool contradict(pair<int, int> q1, pair<int, int> q2)
{
    if(q1.first == q2.first || q1.second == q2.second) return true; // same row or column
    if(abs(q1.first - q2.first) == abs(q1.second - q2.second)) return true; // same diagonal
    return false;
}

void search(vector<pair<int, int>>& queens, int row) 
{
    if(queens.size() == 8) 
    {
        ans++;
        // if you want to print boards:
        // for(int i=0; i<8; i++)
        // {
        //     for(int j=0; j<8; j++)
        //     {
        //         cout << board[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        return;
    }

    // try to put a queen in each available cell in that (row)
    for(int j = 0; j < 8; j++)
    {
        if(board[row][j] == '.')
        {
            // if the new queen contradicts with any of the already placed queens, skip this position;
            bool contradiction = false;

            for(auto q : queens)
            {
                if(contradict(q, make_pair(row, j))) 
                {
                    contradiction = true;
                    break;
                }
            }

            if(!contradiction) 
            {
                board[row][j] = 'Q';
                queens.push_back(make_pair(row, j));

                search(queens, row + 1);

                queens.pop_back();
                board[row][j] = '.';
            }
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            cin >> board[i][j];
        }
    }

    vector<pair<int, int>> queens;
    search(queens, 0);
    
    cout << ans << endl;
}

