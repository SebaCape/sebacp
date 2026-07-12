//Codeforces Contest 1108 | Division 2 | ezraft and Array (B)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*We want to find if a valid sum exists in a sequence of number such that all numbers used in
    our sequence divide the sum. This can be done simply using a multiplicatively increasing
    sequence (1, 2, 3, 6, 12...), with the one caveat that we have to watch out for N = 2, as there
    is no way to have a valid sequence for that with distinct integers (one number would be larger
    than half the sum making it impossible.)*/

    int input_length;
    cin >> input_length;

    while(input_length--)
    {
        vector<long long> sequence{1, 2};
        int num;
        cin >> num;

        //Populate sequence vector
        for(int i{2}; i < 50; i++)
            sequence.push_back(accumulate(sequence.begin(), sequence.end(), 0LL));


        if(num == 2)
        {
            cout << -1 << "\n";
        }
        else
        {
            int i = 0;
            while(num--)
            {
                cout << sequence[i] << " ";
                i++;
            }
            cout << "\n";
        }
    }

    return 0;
}