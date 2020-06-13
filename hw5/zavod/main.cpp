#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

int damerau(std::string& s, std::string& t)
{
    size_t n = s.length() + 1;
    size_t m = t.length() + 1;
    int d[n][m];

    for (int i = 0; i < n; ++i)
        d[i][0] = i;

    for (int j = 0; j < m; ++j)
        d[0][j] = j;

    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j)
        {
            d[i][j] = std::min(std::min(d[i - 1][j] + 1,
                                        d[i][j - 1] + 1),
                               d[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? 0 : 1));
            if (d[i][j] > 11)
                return d[i][j];
        }

    return d[n - 1][m - 1];
}

int findPossibleCommandCount(std::string& userCommand, std::string* commands, int max, int n)
{
    int res = 0;

    for (int i = 0; i < n; ++i)
        if (damerau(userCommand, commands[i]) <= max)
            ++res;

    return res;
}

int main(int argc, const char* argv[])
{
    int n, d, k;
    std::string* correctCommands;
    std::fstream fin;
    std::fstream fout;

    fin.open("input.txt", std::ios::in);
    fout.open("output.txt", std::ios::out);

    if (fin.is_open())
    {
        std::string str;

        getline(fin, str);
        n = stoi(str);
        correctCommands = new std::string[n];
        for (int i = 0; i < n; i++)
        {
            getline(fin, str);
            correctCommands[i] = str;
        }

        getline(fin, str);
        d = stoi(str);

        getline(fin, str);
        k = stoi(str);
        for (int i = 0; i < k; ++i)
        {
            getline(fin, str);
            fout << findPossibleCommandCount(str, correctCommands, d, n) << (i == k - 1 ? "" : "\n");
        }

        fout.close();
        fin.close();

        delete[] correctCommands;
    }

    return 0;
}