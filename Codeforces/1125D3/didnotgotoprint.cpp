//Codeforces Contest 1125 | Division 3 | Did Not Go To Print (B)
#include <bits/stdc++.h>
using namespace std;

/*We can just simulate prints with a stack and vector, tracking which documents never go to print
based on our input. Combine these collections at the end and print them in ascending order for our
result.*/

int main()
{

    int input_length;
    cin >> input_length;

    while(input_length--)
    {
        int n;
        cin >> n;
        string instructions;
        cin >> instructions;
        vector<int> output;
        stack<int> stk;

        for(int i{}; i < n; i++)
        {
            if(instructions[i] == '1')
                stk.push(i);
            else if(instructions[i] == '2')
            {
                if(!stk.empty())
                {
                    stk.pop();
                    output.push_back(i);
                }
            }
        }

        while(!stk.empty())
        {
            output.push_back(stk.top());
            stk.pop();
        }
        sort(output.begin(), output.end());

        cout << output.size() << "\n";
        for(int i{}; i < output.size(); i++)
        {
            cout << output[i] + 1;
            if(i == output.size() - 1)
                cout << "\n";
            else
                cout << " ";
        }
    }

    return 0;
}