#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits.h>

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}


// Special Problems
// Level 1\weeks\week 3\sheet\I_Snacktower  -->  https://codeforces.com/group/g3REqA871s/contest/570641/problem/I
// Level 1\weeks\week 3\sheet\L_Yet Another Broken Keyboard.cpp  -->  https://codeforces.com/group/g3REqA871s/contest/570641/problem/L
// Level 1\weeks\week 3\contest\B.cpp (Maths - sum of sum) --> https://codeforces.com/group/3MTZPM7hsC/contest/652811/problem/B



//                                              DO NOT EXCEED SIZE LIMIT
// max int: 10^9
// max long long: 10^18 
// float offers single-precision, providing approximately 6-7 significant decimal digits of precision.
// double offers double-precision, providing approximately 15-17 significant decimal digits of precision.
int n = 1e5, l = 1e9;
long long a = (1LL)*n*n + (long long)l*l;      // or:      (static_cast<long long>(n) * n) - (static_cast<long long>(l) * l);
cout << a;

//                                                    Complexity
// n ≤ 10           O(n!)
// n ≤ 20           O(2^n)
// n ≤ 500          O(n^3)
// n ≤ 5000         O(n^2)
// n ≤ 10^6         O(n*Log(n))
// n ≤ 10^8         O(n)
// n ≤ 10^18        O(Log(n)), O(1)

// --> For small (n) and complicated problems consider using (Brute Force), that might be trying;
// All possiple subsets O(2^n)
// All possible permutations O(n!)

//                                                       RULES
// 1. Avoid (Overflow) --> long long, double
// 2. Avoid (Flooting points) as possible
// 3. check (x-y) < 1e-9 for floats equality
// 4. Don't you EVER skip (test cases)

// 5. Check time limit:

// 6. To solve a problem you have to:
//   1. Design the soluion.
//   2. Implement it (code it).
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

// 1. Pure Simulation / Ad-Hoc
// How to Identify: The problem statement is long, detailed, and acts like a rulebook (e.g., simulating a game of chess, a card game, or robot instructions). There is no hidden math; you just code exactly what is written.

// 2. Math / Number Theory / Combinatorics

// How to Identify: Asks for answers modulo 10^9+7, requires counting arrangements, finding divisors, prime factorization, or dealing with huge coordinate geometry spaces.
// Triggers: "Count the number of ways...", "Find the number of pairs (i, j) such that gcd(A_i, A_j) = 1".
// Constraints & Complexity:
// N <= 10^{18} --> O(1) or O(log N) (e.g., Fast Exponentiation, Euclidean GCD).
//    N <= 10^7 --> O(N) or O(N log log N) (e.g., Sieve of Eratosthenes).

// 3. Constructive Algorithms

// How to Identify: The problem asks you to construct an array, matrix, or graph satisfying highly specific conditions. It usually states: "If multiple solutions exist, print any."
// Triggers: "Construct an array where no two adjacent elements...", "Output a matrix such that the sum of each row is prime."
// Constraints & Complexity: N <= 10^5 --> O(N). It requires finding an invariant or a pattern, not a heavy data structure.

// 4. Greedy

// How to Identify: Making a locally optimal choice right now never ruins your choices later. Sorting or picking the absolute maximum/minimum element at each step yields the correct global answer.
// Triggers: "Find the minimum number of operations...", "Maximize the total value...".
// Constraints & Complexity: N <= 10^5 --> O(N log N) (heavily dominated by std::sort).

// 5. Binary Search (On Answer /  )

// How to Identify: Finding the exact answer directly is incredibly hard, but verifying a "guessed" answer is very easy. This means if a guessed number works, all numbers larger than it also work (or vice versa). Your goal is to find the exact boundary where the answer flips from working to not working.
// Triggers: "Minimize the maximum...", "Maximize the minimum...".
// Constraints & Complexity: Range up to 10^{18} --> O(N log(text{Max_Value})).

// 6. Two Pointers & Sliding Window

// How to Identify: You are scanning a linear structure (array or string) to find a continuous subarray, subsegment, or a pair of elements that meet a condition.
// Triggers: "Find the longest contiguous subarray with sum <= K", "Find a pair with sum equal to X in a sorted array."
// Constraints & Complexity: N <= 10^7 --> O(N) because the left and right pointers only move forward.

// 7. Divide and Conquer

// How to Identify: The problem can be split into two entirely independent halves, solved separately, and then merged efficiently.
// Triggers: Inversion counting, calculating large polynomial multiplications, or evaluating recurrence relations via Matrix Exponentiation.
// Constraints & Complexity: N <= 10^5 --> O(N log N) or K <= 100 --> O(K^3 log N) for matrix exponentiation.

// 8. Basic Graphs & Trees (Traversal)

// How to Identify: Explicitly describes networks, cities connected by roads, family trees, or 2D grids where you can move up/down/left/right.
// Triggers: "Find the shortest path in an unweighted grid", "Check if a network is fully connected", "Find the diameter of a tree."
// Constraints & Complexity: V, E <= 10^5 --> O(V + E) using BFS (for unweighted shortest path) or DFS (for connectivity/trees).

// 9. Advanced Graphs (Shortest Paths & MST)

// How to Identify: Graphs where edges have variable costs/weights, and you need to optimize paths or connect everything with the lowest possible cost.
// Triggers: "Find the cheapest flight path...", "Connect all servers using the minimum length of cable."
// Constraints & Complexity: V, E <= 10^5 --> O(E log V) using Dijkstra (shortest path) or Kruskal’s/DSU (Minimum Spanning Tree).

// 10. Dynamic Programming (DP)

// How to Identify: Choices are highly dependent. Choosing an option now restricts or changes your choices in the next step. (forcing You to consider the future consequences, unike greedy) A recursive tree shows that you are calculating the exact same parameters over and over.
// Dynamic Programming simply means: The first time you calculate the best way to get from Floor 2 to the top, you save that answer in a table (array). The next time you land on Floor 2, you just look up the answer instantly instead of recalculating it.
// Triggers: "Find the maximum profit given a limited capacity...", "Count the number of paths from top-left to bottom-right under conditions."
// Constraints & Complexity:
// N <= 5000 --> O(N^2) states.
//    N <= 500 --> O(N^3) states.

// 11. Range Queries & Static Data Structures

// How to Identify: You are given an array, and you must process thousands of queries. The array elements might update dynamically between queries.
// Triggers: "Query: find the sum/minimum from index L to R. Update: change element at index i to X."
// Constraints & Complexity: N, Q <= 10^5 --> O(Q log N) using Segment Trees or Fenwick Trees (BIT). If there are no updates, O(1) query using Sparse Tables or Prefix Sums.

// 12. String Algorithms

// How to Identify: Heavy pattern matching, finding repeating substrings, or calculating cyclic shifts. Standard string methods will TLE (O(N^2)).
// Triggers: "Find all occurrences of pattern P in string S", "Find the longest palindromic prefix."
// Constraints & Complexity: abs(S) <= 10^6 --> O(abs(S)) using KMP, Z-Algorithm, or String Hashing.

// 13. Bitmask / Subset Generation (Small N)

// How to Identify: The constraints are deliberately engineered to be incredibly small, signaling that you must explore every single mathematical combination.
// Triggers: "Choose a subset of items...", "Find a permutation of elements...".
// Constraints & Complexity:
// N <= 20 --> O(2^N) (Iterating through all subsets or Bitmask DP).
//    N <= 10 --> O(N!) (Iterating through all permutations via std::next_permutation).

// 14. Meet-in-the-Middle

// How to Identify: A subset problem where N is just slightly too large for an O(2^N) approach, but too small for anything else.
// Triggers: "Find a subset that sums exactly to X," where N approx 40.
// Constraints & Complexity: N <= 40 --> O(2^{N/2} log(2^{N/2})) by splitting the array into two halves of size 20, generating all subsets for both, and using binary search to match them.

// ------------------------------
// Ultimate Pre-Coding Strategy
// When you open a problem, mentally execute this 3-Second Filter Pipeline:

//    1. Check N: Is it <= 20? Jump straight to Bitmask/Permutations. Is it ge 10^{12}? Jump straight to Math/O(1)/O(log N).
//    2. Check Structure: Does it mention strings, grids/graphs, or interval updates? Instantly narrow your focus to those specific standard data structures.
//    3. The Dependency Test: If it's a general array/sequence problem, ask: Does sorting fix it? If Yes rightarrow Greedy/Two Pointers. If No, ask: Can I binary search a guessed answer? If Yes rightarrow Binary Search on Answer. If No rightarrow Dynamic Programming.
*/


//                                                  Read & Write
// The C functions scanf and printf (Formated String)
// alternative to the C++ standard streams. They are usually a bit faster, but they are also more difficult to use.
int a, b;
scanf("%d %d", &a, &b);
printf("%d %d\n", a, b);

// Read line
string s;
getline(cin, s);

// Unknown amount of data
while (cin >> x)
{
    ;
}

// Files
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
//



/*                                              (Type Conversion)

-Implicit conversion: Conversion Is Automatically done By The Compiler
-Explicit conversion(Type casting): Conversion Is done By The Programmer:
    int c = 90;
    cout << char(c) << endl;
*/

//                                            (Pointer - Reference)
int x = 5;
cout << &x << endl;   // cout pointer of x (reference operator)    

int &ref_x = x;       // x and ref_x have the same address (ref_x is an alias to x)
cout << &ref_x << endl;

int *ptr = &x;        // store pointer
cout << ptr << endl;  // cout pointer of x
cout << *ptr << endl << endl; // cout the value ptr points to (dereference operator)



// Dynamic Variables
int *num = new int(1);  // allocated during excution (at run time) in the heap
cout << *num;

delete num;             // always remember to free dynamic allocated space 
num = nullptr;



// Arrays
/* Linked List:
    - When You don't know how many items will be in the list.
    - Types:
        1. Singly Linked List   --> each node points to the next
        2. Doubly Linked List   --> each node points to prev and next
        3. Circular Linked List --> Doubly Linked List but (the head and the tail points to each other)

    - STL --> list<T>
        Doubly Linked
        
        No Random Access O(n): You must traverse the list using iterators.
        Dynamic Size: Lists can grow or shrink dynamically as elements are added or removed

        list<int> l;

    // push (front, back)
        l.push_back(5);
        l.push_back(7);

        l.push_front(4);
        l.push_front(1); // 1 4 5 7

    // pop (front, back)
        l.pop_front();   // 4 5 7

    // size
        cout << "size: " << l.size() << '\n';

    // insert
        for(auto i = l.begin(); i != l.end(); i++)
        {
            if(*i == 7)
            {
                l.insert(i, 6); // 4 5 6 7
                break;
            }
        }

    // print
        for(auto node : l)
        {
            cout << node << ' ';
        }
*/
// Array List:
// When random access is the most important. O(1)
// memory is allocated at compile time(at the stack) having a fixed size. We cannot update the size of this array.
    int a[] = {1, 2, 3};
    cout << *(a+2); //  3

    // Fixed-Sized
    // static array types are distinct based on their size. 
    int old_arr[3] = {3, 4, 5};
    int new_arr[5] = {3, 4, 5, 10, 11};
    old_arr = new_arr;                 // error:  incompatible types in assignment of 'int [5]' to 'int [3]

    // Different ways of passing an array to function:
        // 1. taking a pointer (int *)
        void f1(int *a, size_t n);
        void f2(int x[], size_t n);    // Exactly the same as int *a

        // The 100 is ignored in a function parameter; x still decays to int*. sizeof(x) prints pointer size 
        void f3(int x[100]);                

        // 2. Passing a reference
        void foo_4(int(&x)[100]);       // only accepts arrays of 100 integers. sizeof(x) prints 100
        /* 
         you have to use:   type (&array)[size]    
         to clarify to the compiler that you want a reference to an array,
         rather than the (invalid) array of references:     type &array[size];
        */

        // 3. array<T,N>
        void f5(array<int, 4> a);            // copy
        void f5_ref(const array<int,4>& a);  // refer without copy

    // Char Array
    // define char arraies larger by 1 to keep space for the '\0' character

        // Taking input
            char str[3];
            //cin >> str; // might cause an ERROR
            for(int i = 0; i < 3; i++) cin >> str[i]; // safer

        // all the following are the same
            char str[3] = "ab";
            char str[] = {'a', 'b'};
            char str[3] = {'a', 'b'}; // where str[2] == '\0'

        // Prints a string, not address 
            cout << str; 

        // char to int
            cout << char(65); // A

    // Dynamic array 
    // memory is allocated at run time(at the heap) but NOT having a fixed size.
        int *p;       
        // then later...
        p = new int[3];
        delete[] p; p = nullptr;

        // Change size through copying (since we are dealing with pointers)
        int* dynamic_old_arr = new int[]{3, 4, 5};
        int new_size = 5;
        int* dynamic_new_arr = new int[new_size]{3, 4, 5, 10, 11};

        dynamic_old_arr = dynamic_new_arr;

        for(int i = 0; i < new_size; i++)
        {
            cout << dynamic_old_arr[i] << " ";
        }


    // Return
        array<int, 5> func1();  // if size is known
        vector<int> func2();    // if not
        // dynamic array
        int* func3(size_t n) 
        {
            int* p = new (nothrow) int[n];  // returns nullptr on failure instead of throwing
            if (!p) return nullptr;

            for (size_t i = 0; i < n; ++i) 
                p[i] = 0;

            return p;
        }   

        int main() {
            auto p = func3(10);
            if (!p) cerr << "allocation failed\n";

            // YOU MUST DEALLOCATE THE MEMORY
            delete[] p;
            p = nullptr;
        }
//



// Type Alias
    using ll = long long;
    // or
    typedef long long ll;
    ll n = 1e15;
    cout << sizeof(n) << endl;
/

/* Macros
    Another way to shorten code is to define macros. A macro means that certain
    strings in the code will be changed before the compilation. In C++, macros are
    defined using the #define keyword.
*/
#define F first
#define S second
#define PB push_back
#define MP make_pair

#define REP(i,a,b) for (int i = a; i <= b; i++)

// then we can user the for loop like:
REP(i,1,n) {
    search(i);
}



// Ternary (conditional) operator
int num = 9;
cout << "num relativity to 5 is " << (num > 5 ? "greater" : (num < 5 ? "lower" : "Equal")); // nested ternary


    
// User-defined structs (comparison)
struct P {
    int x, y;
    bool operator<(const P &p) {
        if (x != p.x) return x < p.x;
        else return y < p.y;
    }
}


// Comparison functions
//     It is also possible to give an external comparison function to the sort function
//     as a callback function. For example, the following comparison function comp sorts
//     strings primarily by length and secondarily by alphabetical order:
bool comp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();   
    return a < b;
}

// Custom comparator: ascending by .second, descending by .first
struct comp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        if (a.second != b.second) {
            return a.second < b.second; // Ascending by .second

        }
        return a.first > b.first;   // Descending by .first
    }
};

// Now a vector of strings can be sorted as follows:
sort(v.begin(), v.end(), comp);


#include<algorithm>

    // Sort O(n*log(n))
    sort(arr, arr + n)
    sort(arr, arr + n, greater<int>());     // sort in descending order
    sort(vec.begin(), vec.end());           // sort string or vector. use begin(), end() iterators   (end() points one after the last char)
    
    /* Some sort alogorithms: 
        - O(n^2): 
            Bubble Sort: compares adjacent elements and swaps them if they are in the wrong order. (move smaller elemments into the far left or larger elements into the far right)
            insertion sort
            selection sort
                
        - O(nlog(n)): 
            Merge Sort: divides the array into halves, sorts each half, and then merges the sorted halves back together. (divide and conquer)
        
        - O(n):
            Counting sort: You simplly build a frequency array in O(n) then construct it in O(n). The constraint here is the range of numberes (n) 
    */

    // Reverse
    reverse(arr, arr + n)

    // Max Element
    *max_element(arr, arr + n);

    // Index of value
    distance(arr, find(arr, arr + n, a))    // get index of element (a) in array (arr) with size(n)

    // Permutations
        vector<int> v = {1, 2, 3};
        sort(v.begin(), v.end()); // Sort first to ensure we start from the beginning

        do {
            for (int i : v) cout << i << " ";
            cout << "\n";
        } while (next_permutation(v.begin(), v.end()));
//

#include<iomanip>

    // Set float, double fixed precision
    cout << fixed << setprecision(8) << double_number;
    printf("%.8f\n", double_number);
//

#include <numeric>

    // Sum
    sum = accumulate(arr, arr+n, 0);
/


// String
    size(str)

    to_string(number)           // number to string  
    stoi(str)                   // string to int
    stod(str)                   // string to double
    stoll(str)                  // string to long long
   
    str.append(100, 'A');       // add 100 'A's

    str.back()                  // reference to the last element == str[size(str) - 1]

    s.begin()                   // gets an iterator to the first element in an string
    s.end()                     // gets an iterator to the last element in an string -->('\0')

    s.find(c)                   // returns char (c) first occurance index

    s.erase()                   // Erases whole string
    s.erase(idx)                // Erases all characters after idx
    s.erase(idx, 3)             // Erases 3 characters after idx
    s.erase(itr)                // Erases character at itr
    s.erase(first, last)        // Erases character in range [first, last)
    s.erase(s.begin() + 4);     // Erases s[4]
    s.erase(s.end() - 1);       // Erases the last character in the string (before the '\0')
/


#include <bits/stdc++.h>


    lcm(a, b)
    __gcd(a, b)
/



#include <cmath>
    ceil()     // round up
    round()    // round
    floor()       // round down
/


// check if double number has a fraction 
#include <cmath>
bool hasNoDecimal(double x)
{
    double integer_part = trunc(x);
    //(3.001 - 3) or (2.999 - 3) 
    return abs(x - integer_part) < 1e-9 || abs(x - integer_part) > (1 - 1e-9);
}



// Map (dictionary)
    map<int, int> numbers;
    
    int n = 10, num;
    for(int i = 0; i < n; i++)
    {
        cin >> num;
        numbers[num]++; // if num didn't exists the map will create a pair for it with default value [num, 0] (int's default 0)
    }

    // iterate over pairs
    for(auto [first, second] : numbers)
    {
        cout << first << ' ' << second << '\n';
    }

    // prefix_sum
    int runningSum = 0;
    for (auto& [key, value] : freq) 
    {
        runningSum += value;
        value = runningSum;
    }
//

// Data Structures & STL
/* 
Stack
    A box with one open side that follows the Last In First Out (LIFO) principle.

Queue
    A box with an adding side and a removing side that follows the First In First Out (FIFO) principle.

Deque
    A box that allow adding and removing from both sides. 
    similar to vectors (supports random access), but more efficient in inserting and deleting elements

Priority queue
    - A container that allows fast retrieval of the largest (or smallest) element.
    - sort the elements. 
    - methods:
        - pq.top() in O(1) 
        - pq.push() & pq.pop() in O(log(n))

    - min priority queue: 
        priority_queue<int, vector<int>, greater<int>> mpq; 
Bitset
    A bitset is an array whose each value is either 0 or 1. For example, the following
    code creates a bitset that contains 10 elements:
        bitset<10> s;
        s[1] = 1;
        s[3] = 1;
        s[4] = 1;
        s[7] = 1;
        // or bitset<10> s(string("0010011010")); // from right to left
        cout << s << "\n";    // 0010011010
        cout << s[4] << "\n"; // 1
        cout << s[5] << "\n"; // 0


Inner Structures:

    - Balanced Binary Tree  (Binary Search Tree - BST):
        Has the following properties:
        - The left subtree of a node contains smaller nodes only.
        - The right subtree of a node contains greater nodes only.
        - The left and right subtree each must also be a binary search tree.

    - Hash table: 
        1. When you insert an element, a hash function (std::hash by default) takes it and produces a (unique hash value).
        2. This hash value is mapped to a specific "bucket" using a modulo operation (we have a finite number of buckets and we have to reuse them); bucketIndex = hashValue % totalBuckets.
        3. The element is stored in that bucket if it's unique hash value doesn't already exist.
        - we can then find any value in O(1) by getting its hash value and then looking in the corresponding bucket.
                                    
        - Some problems might include anti-hash tests, which can cuase it run in O(n^2)
    
                                    (hash table vs BST)
    ----------------- unordered_container     vs    container ---------------------------
    | Implementation    Hash Table	                  Balanced Binary Tree (Red-Black)  |
    | Average Speed	    O(1)                          O(log N)                          | (insertion, deletion, and Look-up)
    | Worst-Case	    O(N)                          O(log N)                          |
    | Ordering  (doesn't keep insertion order)   (Sorts the elemnets ascendingly)       |
    -------------------------------------------------------------------------------------


Set
    - A (UNIQUE) set of elements. (doesn't support random access)

    - The C++ standard library contains two set implementations: The structure
        1. set                       --> (ordered) based on a BST average operation time: O(log(n)).
        2. unordered_set (Hashsets)  --> (unordered) based on Hash Table, average operation time: O(1).
  

    - BST set Methods:
        - insert():           Adds an element to the set. O(log(n))
        
        - count(element):     Returns (0, 1) indicating the number of occurrences of the element. O(log(n))
        - find(element):      Returns an iterator to the element in the set if found, else returns the iterator to the end. O(log(n))
        
        - erase(pos):         Removes the element from the specified address from the set. O(1)
        - erase(value):       Removes the specified element from the set. O(log(n))
        - erase(first,last):  Removes the specified range of elements from the set. O(n)
    
    - Example:
        set<int> s;
        s.insert(3);
        s.insert(5);
        s.insert(3);
        cout << s.count(3) << " " << s.count(4) << "\n\n"; // 1 0

        s = {8, 5, 2, 8};
        u_s.insert(3);
        for (auto x : s) cout << x << "\n";   // 2 (3) 5 8 (ordered unique elements)
        cout << endl;
        
        unordered_set<int> u_s = {8, 5, 2, 8};
        u_s.insert(3);
        for (auto x : u_s) cout << x << "\n";   // (3) 2 5 8 (Unordered unique elements)

Multiset
    - Exactly like set but elements are (NOT unique)
    - have 2 versions also: multiset and unordered_multiset

Map (dictionary)
    - store key, value pairs where keys are unique.
    - have 2 versions also: sorted maps (sort keys) and unordered_map (hashmaps)
    - if you access a non-existing key, the map creates a place for it with an (defualt) value.
        map<int, int> m;
        cout << m[3];       // 0 (creates a pair: [3, 0] where 0 is the default int value)

        
- In a sorted container:
    The lower_bound(k)      returns an iterator/pointer to the element (greater than or equal) to k.
    The upper_bound(k)      returns an iterator/pointer to the element (greater) than k.
    
    - they use binary search so time complexity: O(log(N))
    
    int arr[5] = {1, 5, 6, 7, 8};
    cout << "lower bound for element 5: " << *lower_bound(arr, arr + 5, 5) << endl;  // lower bound for element 5: 5
    cout << "lower bound for element 3: " << *lower_bound(arr, arr + 5, 3) << endl;  // lower bound for element 3: 5
    cout << "upper bound for element 5: " << *upper_bound(arr, arr + 5, 5) << endl;  // upper bound for element 5: 6


    cout << "lower bound for element 5 is at index: " << lower_bound(arr, arr + 5, 5) - arr << endl;    // lower bound for element 5 is at index: 1
    cout << "upper bound for element 10 is at index: " << upper_bound(arr, arr + 5, 10) - arr << endl;  // upper bound for element 10 is at index: 5 (Not Found)


    **(NOTICE)**
    the previous global function std::upper_bound requires (random access) to be able to run in O(log(n))
    using it with (set) or (multiset) will run in O(n) instead as there's no random access.
    (the same applies to std::map and std::multimap)
    
    (INSTEAD)
    use the embedded methods: 
    
    s.lower_bound(value);
    s.upper_bound(value);
*/

/* Complete search
    - A brute-force algorithm that tries all possible combinations(subsets, permutations) to find a solution.
    - It is often used when the problem size is small or when there are no efficient algorithms available.
*/

/* How to solve Binary Search problems:
    1. Define a sorted search space (monotonic range (moves in one direction))
    2. Define a "Target" or a "Condition"

    When to use Binary Search:
    - Searching for an element in a sorted array
    - Finding the first or last occurrence of an element
    - Optimization problems: 
      Most number of burgers that don't exceed the budget (Level 1\weeks\week 4\sheet\B_Hamburgers.cpp)

    Complexity:
    - Time Complexity: O(log N) — the search space halves every step
*/ 

/* How to solve recursion problems:
    1. Define the problem
    2. Define a subproblem from it
    3. (Trust) the process
    4. Link 1 & 2
    5 write the Base Case:      the (Last valid || First invalid) case

    * if you have a tree, you can use recursion

    Recursive vs Iterative Solution:
    - Any recursion problem can be solved iterativly
    - Iteration has better space complixty (Doesn't use (call stack) like recursion)
    - Recursion has better readability, and sometimes it's much simpler
    - Recursion has 2 phases:
        1. Ascending Phase: Calling phase
        2. Descending Phase: Return phase

    - Iteration has only 1 phase

    Time comp   -->     nodes * T(node)
    Space comp  -->     depth (number of functions in the call stack)


    --> A (backtracking) algorithm begins with an empty solution and extends the
        solution step by step. 
        The search recursively goes through all different ways how a solution can be constructed
*/

/* Greedy Algorithm (a way of thinking)

    - constructs a solution by always making the best choice at the moment 
    
    - it constructs the final solution directly, without backtracking or reconsidering previous choices. 
      which makes it faster than other algorithms like dynamic programming, but it (doesn't always guarantee the optimal solution).
      
        (For example), for the following set of coins: {1,2,5,10,20,50,100,200} 
        What is the minimum number of coins needed to make n (520)?
        n = 520, we need at least four coins. The optimal solution is to select coins 200+200+100+20 whose sum is 520
        --> A simple greedy algorithm to the problem always selects the largest possible coin, until the required sum of money has been constructed. 
    
    - Note: it often is not obvious whether a greedy algorithm is correct or not. If it is the intended solution, problem authors are expected to be able to prove its correctness. However, as a contestant, if the algorithm is easy to implement, one option is to just code it and see whether it passes. Competitive programmers refer to this as "Proof by AC," or "Proof by Accepted."
        
        (For example), if the coins are {1,3,4} and the target sum is 6, the greedy
        algorithm produces the solution 4+1+1 while the optimal solution is 3+3.
        It is not known if the general coin problem can be solved using any greedy algorithm


    (Example) - Many scheduling problems can be solved using greedy algorithms. A classic problem is as follows: 
    Given n events with their starting and ending times, find a schedule that includes as many events as possible. 
    It is not possible to select an event partially. For example, consider the following events: 
    event | starting time | ending time
    A     | 1             | 3
    B     | 2             | 5
    C     | 3             | 9
    D     | 6             | 8
    In this case the maximum number of events is two. 

    we can think of 3 greedy algorithms to solve this problem:
        1. Select the earliest (starting) next event. (X) fails as it can be too long and block other events.
        2. Select the shortest next event.            (X) may block other events and can't guarantee the optimal solution.
        3. Select the earliest (ending) next event.   (✓) (Optimal Solution)
*/

/* Dynamic Programming (DP) a technique where we:
        1. Break down a problem into smaller subproblems
        2. Store results of subproblems to avoid recomputation
        3. Build up the final answer incrementally

Example: The "wow" Problem (ECPC Team selection\Contest 1\G_(DP).cpp)

    - The problem --> We need to count "wow"s in a string (vv" + "o" + "vv" (i.e., "wow" where w = consecutive "vv").
    - subproblems --> instead of counting "wow"s directly we can count "w", "wo", and "wow", so we can Build the final answer incrementally
    - Steps:
        1. Defining (States):
            At each position in the string, we track how many partial matches we've found:
            (State): w_count, wo_count, wow_count

        2. State Transitions
            Finding 'v' (when previous was also 'v'):
            - We formed a new "w"
            - This new "w" can extend all existing "wo" → new "wow"s
            - wow_count += wo_count
            - w_count += 1

            Finding 'o':
            - This "o" can extend all existing "w" → new "wo"s
            - wo_count += w_count

*/

/* Graph
    - Many programming problems can be solved by modeling the problem as a graph
      problem and using an appropriate graph algorithm. 

    - Graph terminology:
        - A graph consists of (n) nodes and (m) edges connecting them.
        - A path is a (cycle) if the first and last node is the same.
        - A graph is (simple) if no edge starts and ends at the same node, and there are no multiple edges between two nodes. 
        - A graph is (connected) if there is a path between any two nodes. 
            unconected parts of a graph are called (components).
            it's (directed) if edges have 1 directions, and (weighted) there're values assigned to them.

        - A (tree) is a connected graph that consists of n nodes and n−1 edges. 
            There is a (unique path) between any two nodes of a tree. 

        - The (degree of a node) is the number of its neighbors (nodes connected directly to it).
            (indegree) of a node is the number of edges directed to the node, and the 
            (outdegree) of a node is the number of edges directed (start) from the node.

        - The (sum of degrees) in a graph = 2m.
        - A graph is (regular) if the degree of every node is a constant d. (a tree is a regular graph with d = 1)
            (complete) if the degree of every node is n−1 (the graph contains all possible edges between nodes)

        - In a coloring of a graph, no adjacent nodes have the same color.
            a graph can be colored by 2 colors only (bipartite) when it does not contain a cycle with an odd number of edges. 

    - Graph representation:
        - Adjacency list: array of size N (number of nodes) where each node has a vector to store the nodes it's coneected to.
            vector<int> adj[N];
            1 --> 2
            2 --> 3, 4
            3 --> 4
            4 --> 1

        - Adjacency matrix: a 2x2 array that indicates the edges (cannot be used if the graph is large)
              ( 1 2 3 4 )
            (1) 0 1 0 0
            (2) 0 0 1 1
            (3) 0 0 0 1
            (4) 1 0 0 0

        - Edge list: contains all edges of a graph in some order. This is a convenient way to represent a graph if the algorithm processes all edges of the graph
            vector<tuple<int,int,int>> edges;    
            edges.push_back({1,2});
            edges.push_back({2,3});
            edges.push_back({2,4});
            edges.push_back({3,4});
            edges.push_back({4,1});

    - Graph traversal: 
        - Depth-first search (DFS)
            - Doesn't guarantee the optimal solution, time complexity O(n + m)
            - frontier implemented as a (stack)
        
        - Breadth-first search (BFS)
            - take more time in avarage but it guarantees the optimal solution, time complexity O(n + m) 
            - explores the graph level by level

            - start with a frontier (implemented as a queue) that contains the initial state.
            - start with an empty explored set.
            - repeat:
                1. if the frontier is empty --> no solution.
                2. remove a node from the frontier.
                3. if it matches the goal state --> return the solution
                4. add it to the explored set.
                5. expand it (add its not explored neighbours to the frontier)   

*/


/* Partial Sum
    Given q ranges of the form [l,r], find for each point x∈[1,n]
    the number of ranges that contain that point.

    Solution: arr[l-1]++ and arr[r]-- ,then after taking all ranges perform (prefix sum)
    
    For the range [1, 3]
    arr = [1, 0, 0, −1, 0, 0]    --> 1 at (1)-1 and -1 at (3)
    arr = [1, 1, 1,  0, 0, 0]  // after prefix sum
*/

/* Maths

    Geometric progression
        sum = a + ak + ak^2 +··· + b = (bk−a) / (k−1)

        where (a) is the first number, (b) is the last number and 
        the ratio between consecutive numbers is k. For example,

        This formula can be derived as follows: 
            Let S = (a) + ak + ak^2 +··· + b
            By multiplying both sides by k, we get
            kS = ak + ak^2 + ak^3 +··· + b + (bk)
            and solving the equation
            kS − S = bk − a
            S(k-1) = bk-a

        special case:
        1 + 2 + 4 + 8 +... + 2^(n−1) = 2^n − 1
        where a = 1, b = 2^(n−1), k = 2
    end

    Sum of Polynomial 
        1st degree:
            sum = 1 + 2 + 3 +... + n       -->      n(n+1)/2

            This formula can be derived as follows: 
                S = 1 +   2   +... + (n-1) + n
                S = n + (n-1) +... +   2   + 1
                then 
                2*S = (n+1) + (n+1) + (n+1) + ...(n times) 
                2*S = n(n+1)
                S   = n(n+1)/2
        
        2nd degree: 
            S = 1^2 + 2^2 + 3^2 .... n^2   -->      n(n+1)(2n+1)/6
    end 

    Prime and Factors (General\Important Concepts\prime_factors.cpp)

        - Any number can be represented by its prime factors: n = p1^α1 * p2^α2··· pk^αk,
          84 = (2^2) * (3^1) * (7^1)
 
        - Get prime fators algorithim O(sqrt(n))
        
            map<int, int> factors;
            for (int i = 2; i * i <= n; i++)
            {
                while (n % i == 0)
                {
                    n /= i;
                    factors[i]++;
                }
            }
            if(n > 1) factors[n]++;            // the number itself might be prime so it would be greater than sqrt(n)
        
        - The sieve of Eratosthenes O(n*log(n))  غربال ايراتوسثينيس 
            a preprocessing algorithm that builds an array (sieve)
            using which we can efficiently check if a given number between 2...n is prime
            and, if it is not, find one prime factor of the number.
        /

        - Number of Factors: (α1 + 1) * (α2 + 1) * ...

            to form a factor of 84 you can use 2 --> 0, 1 (2 times) and 3 --> 0 (once) from that we can conclude:
            number of factors (combinations) = (α1 + 1) * (α2 + 1) * ...
            84 --> 3 * 2 * 2 = 12

        - Sum of factors: ( (p1^(α1+1) - 1) / (p1 - 1) ) * ( (p2^(α2+1) - 1) / (p2 - 1) ) * ...
            
            we can form each factor from prime factors (with unique combination of powers each time)
            for example: 2: 2^1 * 3^0 * 7^0, 42 = 2^1 * 3^1 * 7^1

            so when you multiply the sums of the prime factors powers the distributive property creates 
            every possible combination of prime factors, and therefore creates every possible factor
            we need to sum:
            sum_of_factors(84) = (1 + 2 + 2^2) * (1 + 3) * (1 + 7)
            using geometric progression: 
                               = ((2^3 - 1) / (2-1)) * ((3^2 - 1) / (3-1)) * ((7^2 - 1) / (7-1))
                               = 7 * 4 * 8 = 224

        - Product of factors: n^(number_of_factors / 2)
            6 -> 1, 2, 3, 6 -> 2 * 3
            Product of factors = (6*1) * (2*3) = 6 * 6 = 6^2
            so we could conclude that power from number_of_factors = 4
            and each 2 factors make one 6, so power = 4/2 = 2 
        84 --> 84^6

    end

    LCM - GCD
        Gratest Common Divisior(GCD) is the greatest number that can divide both a and b
        gcd(4, 6) = 2, list devisors:
        4 --> 1, (2), 4
        6 --> 1, (2), 3, 6

        - To simplify two numbers(x, y) --> devide them by their gcd(x, y)
            int GCD = gcd(num1, num2);
            int simplified_num1 = num1/GCD;

        Least Common Multiple(LCM)   is the smallest number that is a multiple of a and b  
        lcm(4, 6) = 12, list multiples:
        4 --> 4, 8, (12)
        6 --> 6, (12)

        - We can use prime factors:
            4 = 2^2 * 3^0
            6 = 2^1 * 3^1

            gcd(4, 6) = 2^1 * 3^0 = 2                       (use least powers)
            lcm(4, 6) = 2^2 * 3^1 = 12                      (use greatest powers)

            gcd(4, 6) * lcm(4, 6) = 2^3 * 3^1 = 4 * 6 = 24

        - lcm(a,b) * gcd(a,b) = a * b     
    END

    Bits
    x is divisible by 2^k when:     x & (2^k − 1) = 0

        This formula can be derived as follows: 
            12 is divisible by 4 as 12 & 3 =
            1100 &
            0011
            = 00

            which means that 12 doesn't have (1 or 2 or 3 which will make it undivisible)
            like in 9, 10, 11 notice:
            9  % 4 = 1
            10 % 4 = 2
            11 % 4 = 3
    end

    The left bit shift x << k    -->   (x * 2^k) appends k zero bits to the number
           8 4 2             32 16 8            (notice how the weights doubled by 2^2)
        14(1 1 1 0) << 2 = 56(1 1 1 0 0 0)
    
    The right bit shift x >> k   -->   (x / 2^k) removes the k last bits from the number
        49(110001) >> 3 = 6(110)

*/

// Bits
    // devide by 2
        x = x >> 1;
    // multiply by 2
        x = x << 1;
    // Read bits | Get binary representation
        // instead of 31 you can get use the number of bits that contains x --> log2(x)  
        // (we didn't round up as (i) reaches 0)
        for (int i = 31; i >= 0; i--) 
        {
            /*
                x = 13   -->  1101
                x & 1000 --> &1000 --> 1
                x & 100  -->  &100 --> 1
                x & 10   -->   &10 --> 0
                x & 1    -->    &1 --> 1
            */
            if ( x & (1 << i) )
                cout << "1";
            else 
                cout << "0";
        }

    // Edit Bits
        x |= (1 << pos);  // turn the bit at position (pos) into 1
        x &= ~(1 << pos); // turn the bit at position (pos) into 0
        /*
            13 &= ~(1 << 3) --> 13 &=(1000 --> 0111)

              1101
            & 0111
            = 0101
        */

    // Set
    // since int has 31 bits and we can edit each one of them, we can use it to hold a set range (0 : 31)
        // x = {1,3,4,8}    we can represeant it through:
        int x = (1<<1)|(1<<3)|(1<<4)|(1<<8);


//

// Class & templates 
// .h file (decleration)
template <class N>
class rec
{
private:
    N width;
    N height;

public:
    rec(N, N);
    rec();
    N area();
    ~rec() {};
};

// .cpp file (difinitions)
#include "rec.h"

template <class N>
rec<N>::rec(N w, N h) : width(w), height(h) {} // constructor

template <class N>
N rec<N>::area() // (::) is the Scope Resolution Operator
{
    return width * height;
}

// int nums[5] = {1, 4, 9, 2, 6};
// cout << *max_element(nums, nums + 5);
// int n = 100001;
// int map[n];
// for (int i = 0; i < n; i++)
// {
//     map[i] = i;
// }
// long long sum = 0;
// int a = 0, b = 10000;
// while (n > 10000)
// {
//     sum = accumulate(map + a, map + b, sum);
//     a += 10000;
//     b += 10000;
//     n -= 10000;
// }
// sum = accumulate(map + a, map + a + n, sum);
// cout << sum;