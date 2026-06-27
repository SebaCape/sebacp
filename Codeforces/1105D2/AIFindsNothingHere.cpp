#include <iostream>
using namespace std;

//Codeforces Contest 1105 | Division 2 | AI Finds Nothing Here (B)

//Helper function for safe binary exponentiation w/o overflow
long long mod_pow(long long base, long long exp, long long mod)
{
    long long result = 1;
    base %= mod;

    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp >>= 1;
    }

    return result;
}

int main()
{
    /*We want to find the possible amount of matrices such that submatrices of size r x c will always
    have their bitwise xor sum equal to 0 (where all elements are binary digits). We can count how
    many submatrices can fit in our main matrix via (n - r - 1) * (m - c - 1), and then populate our
    first submatrix arbitrarily. Every sub matrix after that will can be made to have a xor sum of 0 using 
    direct curation. Because of this, we can then calculate our final outcomes as  
    2^(nm - (n - r - 1)(m - c - 1))*/

    int input_len;
    const long long MOD = 998244353;
    cin >> input_len;

    while (input_len--)
    {
        long long n, m, r, c; //n -> rows, m -> cols, r & c -> rows and cols for submatrices
        cin >> n >> m >> r >> c;

        //Calculate how many submatrices can fit within our main matrix
        long long sub_mat_fit{(n - r + 1) * (m - c + 1)};
        //Calculate how many subsequent parent matrix possibilities can exist because of this
        long long possibilidades{mod_pow(2, n * m - sub_mat_fit, MOD)};

        cout << possibilidades % MOD << "\n";
    }

    return 0;
}

