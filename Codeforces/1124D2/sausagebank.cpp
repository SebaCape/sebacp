//Codeforces Contest 1124 | Division 2 | Sausage Bank (A)
#include <bits/stdc++.h>
using namespace std;

/*
    We can approach this problem greedily by just letting the money in the bank double until the last
    possible night before we need to start taking, and then take every night after that (since the
    exponentiation of 2 will always grow way faster than summation.)
*/

int main()
{
    int input_length;
    cin >> input_length;

    while(input_length--)
    {
        int n, k;
        cin >> n >> k;

        cout << (1 << (n - k + 1)) + (2 * (k - 1));
        if(input_length)
            cout << "\n";
    }

    return 0;
}