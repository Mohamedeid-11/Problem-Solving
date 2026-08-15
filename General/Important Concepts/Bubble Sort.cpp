#include <bits/stdc++.h>
using namespace std;

void merge_sort(vector<int> &vec)
{
    // basecase
    if (vec.size() <= 1) return;

    // devide the vector
    vector<int> v1, v2;
    v1 = vector<int>(vec.begin(), vec.begin() + vec.size() / 2);
    v2 = vector<int>(vec.begin() + vec.size() / 2, vec.end());

    // sort each half
    merge_sort(v1);
    merge_sort(v2);

    // merge them (compare each element from both halves, and put the smallest first)
    vec.clear();
    size_t i = 0, j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] <= v2[j])
            vec.push_back(v1[i++]);
        else
            vec.push_back(v2[j++]);
    }
    // Push any remaining elements left over in v1 or v2
    while (i < v1.size()) vec.push_back(v1[i++]);
    while (j < v2.size()) vec.push_back(v2[j++]);
}

int main()
{
    vector<int> vec = {1, 3, 6, 2, 8, 2, 5, 9};
    merge_sort(vec);
    for (int i : vec) cout << i << ' ';
}