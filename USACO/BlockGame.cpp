//USACO 2016 December Contest | Bronze Division | Block Game
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //File IO
    ifstream fin("blocks.in");
    ofstream fout("blocks.out");

    /*
        just count the letters
    */

    int n;
    string s1, s2;
    vector<int> letters(26), freq1(26), freq2(26);
    fin >> n;

    while(n--)
    {
        fin >> s1 >> s2;
        for(char ch : s1)
            freq1[ch - 97] += 1;
        for(char ch : s2)
            freq2[ch - 97] += 1;

        //Add max freq count between the two strings
        for(int i{}; i < 26; i++)
            letters[i] += freq1[i] > freq2[i] ? freq1[i] : freq2[i];

        fill(freq1.begin(), freq1.end(), 0);
        fill(freq2.begin(), freq2.end(), 0);
    }

    for(int count : letters)
    {
        fout << count << "\n";
    }

    return 0;
}