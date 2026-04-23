#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> super_Lucky_nums;

// generate super lucky numbers up to 10 digits
void SuperLucky(string current, int fours, int sevens)
{
    if (fours == sevens && !current.empty())
    {
        super_Lucky_nums.push_back(stoll(current));
    }

    if (current.length() > 10)
        return;

    SuperLucky(current + "4", fours + 1, sevens);
    SuperLucky(current + "7", fours, sevens + 1);
}

int main()
{
    long long n;
    cin >> n;
    SuperLucky("", 0, 0);

    sort(super_Lucky_nums.begin(), super_Lucky_nums.end());

    for (long long number : super_Lucky_nums)
    {
        if (number >= n)
        {
            cout << number << endl;
            break;
        }
    }

    return 0;
}