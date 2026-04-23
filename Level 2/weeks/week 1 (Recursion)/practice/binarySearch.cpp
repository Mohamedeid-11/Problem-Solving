#include <bits/stdc++.h>
using namespace std;

// Binary Serach using recursion
int binaySearch(int *arr, int l, int r, int x)
{
    // if we didn't find x after the search
    if (l > r)
        return -1;

    int mid = (l + r) / 2;

    if (arr[mid] == x)
        return mid;
    else if (arr[mid] < x)
        return binaySearch(arr, mid + 1, r, x);
    else
        return binaySearch(arr, l, mid - 1, x);
}

int main()
{
    int arr[] = {3, 11, 14, 22, 56, 70, 71, 100};
    cout << binaySearch(arr, 0, 7, 70) << endl;
}
