//Codeforces Contest 1109 | Division 3 | Minus Two (B)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*We want to find the maximum number frequency we can make by subtracting two from an array
    of arbitrary values. We can just simulate the maximum subtraction until our solution space
    stabilizes, and then count equal values. (possibilities are 0, 1, 2) In fact, simulation is
    not actually needed, as we can just check the mod 2 and 4 results to determine our remainder.*/

    int input_length;
    cin >> input_length;
    vector<int> output;

    while(input_length--)
    {
        int nums_length;
        cin >> nums_length;
        int zeros{}, ones{}, twos{};

        while(nums_length--)
        {
            int num;
            cin >> num;
            if(num % 4 == 0)
                zeros++;
            else if(num % 2 == 0)
                twos++;
            else
                ones++;
        }

        output.push_back(max({zeros, ones, twos}));
    }

    for(int element : output)
        cout << element << "\n";

    return 0;
}