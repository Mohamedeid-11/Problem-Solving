#include <iostream>
#include <cmath>
using namespace std;

bool hasNoDecimal(double x)
{
    double integer_part = trunc(x);
    return abs(x - integer_part) < (1e-9) || abs(x - integer_part) > (1 - 1e-9);
}

int main()
{
    double x = 10000000.0000000;
    double y = 10000000.0000001;
    cout << hasNoDecimal(x) << ' ' << hasNoDecimal(y) << endl;
}