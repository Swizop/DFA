#pragma once
#include <iostream>
#include <vector>
using namespace std;
class DFA {
    int n, m, in, nf;   //n = number of nodes, m = number of transitions, in = initial state, nf = nr of final states
    int** t;            //adjacency matrix
    vector<int> v;      //final states

    public:
        DFA(int = 0, int = 0, int = 0, int = 0, int** = NULL, vector<int> = vector<int>());
        ~DFA();
        DFA(const DFA&);
};