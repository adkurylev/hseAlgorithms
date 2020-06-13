#include <fstream>
#include <vector>

int solve(int N, int M, int* m, int* c)
{
    std::vector<std::vector<int>> a(N + 1);

    for (int i = 0; i < N + 1; ++i)
        a[i] = std::vector<int>(M + 1);

    for (int i = 1; i < N + 1; ++i)
        for (int j = 1; j < M + 1; ++j)
        {
            if (j >= m[i - 1])
                a[i][j] = std::max(a[i - 1][j], a[i - 1][j - m[i - 1]] + c[i - 1]);
            else
                a[i][j] = a[i - 1][j];
        }

    return a[N][M];
}

int main(int argc, const char * argv[])
{
    std::fstream fin;
    std::fstream fout;
    int N = 0;
    int M = 0;
    int* m = nullptr;
    int* c = nullptr;

    fin.open("input.txt", std::ios::in);

    if (fin.is_open())
    {
        fin >> N >> M;
        m = new int[N];
        c = new int[N];

        for (int i = 0; i < N; ++i)
            fin >> m[i];

        for (int i = 0; i < N; ++i)
            fin >> c[i];

        fin.close();
    }

    int res = solve(N, M, m, c);

    fout.open("output.txt", std::ios::out);

    if (fout.is_open())
        fout << res << "\n";

    delete[] m;
    delete[] c;
    return 0;
}