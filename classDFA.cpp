#include <iostream>
#include "classDFA.h"

#define LIMIT -300

DFA::~DFA()
{
    int i;
    for(i = 0; i < n; i++)
        delete[] t[i];
    delete[] t;
    //cout<<"object is deleted\n";
}

DFA::DFA(unsigned int n, unsigned int m, unsigned int in, unsigned int nf, int **t, vector<int> v) : n(n), m(m), in(in), nf(nf)
{
    int i, j;
    if (t != NULL)
    {
        this->t = new int* [n];
        for (i = 0; i < n; i++)
        {
            this->t[i] = new int[n];
            for (j = 0; j < n; j++)
                this->t[i][j] = t[i][j];
        }
    }
    else
        if(n == 0)
            t = NULL;
        else
        {
            this->t = new int *[n];
            for (i = 0; i < n; i++)
            {
                this->t[i] = new int[n];
                for (j = 0; j < n; j++)
                    this->t[i][j] = LIMIT;
            }
        }
    
    this->v = vector<int>(n);
    for (int i = 0; i < v.size(); i++)
        this->v[i] = v[i];
}

DFA::DFA(const DFA& cop)
{
    this->n = cop.n;
    this->m = cop.m;
    this->in = cop.in;
    this->nf = cop.nf;
    this->v = vector<int>(n);
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
        for (i = 0; i < cop.n; i++)
            this->v[i] = cop.v[i];
    }
    else
        this->t = NULL;
}


void DFA::setn(unsigned int x)      //if we reinitialize the number of nodes in the DFA, we also need to reinitialize the adjacency matrix and the vector used for final states
{
    int i, j;
    this->n = x;

    if(n == 0)
            t = NULL;
    else
    {
        this->t = new int* [n];
        for (i = 0; i < n; i++)
        {
            this->t[i] = new int[n];
            for (j = 0; j < n; j++)
                this->t[i][j] = LIMIT;
        }
    }

    this->v = vector<int>(n);
}

void DFA::setm(unsigned int x)
{
    this->m = x;
}

void DFA::setin(unsigned int x)
{
    this->in = x;
}

void DFA::setnf(unsigned int x)
{
    this->nf = x;
}

void DFA::SetValuesInMatrix(unsigned int i, unsigned int j, char x)
{
    this->t[i][j] = x;
}

void DFA::SetFinalState(unsigned int poz)
{
    if(poz >= n)
    {
        cout<<"Pozitie prea mare\n";
        return;
    }
    this->v[poz] = 1;
}

int DFA::getn() { return n; }

int DFA::getm() { return m; }
        
int DFA::getin() { return in; }
        
int DFA::getnf() { return nf; }

int DFA::GetValueFromMat(unsigned int i, unsigned int j)
{
    return t[i][j];
}

bool DFA::IsFinalState(unsigned int poz)
{
    if(poz >= n)
        return false;
    if(v[poz] == 1)
        return true;
    return false;
}

