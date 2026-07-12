//Codeforces Contest 1108 | Division 2 | farmpiggie and Subset Sum (A)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*We are trying to find valid subsequences from 1 to n such that no permutation of that
    sequence with operation value * index (added or subtracted to a sum) will result in a 1
    output. This is actually simple, as we can observe that by greedily using reverse order,
    there is never a case where the sequence can end in 1 because the difference will always be
    either larger than 0 or equal to zero since opposite ends of the sequence cancel out.*/

    int input_length;
    cin >> input_length;

    while(input_length--)
    {
        int num;
        cin >> num;
        num += 1;

        while (--num)
        {
            cout << num << " ";
        }
        cout << "\n";
    }
    
    return 0;
}