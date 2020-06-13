//#include "BigIntegerAlgorithms.hh"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

int globalK;

static string vector_to_string(vector<int>& v)
{
    string str;
    for (int i = 0; i < v.size(); ++i)
    {
        str += to_string(v[i]);
        if (i != v.size() - 1)
            str += " ";
    }
    return str;
}

static void solve(vector<int>& permutation, vector<bool>& used, vector<int>& result, int t, int n)
{
    for (int i = 1; i <= n; ++i)
    {
        if (!used[i - 1])
        {
            used[i - 1] = true;
            permutation[t] = i;

            if (globalK == 0)
                return;
            if (t < n - 1)
                solve(permutation, used, result, t + 1, n);
            else
            {
                globalK--;
                result = permutation;
            }

            used[i - 1] = false;
        }
    }
}

static string get_day(int N,int k)
{
    vector<int> result = vector<int>();
    vector<bool> used = vector<bool>(N);
    vector<int> permutation = vector<int>(N);
    globalK = k;

    solve(permutation, used, result, 0, N);

    return vector_to_string(result);
}

int main(int argc, const char * argv[]) {

    int N,K;
    fstream fin;
    fstream fout;
    fin.open("input.txt",ios::in);
    fout.open("output.txt",ios::out);
    if(fin.is_open()) {
        string str;
        getline(fin,str);
        N = atoi( str.c_str());
 
        getline(fin,str);
        K = atoi( str.c_str());
         fout << get_day(N,K)<< endl;
       
        fout.close();
        fin.close();
    }
    
    return 0;
}
