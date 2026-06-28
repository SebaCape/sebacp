#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

//Codeforces Contest 1106 | Division 2 | Crimson Triples
int main()
{
    /*
        Given some integer input n, we want to find how many triples exist such that choosing 
        integers a, b, and c such that 1 <= a, b, c <= n, and that gcd(lcm(a,b),lcm(b,c)) = gcd(a,c).
        We know that  gcd(lcm(a,b),lcm(b,c)) = lcm(b, gcd(a, c)) due to distribution of least common 
        multiples. We can represent the possible values of b using the sequence that sums all numbers
        (n / i)^2 where i starts at 1.
    */

    int input_len;
    cin >> input_len;

    while(input_len--)
    {
        long long valid_gcds{}, n;
        cin >> n;

        for(int i = 1; i <= n; i++)
            valid_gcds += (n / i) * (n / i);

        cout << valid_gcds << "\n";
    }

    return 0;
}