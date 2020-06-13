#include <iostream>
#include <fstream>
#include <vector>

bool getEl(int i, bool* f)
{
    if (i < 0)
        return false;

    return f[i];
}

bool getSum(int i, bool* f, int a, int b, int c)
{
    bool q = getEl(i - a, f);
    bool w = getEl(i - b, f);
    bool e = getEl(i - c, f);

    return q || w || e;
}

int solve(int n, int a, int b, int c)
{
    bool* f = new bool[n];
    f[0] = true;
    int res = 1;

    for (size_t i = 1; i < n; ++i)
    {
        f[i] = getSum(i, f, a, b, c);
        if (f[i]) res++;
    }

    return res;
}

int main()
{
    std::fstream fin;
    std::fstream fout;
    fin.open("input.txt", std::ios::in);

    int n, a, b, c;

    if (!fin.is_open())
        return -1;

    fin >> n >> a >> b >> c;
    fin.close();

    int res = solve(n, a, b, c);

    fout.open("output.txt", std::ios::out);

    if (!fout.is_open())
        return -1;

    fout << res;
    fout.close();

    return 0;
}
