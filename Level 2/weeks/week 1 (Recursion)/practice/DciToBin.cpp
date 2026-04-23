#include <bits/stdc++.h>
using namespace std;

// decimal to binary using recursion
string dciToBin(int decimal, string resualt)
{
    if (decimal == 0)
        return resualt;

    resualt += (decimal % 2 + '0');
    return dciToBin(decimal / 2, resualt);
}

int main()
{
    cout << dciToBin(233, "");
}
