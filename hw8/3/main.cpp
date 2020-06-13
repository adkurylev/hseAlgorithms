#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string assemble_LCS(std::string& x, std::string& y, std::vector<std::vector<int>>& l, int i, int j)
{
    if (l[i][j] == 0)
        return "";
    if (x[i - 1] == y[j - 1])
        return assemble_LCS(x, y, l, i - 1, j - 1) + x[i - 1];
    if (l[i - 1][j] < l[i][j - 1])
        return assemble_LCS(x, y, l, i, j - 1);
    else
        return assemble_LCS(x, y, l, i - 1, j);

}

std::string getLCS(std::string& x, std::string& y)
{
    int m = x.length();
    int n = y.length();

    std::vector<std::vector<int>> lcs(m + 1);

    for (int i = 0; i < m + 1; ++i)
        lcs[i] = std::vector<int>(n + 1);

    for (int i = 1; i < m + 1; ++i)
        for (int j = 1; j < n + 1; ++j)
        {
            if (x[i - 1] == y[j - 1])
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            else
                lcs[i][j] = std::max(lcs[i - 1][j], lcs[i][j - 1]);
        }

    return assemble_LCS(x, y, lcs, m, n);
}

int main()
{
    std::string x;
    std::string y;
    std::string res;

    std::ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        getline(fin, x);
        getline(fin, y);
        fin.close();
    }

    res = getLCS(x, y);

    std::fstream fout;
    fout.open("output.txt", std::ios::out);
    fout << res;
    fout.close();

    return 0;
}