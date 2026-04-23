#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int arr1[n1], arr2[n2];
    for (int i = 0; i < n1; i++)
        arr1[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        arr2[i] = arr[mid + 1 + i];

    int idx1 = 0, idx2 = 0;
    int n = l;
    while (idx1 < n1 && idx2 < n2)
    {
        if (arr1[idx1] <= arr2[idx2])
        {
            arr[n] = arr1[idx1];
            idx1++;
        }
        else
        {
            arr[n] = arr2[idx2];
            idx2++;
        }
        n++;
    }

    while (idx1 < n1)
    {
        arr[n] = arr1[idx1];
        idx1++;
        n++;
    }

    while (idx2 < n2)
    {
        arr[n] = arr2[idx2];
        idx2++;
        n++;
    }
}

// Merge Sort using recursion
void mergeSort(int *arr, int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main()
{
    int arr[] = {6, 3, 8, 1, 4, 7, 2, 5};

    mergeSort(arr, 0, 7);

    for (auto i : arr)
    {
        cout << i << " ";
    }
}
