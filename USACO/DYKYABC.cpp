//USACO 2016 | Bronze Division | Promotion Counting
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
    //Collect all inputs into a vector
    vector<int> expressions;
    int num;

    while(cin >> num)
        expressions.push_back(num);

    //When we sort our expressions, we know that the greatest (A + B + C) will come last
    //And the smallest (A, B) will come first, allowing us to derive our solution
    sort(expressions.begin(), expressions.end());

    //Output A B and C
    cout << expressions[0] << " " << expressions[1] << " " << expressions[expressions.size() - 1] - expressions[0] - expressions[1];

    return 0;
}