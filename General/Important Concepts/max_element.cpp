#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    // int n, greatest = 1, index = 0;
    int n;
    cin >> n;
    int num[n];

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    cout << *max_element(num, num + n);

    return 0;
}
