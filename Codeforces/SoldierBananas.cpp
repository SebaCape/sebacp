#include <iostream>

using namespace std;

int main()
{
    //Input handling and initialization
    int bananas{}, money{}, price{};

    cin >> price;
    cin >> money;
    cin >> bananas;

    //Calculate and output total cost (sum of bananas 1 to n -> n(n+1)/2 times price)
    cout << (price * (bananas * (bananas + 1)) / 2) - money;

    return 0;
}