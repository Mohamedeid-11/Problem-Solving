#include <bits/stdc++.h>
using namespace std;

// Merge Sort
// O(n*log(n)) time complexity
void sort(vector<int>& arr, int left, int right)
{
    if(left >= right) return;

    int mid = left + (right - left) / 2, half1_right = mid, half2_left = mid + 1; 
    sort(arr, left, half1_right);
    sort(arr, half2_left, right);

    // now merge the two sorted halves
    vector<int> temp(right - left + 1);
    int i = left, j = half2_left, k = 0; // i, j points to the smallest of each half

    while(i <= half1_right && j <= right)
    {
        if(arr[i] < arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while(i <= half1_right) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];

    for(int i = left; i <= right; i++)
    {
        arr[i] = temp[i - left];
    }
}

int main() 
{
    vector<int> nums = {6, 5, 3, 1, 8, 7, 2, 4};
    sort(nums, 0, nums.size() - 1);

    for(int n : nums) cout << n << " ";
}