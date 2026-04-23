#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int start = 1;
    int end = N;
    int ans;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if ((mid * mid) <= N)
        {
            start = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    cout << ans;
    return 0;
}