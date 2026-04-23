#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void print_arr(vector<int>& arr)            // recieve vector by referenece (no copying)
{
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}
// call with print_arr(v);

void print_arr(int arr[], int size)         // (no copying), since arrays are passed as pointers (pointer to the first element)
{
    for(int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
// call with print_arr(arr, size);

int main() 
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // int n = 10;
    // int arr[n] {};              // zero-intialized classic array (using n is allowed only in g++)
    // int* dyn_arr = new int[n];  // dynamic allocated array
    // vector<int> v(n);           // actual dynamic array (auto resize)

    // // fill
    // fill(arr, arr+n, 5);
    // fill(v.begin(), v.end(), 5);

    // // iterate using iterators
    // for(auto it = v.begin(); it != v.end(); it++) // auto --> vector<int>::iterator
    // {
    //     cout << *it << ' ';
    // }

    // // free dynamic allocated array
    // delete [] dyn_arr;

    // set<int> s;
    // s.insert(3);
    // s.insert(5);
    // s.insert(3);
    // cout << s.count(3) << " " << s.count(4) << "\n\n"; // 1 0

    // s = {8, 5, 2, 8};
    // u_s.insert(3);
    // cout << "size: " << s.size() << "\n"; // 4 
    // for (auto x : s) cout << x << "\n";   // 2 3 5 8 (ordered unique elements)
    // cout << endl;
    
    // unordered_set<int> u_s = {8, 5, 2, 8};
    // u_s.insert(3);
    // cout << "size: " << u_s.size() << '\n'; // 4
    // for (auto x : u_s) cout << x << "\n";   // 3 2 5 8 (Unordered unique elements)

    //map<int, int> m;
    //cout << m[3]; // 0 (creates a pair: [3, 0] where 0 is the default value of int)

    // vector<int> adj[100]; // array of vectors
    // adj[1].push_back(2);
    // adj[2].push_back(3);
    // adj[2].push_back(4);
    // adj[3].push_back(4);
    // adj[4].push_back(1);
    // vector<int> v = {0, 7, 1};
    // sort(v.begin(), v.end());

    // cout << v.back() << ' ';
    // v.pop_back();
    // cout << v.back();

    // vector<int> path(1, 1);
    // reverse(path.begin(), path.end());
    
    
    // int arr[5] = {1, 5, 6, 7, 8};
    // cout << "lower bound for element 5: " << *lower_bound(arr, arr + 5, 5) << endl;
    // cout << "lower bound for element 3: " << *lower_bound(arr, arr + 5, 3) << endl;
    // cout << "upper bound for element 5: " << *upper_bound(arr, arr + 5, 5) << endl;

    // cout << "lower bound for element 5 is at index: " << lower_bound(arr, arr + 5, 5) - arr << endl;
    // cout << "lower bound for element 3 is at index: " << lower_bound(arr, arr + 5, 3) - arr << endl;
    // cout << "upper bound for element 5 is at index: " << upper_bound(arr, arr + 5, 5) - arr << endl;
 
    // cout << "upper bound for element 10 is at index: " << upper_bound(arr, arr + 5, 10) - arr << endl; //Not Found
    // list<int> l;

    // // push (front, back)
    // l.push_back(5);
    // l.push_back(7);

    // l.push_front(4);
    // l.push_front(1); // 1 4 5 7

    // // pop (front, back)
    // l.pop_front();   // 4 5 7

    // // size
    // cout << "size: " << l.size() << '\n';

    // // insert
    // for(auto i = l.begin(); i != l.end(); i++)
    // {
    //     if(*i == 7)
    //     {
    //         l.insert(i, 6); // 4 5 6 7
    //         break;
    //     }
    // }

    // // print
    // for(auto node : l)
    // {
    //     cout << node << ' ';
    // }

    // vector<int> v;
    // v.erase()

    int n = 1, m = 2;
        int board[n][m];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                board[i][j] = 1;
            }
        }

        cout << 3;
}