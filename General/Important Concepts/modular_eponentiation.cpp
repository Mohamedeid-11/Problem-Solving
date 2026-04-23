#include <iostream>
using namespace std;
typedef unsigned long long ull;

// Time Complexity --> O(logn)

// call stack --> 240^(84), 240^(42), 240^(21), 240^(10), 240^(5), 240^(2), 240^(1), 240^(0)
int recursive_expMod(int x, int n, int m)
{
    if (n == 0)
        return 1;

    // get x^(n/2) 
    ull u = recursive_expMod(x, n / 2, m);

    // x^n = x^(n/2) * x^(n/2)
    u = (u * u) % m;

    // if (n is odd) then u = x^(n-1) not x^n
    if (n % 2 == 1)
        u = (u * x) % m;

    return u;
}

// using powers of 2
int expMod(int x, int n, int m)
{
    // 240^(84) % m
    // (u) --> x^(2^k)
    // (k) is the bits of 84: {1, 0, 1, 0, 1, 0, 0};     //powers of 2 --> 2^0 : 2^6 (1:64)
    ull u = x%m, res = (n&1)? u : 1;
    n >>= 1;

    while(n > 0)
    {
        // Repeated Squaring: The base(x) is repeatedly squared and reduced modulo m
        // u --> 240^(1), 240^(2), 240^(4), 240^(8), 240^(16), 240^(32), 240^(64)
        u = (u * u) % m;

        // add the squares(u) the result require: 240^4, 240^16, 240^64 = 240^84
        if(n & 1) res = (res * u) % m;

        // divide by 2 (shift/remove the 1st bit)
        n >>= 1;
    }

    return res;
}

int main()
{
    // 240^(84) % 14
    int a = 240, b = 84, m = 14;
    cout << expMod(a, b, m);
}

// https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/fast-modular-exponentiation