#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

//Codeforces 2048B
int main()
{
    //Parse input length for number of queries to compute
    int input_length, ct{};
    cin >> input_length;

    /*
        To minimize the sum of all subarray minimums, we can just choose a min value from our range,
        and then append it only when our current output index is divisible by the size of subarrays
        we desire. This ensures accurate spreading of minimums.
    */
    while(ct < input_length)
    {
        //Parse input for subarray size and element range
        int range, sub_size;
        cin >> range >> sub_size;

        //Vectors for range and output, as well as left and right pointers for subarray population
        vector<int> range_vec(range), output;
        int l{}, r{range - 1};

        //Use std::iota to initialize range of values in vector
        iota(range_vec.begin(), range_vec.end(), 1);

        //Initialize index count to keep track for adding a max
            int idx{1}; //Note the 1 indexed start to make remainder checking easier 

        //Populate our output vector optimally
        while(l <= r)
        {
            //Check condition to add left or right value (if our current index is divisible by subarray size)
            if(idx % sub_size == 0)
            {
                output.push_back(range_vec[l]);
                l++;
            }
            else
            {
                output.push_back(range_vec[r]);
                r--;
            }

            idx++;
        }
        //Print output vector
        for(int item : output)
            cout << item << " ";
        cout << "\n";
        ct++;
    }

    return 0;
}