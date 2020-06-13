//#include "BigIntegerAlgorithms.hh"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

static string vector_to_string(vector<int>& vector)
{
    string res;
    for (int i = 0; i < vector.size(); ++i)
    {
        res += to_string(vector[i]);
        if (i != vector.size() - 1)
            res += " ";
    }
    return res;
}

static void increase(vector<int>& combination, int j)
{
    ++combination[j];
    for (int i = j; i < combination.size() - 1; ++i)
        combination[i + 1] = combination[i] + 1;
}

//Необходимо реализовать данный метод
//Вся информация о задаче доступна в тексте задачи и в слайдах презентации к семинару(в ЛМС)
static string get(int N,int k, int m)
{
    vector<int> combination = vector<int>(m);
    for (int i = 0; i < m; ++i)
        combination[i] = i + 1;

    for (int i = 1; i < k; ++i)
    {
        if (combination[m - 1] < N)
            increase(combination, m - 1);
        else
            increase(combination, m - 2);
    }

    return vector_to_string(combination);
}

int main(int argc, const char * argv[]) 
{
    int M,N,K;
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
        getline(fin,str);
        M = atoi( str.c_str());
        fout << get(N, K, M)<< endl;
         
        fout.close();
        fin.close();
    }
    return 0;
}