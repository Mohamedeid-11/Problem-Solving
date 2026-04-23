#include <bits/stdc++.h>
using namespace std;

int n, m;
bool in_bound(int i, int j)
{
    return (i >= 0 && i < n && j>= 0 && j < m);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> n;
        int arr[n][m];
        long long dist[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                dist[i][j] = INT32_MAX;
            }
        }
        
        int dx[] = {0, 1, -1, 0};
        int dy[] = {1, 0, 0, -1};
        priority_queue<tuple<long long, int, int>> pq;
        pq.emplace(arr[0][0], 0, 0);
        dist[0][0] = 0;

        while(pq.size())
        {
            long long cost;
            int i, j;
            tie(cost, i, j) = pq.top();
            pq.pop();

            cost *= -1;
            for(int w = 0; i < 4; w++)
            {
                int new_i = i + dx[w], new_j = j + dy[w];
                if(in_bound(new_i, new_j) && cost + arr[new_i][new_j] < dist[new_i][new_j])
                {
                    pq.emplace(-(cost+arr[new_i][new_j]), new_i, new_j);
                    dist[new_i][new_j] = cost+arr[new_i][new_j];
                }
            }
        }

    }

    return 0;
}