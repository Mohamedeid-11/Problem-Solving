    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        map<int, int, greater<int>> buy, sell;

        int n, s;
        cin >> n >> s;
        while(n--)
        {
            char type;
            int price, num;
            cin >> type >> price >> num;

            if(type == 'B') buy[price] += num;
            else sell[price] += num;
        }
        
        int excess_values = max(0, (int)sell.size() - s);    //so we take (at most) s prices, otherwise get all the sell map
        int map_index = -1;
        for(auto [price, num] : sell) 
        {
            map_index++;                                     // update index before continue so they don't inturrpt with each other (if index stopped being updated we will skip all pairs)
            if(map_index < excess_values) continue;          // skip the excess if any then print the rest of sell
            cout << "S " << price << ' ' << num << '\n';
        }
        map_index = -1;
        for(auto [price, num] : buy)
        {
            map_index++;
            if(map_index == s) break;
            cout << "B " << price << ' ' << num << '\n';
        }
    }