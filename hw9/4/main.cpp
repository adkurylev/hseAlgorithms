#include "ReadWriter.h"
#include <vector>
//string, iostream included in "ReadWriter.h"

//Можно добавлять любые вспомогательные методы и классы для решения задачи.

long long getSum(int i, int j, std::vector<std::vector<long long>>& a);

long long getEl(int i, int j, std::vector<std::vector<long long>>& a)
{
    if (i < 0 || j < 0 || i >= a.size() || j >= a[0].size())
        return 0;

    if (a[i][j] == -1)
        a[i][j] = getSum(i, j, a);

    return a[i][j];
}

long long getSum(int i, int j, std::vector<std::vector<long long>>& a)
{
    long long q = getEl(i - 2, j - 1, a);
    long long w = getEl(i - 2, j + 1, a);
    long long e = getEl(i - 1, j - 2, a);
    long long r = getEl(i + 1, j - 2, a);

    return q + w + e + r;
}

//Задача реализовать этот метод
//param N - количество строк (rows) доски
//param M - количество столбцов (columns) доски
//return - количество способов попасть в правый нижний угол доски (клетка N-1, M-1, если считать что первая клетка 0,0)
long long solve(int N, int M)
{
    std::vector<std::vector<long long>> a(N);

    for (size_t i = 0; i < N; ++i)
        a[i] = std::vector<long long>(M);

    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < M; ++j)
            a[i][j] = -1;

    a[0][0] = 1; // если здесь напишу 0, как в презентации, очевидно, что везде будут нули

    for (size_t i = 0; i < N; ++i)
        for (size_t j = 0; j < M; ++j)
            a[i][j] = getEl(i, j, a);

    return a[N - 1][M - 1];
}

int main(int argc, const char * argv[])
{
    ReadWriter rw;

    int N = rw.readInt(); //количество строк (rows)
    int M = rw.readInt(); //количество столбцов (columns)
    //решение
    long long res = solve(N, M);
    //результат в файл
    rw.writeLongLong(res);

    return 0;
}