//USACO 2019 Open | Bronze Division | Bucket Brigade
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
    //File IO
    ifstream fin("buckets.in");
    ofstream fout("buckets.out");

    //Declare coordinate storing variables for each key object 
    int barn_row, barn_col, lake_row, lake_col, rock_row, rock_col;
    char ch;

    /*
        We can calculate distance by checking row and column differences between barn and lake.
        If the rock is on the same row as both or column as both, two extra cows are needed.
        Note that BFS is not necessary here as there is only one source and destination which
        always have a valid path.
    */

    //Parse input and find coordinates of key values
    for(int r{}; r < 10; r++)
    {
        for(int c{}; c < 10; c++)
        {
            fin >> ch;
            switch(ch)
            {
                case 'B':
                    barn_col = c;
                    barn_row = r;
                    break;
                case 'L':
                    lake_col = c;
                    lake_row = r;
                    break;
                case 'R':
                    rock_col = c;
                    rock_row = r;
                    break;
            }
        }
    }

    //Base answer calculation
    int distance{abs(barn_col - lake_col) + abs(barn_row - lake_row) - 1};

    //Conditional check for extra cows given that obstacle resides on the same line
    if((barn_col == rock_col && rock_col == lake_col && ((barn_row < rock_row && rock_row < lake_row) || (lake_row < rock_row && rock_row < barn_row))) 
    || barn_row == rock_row && rock_row == lake_row && ((barn_col < rock_col && rock_col < lake_col) || (lake_col < rock_col && rock_col < barn_col)))
        distance += 2;

    //Output distance
    fout << distance;

    return 0;
}