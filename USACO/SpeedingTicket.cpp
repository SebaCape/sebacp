//USACO 2015 December Contest | Bronze Division | Speeding Ticket
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //File IO
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");

    /*
        We are given stretches of roads with speed limits, and then stretches of road at which
        a certain speed was traveled. We want to find the largest speed limit exceeding that
        happened at any point of the journey. This can be done by tracking stretches of road to
        corresponding speed limit, and then just checking against it with our actual speed and
        holding the running minimum.
    */

    //Count road segments and travel segments
    int n, m;
    fin >> n >> m;
    vector<int> seg_lengths, seg_limits;

    //Track speed limits for each stretch of road
    for(int i{}; i < n; i++)
    {
        int le, li;
        fin >> le >> li;
        seg_lengths.push_back(le);
        seg_limits.push_back(li);
    }
    
    //Compare against our actual travels
    int max_violation{}, speed, stretch, idx{};
    fin >> stretch >> speed;

    while(idx < n)
    {
        //If our stretch has been traveled, update inputs
        if(stretch <= 0)
            fin >> stretch >> speed;

        //Simulate traveling a specific stretch of road
        int temp = stretch;
        stretch -= seg_lengths[idx];
        seg_lengths[idx] -= temp;

        //Set max violation if necessary
        max_violation = max(max_violation, speed - seg_limits[idx]);

        //Move index forwards to next segment if passed
        if(seg_lengths[idx] <= 0)
            idx++;
    }

    fout << max_violation;

    

    return 0;
}