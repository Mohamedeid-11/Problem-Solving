#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        stack<char> brackets;  // we need LIFO

        int n; cin >> n;
        int invalid = 0;

        for(int i=0; i<n; i++)
        {
            char tmp; cin >> tmp;

            if(tmp == '(') brackets.push(tmp);
            else
            {   
                if(brackets.empty()) invalid++;
                else brackets.pop();
            }   
        }

        while (!brackets.empty())
        {
            invalid++;
            brackets.pop();
        }

        cout << invalid << endl;
    }
}