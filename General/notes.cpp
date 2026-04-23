#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
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
// n ≤ 12           O(n!)
// n ≤ 25           O(2^n)
// n ≤ 500          O(n^3)
// n ≤ 10^4         O(n^2)
// n ≤ 10^6         O(n*Log(n))
// n ≤ 10^8         O(n)
// n ≤ 10^18        O(Log(n)), O(1)

// --> For small (n) and complicated problems consider using (Brute Force), that might be trying;
// All possiple subsets O(2^n)
// All possible permutations O(n!)



//                                                  Read & Write
// The C functions scanf and printf
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


// Ternary (conditional) operator
int num = 9;
cout << "num relativity to 5 is " << (num > 5 ? "greater" : (num < 5 ? "lower" : "Equal")); // nested ternary


#include<algorithm>

    // Sort O(n*log(n))
    sort(arr, arr + n)
    sort(arr, arr + n, greater<int>());     // sort in descending order
    sort(vec.begin(), vec.end());           // sort string or vector. use begin(), end() iterators   (end() points one after the last char)
    
    /* Some sort alogorithms: 
        - bubble sort, insertion sort, selection sort --> O(n^2) 
        (exmple) Bubble Sort: compares adjacent elements and swaps them if they are in the wrong order. (move smaller elemments into the far left or larger elements into the far right)
                
        - Merge Sort O(n*log(n)): divides the array into halves, sorts each half, and then merges the sorted halves back together. (divide and conquer)
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
    
                                    (BST vs hash table)
    ----------------- unordered_container   vs    container ---------------------------
    | Implementation    Hash Table	                Balanced Binary Tree (Red-Black)  |
    | Average Speed	    O(1)                        O(log N)                          | (adding, removing, and checking)
    | Worst-Case	    O(N)                        O(log N)                          |
    | Ordering          None                        Sorted                            |
    -----------------------------------------------------------------------------------


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

    Solution: arr[l]++ and arr[r+1]-- ,then after taking all ranges perform (prefix sum)
    
    For the range [1, 3]
    arr = [1,0,0,−1,0,0]    --> 1 at (1)-1 and -1 at (3)
    arr = [1, 1, 1, 0, 0, 0]  // after prefix sum
*/

/* Maths

    Geometric progression
        sum = a + ak + ak^2 +··· + b = (bk−a) / (k−1)

        where (a) is the first number, (b) is the last number and 
        the ratio between consecutive numbers is k. For example,

        This formula can be derived as follows: 
            Let S = (a) + ak + ak^2 +··· + b
            By multiplying both sides by k, we get
            kS = ak + ak^2 + ak^3 +··· + (bk)
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