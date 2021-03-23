#include <iostream>
#include "classDFA.h"

DFA::~DFA()
{
    int i;
    for(i = 0; i < n; i++)
        delete[] t[i];
    delete[] t;
    //cout<<"object is deleted\n";
}

DFA::DFA(int n, int m, int in, int nf, int **t, vector<int> v) : n(n), m(m), in(in), nf(nf)
{
    if (t != NULL)
    {
        int i, j;
        this->t = new int *[n];
        for (i = 0; i < n; i++)
            this->t[i] = new int[n];
        for (j = 0; j < n; j++)
            this->t[i][j] = t[i][j];
    }
    if (v.size() > 0)
    {
        for (int i = 0; i < v.size(); i++)
            this->v.push_back(v[i]);
    }
}

DFA::DFA(const DFA& cop)
{
    this->n = cop.n;
    this->m = cop.m;
    this->in = cop.in;
    this->nf = cop.nf;
    if(cop.t != NULL)
    {
        int i, j;
        this->t = new int* [n];
        for(i = 0; i < n; i++)
        {
            this->t[i] = new int [n];
            for(j = 0; j < n; j++)
                this->t[i][j] = cop.t[i][j];
        }
        for(i = 0; i < cop.v.size(); i++)
            this->v.push_back(cop.v[i]);
    }
}

