#include <iostream>

using namespace std;

//Codeforces 546A
int main()
{
    //Input handling and initialization
    int bananas{}, money{}, price{};

    cin >> price >> money >> bananas;

    //Calculate and output total cost (sum of bananas 1 to n -> n(n+1)/2 times price) or 0 if negative money needed to borrow
    int borrow = price * (bananas * (bananas + 1) / 2) - money;

    if(borrow < 0)
        cout << 0;
    else
        cout << borrow;

    return 0;
}