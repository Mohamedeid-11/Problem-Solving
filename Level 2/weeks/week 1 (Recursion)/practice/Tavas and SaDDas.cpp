#include <bits/stdc++.h>
using namespace std;

int N;
int luckyIndex(int lucky = 0, int index = 0)
{
    // to take max between n and -1 at the end so we return n
    if (lucky > N)
        return -1;
    else if (lucky == N)
        return index;

    return max(
        luckyIndex(lucky * 10 + 4, index * 2 + 1),
        luckyIndex(lucky * 10 + 7, index * 2 + 2));
}
/*
By drawing the tree
            0 --> 4,7
4 --> 44, 47     , 7 --> 74, 77  ....and so on

We can notice:
lucky 44, index 3
will lead us to 444, 447   by applying (lucky * 10 + 4) to add the digit 4 and so on to add 7
then the index of each on of them can be calculated by (index * 2 + 2)

*/

int main()
{
    cin >> N;
    cout << luckyIndex();
}
