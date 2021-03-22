#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DFA {
    int n, m, in, nf;   //n = number of nodes, m = number of transitions, in = initial state, nf = nr of final states
    int** t;            //adjacency matrix
    vector<int> v;      //final states

    public:
        DFA(int n = 0, int m = 0, int in = 0, int nf = 0, int **t = NULL, vector<int> v = vector<int>()) : n(n), m(m), in(in), nf(nf)
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
        ~DFA();
        DFA(const DFA&);
};


int main()
{
    DFA d;
    
    return 0;
}


DFA::~DFA()
{
    int i;
    for(i = 0; i < n; i++)
        delete[] t[i];
    delete[] t;
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