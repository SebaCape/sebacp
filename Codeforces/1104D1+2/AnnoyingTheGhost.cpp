#include <iostream>
#include <vector>
#include <set>
using namespace std;

//Codeforces Round 1104 Div 1 + 2 | Order Capital Round 2 | Question B
int main()
{
    //Count queries of input as well as initializing loop variable
    int input_count;
    cin >> input_count;

    /*
        We need to first determine every number to increase to one of our target values. Then, we
        shall count the amount of inversions needed to reach our target sequence, combined with
        ensuring validity of our sequence. This can be done using a set, and two vectors.
    */

    while(input_count--)
    {
        //Set up initial input handling & bookkeeping vars
        vector<int> start_piles, target_piles;
        set<int> target_set;
        int pile_count, i{}, num;
        bool is_valid = true;

        cin >> pile_count;

        for(i; i < pile_count; i++)
        {
            cin >> num;
            start_piles.push_back(num);
        }
        for(i = 0; i < pile_count; i++)
        {
            cin >> num;
            target_piles.push_back(num);
            target_set.insert(num); //We also append to our set as well for start pile increases
        }

        //Begin stage one operations on our initial sequence of piles
        for(i = 0; i < pile_count; i++)
        {
            //Track our pile that we are comparing against as well as our lower bound of our target set (iterator)
            auto cur_pile = start_piles[i];
            auto low_bound = target_set.lower_bound(cur_pile);

            //We check if there is a value within our set that we can increment this pile size up to
            if(low_bound != target_set.end())
            {
                start_piles[i] = *low_bound;
                target_set.erase(low_bound);
            }
            //If there is no valid value we can raise our current pile to, then -1 is output
            else
            {
                is_valid = false;
                break;
            }
        }

        //Move to phase two and calculate inversions from start to target if valid, otherwise output -1
        if(is_valid)
        {
            int inversions = 0;

            for(i = 0; i < pile_count - 1; i++)
            {
                int idx{i + 1};
                while(idx < pile_count)
                {
                    if(start_piles[i] > start_piles[idx])
                        inversions++;
                    idx++;
                }
            }
            cout << inversions << "\n";
        } //NOTE: Validity checking is O(N^2), can be reduced to O(nlogn) but unecessary because of problem bounds
        else
        {
            cout << -1 << "\n";
            continue;
        }
    }
    return 0;
}