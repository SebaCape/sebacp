#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ifstream fin("teleport.in");
    ofstream fout("teleport.out");

    string line;
    vector<int> nums;
    int num;

    if(getline(fin, line))
    {
        istringstream iss(line);
        while(iss >> num)
            nums.push_back(num);
    }

    if(nums.size() < 4) {
        return 0; 
    }

    fout << min({
        abs(nums[1] - nums[0]), 
        abs(nums[0] - nums[2]) + abs(nums[1] - nums[3]),  
        abs(nums[0] - nums[3]) + abs(nums[1] - nums[2])
    }) << endl;

    return 0;
}