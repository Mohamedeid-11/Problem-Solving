#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

/*

*/

// RULES
// 1. Avoid (Overflow) --> long long, double
// 2. Avoid (Flooting points) as possible
// 3. check (x-y) < 1e-9 for floats equality
// 4. Don't you EVER skip (test cases)

// 5. Check time limit:
//    n ≤ 10           O(n!)
//    n ≤ 20           O(2^n)
//    n ≤ 500          O(n^3)
//    n ≤ 5000         O(n^2)
//    n ≤ 10^6         O(n*Log(n))
//    n ≤ 10^8         O(n)
//    n ≤ 10^18        O(Log(n)), O(1)

// 6. To solve a problem you have to:
//   1. Design the soluion.
//   2. Implement it.
/*  So make sure to identify the (Core problem type):
//                          [ Analyze Constraint N ]
//                                      |
//          +---------------------------+---------------------------+
//          |                                                       |
//    (N is small: N ≤ 20)                                (N is large: N ≥ 10^5)
//          |                                                       |
//  [Bitmask / Permutations]                                        |
//        O(2^N) or O(N!)                                           |
//                                                [ Does Sorting or Guessing help? ]
//                                                                  |
//                                         +------------------------+------------------------+
//                                         |                                                 |
//                                       (Yes)                                              (No)
//                                         |                                                 |
//                        [Is it monotonic when guessing?]                          [Check Structure]
//                                         |                                                 |
//                           +-------------+-------------+                  +----------------+----------------+
//                           |                           |                  |                                 |
//                         (Yes)                        (No)         [Graph/Network?]                 [Math/Constructive?]
//                           |                           |                  |                                 |
//                   [Binary Search]                  [Greedy]        [BFS/DFS/Dijkstra]                [Math / O(1) / O(N)]
//                  O(N log(Answer))                 O(N log N)       O(V + E log V)
*/
