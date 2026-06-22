//USACO January 2020 | Bronze Division | Word Processor
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ifstream fin("word.in");
    ofstream fout("word.out");

    //Variable initialization for input handling
    int init_line_size, line_size, word_count;
    string cur_word;

    fin >> word_count >> init_line_size;
    line_size = init_line_size;

    //Go through every character and output systematically
    while(word_count--)
    {
        fin >> cur_word;

        //New line needed, reset line size counter
        if(line_size < cur_word.length())
        {
            fout << endl;
            line_size = init_line_size;
        }
        //Whitespace comes before words, but not at line ends or beginnings
        else if(line_size != init_line_size)
        {
            fout << " ";
        }

        //Done regardless; word flushed to same line if possible, otherwise we are on the next line
        fout << cur_word;
        line_size -= cur_word.length(); //Minus extra character for whitespace

        
    }

    return 0;
}