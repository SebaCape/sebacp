//Codeforces Contest 1125 | Division 3 | In Search of Convenience (A)
#include <bits/stdc++.h>
using namespace std;

/*Just add z to one of our coordinates and it will be an extra z units away from our start.*/

int main()
{

    int input_length;
    cin >> input_length;
    vector<pair<int, int>> output;

    while(input_length--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        pair<int, int> coordinate = {x, y + z};
        output.push_back(coordinate);
    }

    for(pair<int, int> c : output)
    {
        cout << c.first << " " << c.second << "\n";
    }

    return 0;
}