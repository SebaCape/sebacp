#include <iostream>
#include <vector>
using namespace std;

//Codeforces Round 1104 Div 1 + 2 | Order Capital Round 2 | Question A
int main()
{
    //Count queries of input as well as initializing loop variable
    int input_count, ct{};
    vector<int> output;
    cin >> input_count;

    while(ct < input_count)
    {
        //Count nums to create iterate through input, initialize sum and last minimum variable
        int num_count, height_sum{}, last_min, num;
        cin >> num_count;
        cin >> last_min;
        height_sum += last_min; //Handles first value (never need to worry about 0 value)

        for(int i{1}; i < num_count; i++)
        {
            //Check next value for min update, increment height sum
            cin >> num;
            if(num < last_min)
                last_min = num;
            height_sum += last_min;
        }

        //Add our best possible height to vector and move to next case
        output.push_back(height_sum);
        ct++;
    }

    for(int item : output)
        cout << item << "\n";

    return 0;
}