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
    ifstream fin("promote.in");
    ofstream fout("promote.out");

    //Declare start and end values for each rank and populate
    int bs, bf, ss, sf, gs, gf, ps, pf; 
    fin >> bs >> bf >> ss >> sf >> gs >> gf >> ps >> pf;

    //Calculate counts for bronze -> silver -> gold -> platinum promotions (end - start of all superceding leagues)
    int gtp = pf - ps;
    int stg = gtp + gf - gs;
    int bts = stg + sf - ss;

    //Output results
    fout << bts << "\n" << stg << "\n" << gtp;

    return 0;
}