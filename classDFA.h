#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class DFA {
    int n, m, in, nf;   //n = number of nodes, m = number of transitions, in = initial state, nf = nr of final states
    int** t;            //adjacency matrix
    vector<int> v;      //final states

    public:
        DFA(unsigned int = 0, unsigned int = 0, unsigned int = 0, unsigned int = 0, int** = NULL, vector<int> = vector<int>());
        ~DFA();
        DFA(const DFA&);
        void setn(unsigned int);
        void setm(unsigned int);
        void setin(unsigned int);
        void setnf(unsigned int);
        void SetValuesInMatrix(unsigned int, unsigned int, char);
        void SetFinalState(unsigned int);
        int getn();
        int getm();
        int getin();
        int getnf();
        int GetValueFromMat(unsigned int, unsigned int);
        bool IsFinalState(unsigned int);
};