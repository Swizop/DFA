#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "classDFA.h"

using namespace std;

ifstream f("input.txt");
ofstream g("output.txt");

void isaccepted(string, DFA, int, int, vector<int> = vector<int>());

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
        isaccepted(word, d, d.getin(), 0);
    }
    return 0;
}


void isaccepted(string s, DFA d, int state, int p, vector<int> v)       
{
    int i, n = d.getn(), ok = 0;
    v.push_back(state);
    if(p >= s.length())                 ///p = index in string
        if(d.IsFinalState(state))
        {
            g << "DA\nTraseu: ";
            for(i = 0; i < v.size(); i++)
                g << v[i] << " ";
            g << "\n";
        }
        else
            g<<"NU\n";
    else
    {
        for(i = 0; i < n && ok == 0; i++)
            if(d.GetValueFromMat(state, i) == s[p])
            {
                isaccepted(s, d, i, p + 1, v);
                ok = 1;
            }
        if(ok == 0)
            g<<"NU\n";
    }
}