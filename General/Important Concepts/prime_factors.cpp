#include <bits/stdc++.h>
using namespace std;

/*
https://stackoverflow.com/questions/11924249/finding-prime-factors
https://www.youtube.com/watch?v=CWmTWxEjZ5A
https://mathschallenge.net/library/number/number_of_divisors
https://brainly.in/question/15254203#:~:text=be%20mentioned%20once.-,Therefore%2C%20the%20factors%20are%201%2C%202%2C%203%2C%204,does%20not%20have%20a%20pair.

*/

// Extracting prime factors of n -->  O(sqrt(n))
bool isPrime(int n)
{
    if (n == 1)
        return false;
    else
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false; // it's not prime
        }

        return true;
    }
}

vector<int> primeFactors(int n)
{
    vector<int> f;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            f.push_back(i);
            n /= i;
        }
    }

    if (n > 1) f.push_back(n); // check if there is a factor greater than sqrt(n)

    return f;
}

// number of factors
int countFactors(int n)
{
    int count = (n == 1)? 1: 2;      // count the first pair of factors : (1) and (n)
    for (int i = 2; i * i <= n; i++) // loop starts from n = 4
    {
        // count the rest of pairs
        if (n % i == 0)
        {
            count++;
            if (i*i != n) count++; // don't double count sqrt(n)
        }
    }
    return count;
}
int countFactors_2(int n)
{
    int ans = 1;
    
    // get power of each prime factor
    // number of factors = (p1 + 1) * (p2 + 1) * .... * (pn + 1)
    for (int i = 2; i * i <= n; i++)
    {
        int power = 0;
        while(n % i == 0)
        {
            power++;
            n /= i;
        }
        if(power) ans *= power + 1;

    }
    if(n > 1) ans *= power + 1;

    return ans;
}

// Get sieve --> O(n*log(n))
// sieve[k] = 0  --> k is prime
// sieve[k] != 0 --> sieve[k] is a prime factor of k
vector<int> sieve(int limit)
{
    vector<int> sieve(limit, 0);
    sieve[0] = sieve[1] = 1;            // take care of 0, and 1
    // for each number(n)
    for (int n = 2; n <= limit; n++)
    {
        // if (n) is prime --> mark multiples of (n) 
        // Example: n = 3 --> mark u = 6, 9, 12, 15... 
        if (!sieve[n])
        {
            // primes.push_back(n);  You can also collect primes
            for (int u = 2 * n; u <= limit; u += n) 
                sieve[u] = n;
        }
    }
    return sieve;
}
vector<long long> sum_of_factors_using_sieve(int limit)
{
    // sieve to compute sum of n factors for all n
    // i=1: add 1 to sum[1], sum[2], sum[3], sum[4], sum[5], sum[6] ...
    // i=2: add 2 to        sum[2],       sum[4],       sum[6] ...
    // i=3: add 3 to               sum[3],       sum[6] ...
    // i=4: add 4 to                     sum[4] ...
    
    vector<long long> sum(limit, 0);
    for (int n = 1; n <= limit; n++) // for each number
    {   
        for (int u = n; u <= limit; u += n) // add it to its multible
        {
            sum[u] += n;
        }
    }
}
