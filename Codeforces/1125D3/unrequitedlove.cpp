//Codeforces Contest 1125 | Division 3 | Unrequited Love (C)
#include <bits/stdc++.h>
using namespace std;

/*We are trying to maximize pairs of distinct triads that have the same sum in an array (given
some rules on computation.) To do this we can just compute triad sums at each index, keep a
running count of their occurrences, and cut any triads that share the same note (denoted by 
an index difference of 2 or 4.)*/

int main()
{

    int input_length;
    cin >> input_length;
    vector<long long> output;

    while(input_length--)
    {
        vector<long long> triad_sums, values;
        int n;
        cin >> n;

        while(n--)
        {
            long long cur_num;
            cin >> cur_num;
            values.push_back(cur_num);
        }

        for(int i{}; i < (int)values.size() - 4; i++)
        {
            triad_sums.push_back(values[i] + values[i + 2] - values[i + 4]);
        }

        unordered_map<long long, set<int>> dupes;
        long long total{};

        for(int i{}; i < triad_sums.size(); i++)
        {
            if(dupes.find(triad_sums[i]) != dupes.end())
            {
                total += dupes[triad_sums[i]].size();
                if(dupes[triad_sums[i]].find(i - 2) != dupes[triad_sums[i]].end())
                    total -= 1;
                if(dupes[triad_sums[i]].find(i - 4) != dupes[triad_sums[i]].end())
                    total -= 1;
            }
            dupes[triad_sums[i]].insert(i);
        }

        output.push_back(total);
    }

    for(long long el : output)
        cout << el << "\n";

    return 0;
}