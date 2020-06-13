#include "BigIntegerAlgorithms.hh"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

int globalK;

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

static void solve(vector<int>& permutation, vector<bool>& used, vector<int>& result, int t, int n, int m)
{
    for (int i = 1; i <= n; ++i)
    {
        if (!used[i - 1])
        {
            used[i - 1] = true;
            permutation[t] = i;

            if (globalK == 0)
                return;
            if (t < m - 1)
                solve(permutation, used, result, t + 1, n, m);
            else
            {
                globalK--;
                result = permutation;
            }

            used[i - 1] = false;
        }
    }
}

//Необходимо реализовать данный метод
//Вся информация о задаче доступна в тексте задачи и в слайдах презентации к семинару(в ЛМС)
static string get(int n, int k, int m)
{
    vector<int> result = vector<int>();
    vector<bool> used = vector<bool>(n);
    vector<int> permutation = vector<int>(m);
    globalK = k;

    solve(permutation, used, result, 0, n , m);

    return vector_to_string(result);
}

int main(int argc, const char* argv[])
{
    int M, N, K;
    fstream fin;
    fstream fout;
    fin.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    if (fin.is_open())
    {
        string str;
        getline(fin, str);
        N = atoi(str.c_str());
        getline(fin, str);
        K = atoi(str.c_str());
        getline(fin, str);
        M = atoi(str.c_str());
        fout << get(N, K, M) << endl;

        fout.close();
        fin.close();
    }
    return 0;
}