#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//Codeforces Contest 1106 | Division 2 | Another Puzzle From Papyrus (A)
int main()
{
    int input_len;
    cin >> input_len;

    /*
        We want to convert some input array A to some target array B. The only operations we can do
        are to sort the array in C seconds, or decrement some element by 1 in one second. To solve
        this we need to find the shortest time to reach our target.
        We cannot reach our target if some element a (- A < b (- B, where b is the minimal element.

        We can solve this by:
        1. Checking input validity to reach target
        2. Simulating cost to sort then subtract, and just subtract outright
        3. Picking the lower cost
    */

    while(input_len--)
    {
        //Input handling
        int n, c, cur;
        cin >> n >> c;

        vector<int> start, target;

        //Populate vectors
        for(int i{}; i < n; i++)
        {
            cin >> cur;
            start.push_back(cur);
        }
        for(int i{}; i < n; i++)
        {
            cin >> cur;
            target.push_back(cur);
        }

        //Check if input can be subtracted straight (already ordered)
        bool can_sub = true, is_valid = true;
        for(int i{}; i < n; i++)
        {
            if(start[i] < target[i])
            {
                can_sub = false;
                break;
            }
        }

        //Calculate both costs
        int sub_only_cost{}, sort_sub_cost{c};

        //Subtraction only
        if(can_sub)
            for(int i{}; i < n; i++)
                sub_only_cost += start[i] - target[i];
            
        //Sort then subtraction (validity of answer checked here
        sort(start.begin(), start.end());
        sort(target.begin(), target.end());

        for(int i{}; i < n; i++)
        {
            if(start[i] < target[i])
            {
                is_valid = false;
                break;
            }
            sort_sub_cost += start[i] - target[i];
        }

        //Determine output
        if(is_valid)
        {
            if(can_sub)
                cout << min(sub_only_cost, sort_sub_cost) << endl;
            else 
                cout << sort_sub_cost << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}