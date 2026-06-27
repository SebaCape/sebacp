#include <iostream>
#include <cmath>
#include <set>
#include <bit>
using namespace std;

//Codeforces Contest 1105 | Division 2 | Another Popcount Problem (A)
int main()
{
    /*
        We want to find the best way to split a number such that it has as many bits as possible.
        This can be achieved greedily by summing the number using the greatest powers 2^k - 1 that
        it bounds above, and then using the remainder when necessary. Note that if a number
        is greater than our input divided by the amount of partitions left, then we cannot use it.
    */
    int input_len;
    cin >> input_len;
    set<long long> two_pows; //Keep set of powers of two - 1

    //Populate set
    for(int i{1}; i < 32; i++)
    {
        two_pows.insert(pow(2, i) - 1);
    }

    while(input_len--)
    {
        //Take in input for our number to calculate popcount and for how many splits
        long long num, partitions, bit_count{};
        cin >> num >> partitions;

        //Edge case: Too many partitions
        if(num <= partitions)
        {
            cout << num << "\n";
            continue;
        }

        while(partitions > 0)
        {
            //Get best element (number before value that bounds above our value)
            long long best_num = *prev(two_pows.upper_bound(num / partitions));

            //Increment bit count accordingly and update inputs
            num -= best_num;
            bit_count += __popcount(best_num);
            partitions--;
        }

        cout << bit_count << "\n";
    }

    return 0;
}