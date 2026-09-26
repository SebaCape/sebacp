//Codeforces Contest 1124 | Division 2 | K is Important (C)
#include <bits/stdc++.h>
using namespace std;

/*Essentially this question asks us to greedily pick the max from pairs at the edge of our array and
then sum the middle elements as well given that they are reachable (if k - 1 <= n - k + 1.)*/

int main()
{
    int input_length;
    cin >> input_length;

    vector<long long> output;

    while(input_length--)
    {
        //Calculate indices of interest and populate vector of nums
        int n, k;
        cin >> n >> k;
        int other_spot = n - k;
        int temp_n = n;

        //arr is one indexed
        vector<long long> arr(n + 1);
        int ct = 1;

        while(temp_n--)
        {
            int num;
            cin >> num;
            arr[ct] = num;
            ct++;
        }

        //Calculate the amount of pairs to keep track of and sum
        int pair_length = min(k - 1, n - k + 1);
        long long max_sum{};

        //Pick the best pairwise value at each step
        for (int l = 1; l <= pair_length; l++) 
        {
            int r = n + 1 - l;
            max_sum += max(arr[l], arr[r]);
        }

        //Given that the middle is reachable, add its values to our sum
        if (k - 1 <= n - k + 1) {
            for (int m = pair_length + 1; m <= n - pair_length; m++)
                max_sum += arr[m];
        }

        output.push_back(max_sum);
    }

    //Print output to console
    for(int o{}; o < output.size(); o++)
    {
        cout << output[o];
        if(o != output.size() - 1)
            cout << "\n";
    }

    return 0;
}