#include <iostream>

using namespace std;

//Codeforces 231A
int main()
{
    //Declare variables for problem & input handling
    int nums{};
    int num{};
    int i_len{};
    int problems{};

    //Get our input length and consume newline
    cin >> i_len;
    cin.ignore();

    //Loop through input length
    while(i_len--)
    {
        //Add numbers to our approval sum
        for(int k{}; k < 3; k++)
            if(cin >> num)
                nums += num;

        if(nums > 1)
            problems ++;
        
        nums = 0;
    }

    //Output problems that the team will implement
    cout << problems;

    return 0;
}