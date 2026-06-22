#include <iostream>
#include <vector>
using namespace std;

//Codeforces Round 1104 Div 1 + 2 | Order Capital Round 2 | Question C
int main()
{
    //Count queries of input as well as initializing loop variable
    int input_count;
    cin >> input_count;

    /*
        Find which value will be the greatest after swaps with all values in front of it.
        We know that once a value reaches the end it will be greater than all preceding values.
        This is because it envelops the sum of all of those values.
        Therefore, we can greedily calculate what would end the largest, and return that.
        This can be done easily by calculating a prefix under the following condition:
        cur <= next ? cur = next : cur += next
    */

    while(input_count--)
    {
        int pile_count, num, i{}, max_val;
        vector<int> piles;
        cin >> pile_count;

        //Take pile input
        for(i; i < pile_count; i++)
        {
            cin >> num;
            piles.push_back(num);
        }

        //Hold our best swapping prefix with default value to be calculated next loop
        long long best_pref = piles[0];

        //Calculate best prefix
        for(i = 0; i < pile_count - 1; i++)
        {
            best_pref = best_pref <= piles[i + 1] ? piles[i + 1] : best_pref + piles[i + 1];
        }

        //Output best outcome
        cout << best_pref << "\n";
    }
    return 0;
}