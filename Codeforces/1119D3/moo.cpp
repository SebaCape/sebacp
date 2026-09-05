//Codeforces Contest 1109 | Division 3 | Moo Language School (A)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    /*We want to check if we can place "farms" in n/k segments of our arrays and how many
    of those segments have now zeroes.*/

    int input_length;
    cin >> input_length;

    while(input_length--)
    {
        int n, k;
        cin >> n >> k;
        string fields;
        cin >> fields;

        bool can_place = false;
        int count{};

        for(int i = 1; i <= n; i++)
        {
            if(fields[i - 1] == '0')
                can_place = true;

            if(i % k == 0)
            {
                if(!can_place)
                    count++;
                can_place = false;
            }
        }

        cout << count << "\n";
    }

    return 0;
}