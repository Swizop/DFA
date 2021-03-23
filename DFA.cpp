#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "classDFA.h"

using namespace std;

ifstream f("input.txt");

int main()
{
    DFA d;
    int x, i, y;
    char q;
    string word;
    
    f>>x;           //READ number of nodes
    d.setn(x);

    f>>x;           //nr of transitions
    d.setm(x);
    
    for(i = 1; i <= d.getm(); i++)      //transitions
    {
        f >> x >> y >> q;
        d.SetValuesInMatrix(x, y, q);
    }

    f >> x;         //initial state
    d.setin(x);

    f >> x;         //nr of final states
    d.setnf(x);
    for(i = 1; i <= d.getnf(); i++)     //final states
    {
        f >> x;
        d.SetFinalState(x);
    }


    f >> x;         //nr of strings
    getline(f, word);
    for(i = 1; i <= x; i++)         //read strings
    {
        getline(f, word);
    }
    return 0;
}