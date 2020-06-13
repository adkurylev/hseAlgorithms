#include "ReadWriter.h"
#include <set>

void getResult(int i, int j, int* stones, std::vector<std::vector<int>>& a, std::vector<int>& res)
{
    if (a[i][j] == 0)
        return;
    if (a[i - 1][j] == a[i][j])
        getResult(i - 1, j, stones, a, res);
    else
    {
        getResult(i - 1, j - stones[i - 1], stones, a, res);
        res.push_back(stones[i - 1]);
    }
}

void solve(int n, int w, int* stones, std::vector<int>& res)
{
    std::vector<std::vector<int>> a(n + 1);

    for (int i = 0; i < n + 1; ++i)
        a[i] = std::vector<int>(w + 1);

    for (int i = 1; i < n + 1; ++i)
        for (int j = 1; j < w + 1; ++j)
        {
            if (j >= stones[i - 1])
                a[i][j] = std::max(a[i - 1][j], a[i - 1][j - stones[i - 1]] + stones[i - 1]);
            else
                a[i][j] = a[i - 1][j];
        }

    getResult(n, w, stones, a, res);
}

int main(int argc, const char * argv[])
{
    ReadWriter rw;
    int N = rw.readInt(); //камни
    int W = rw.readInt(); //ограничения на вес
    int* arr = new int[N]; //имеющиеся камни
    rw.readArr(arr, N);

    //основной структурой выбран вектор, так как заранее неизвестно какое количество камней будет взято
    std::vector<int> res;
    //решаем задачу
    solve(N, W, arr, res);
    int sum = 0;
    for (int i = 0; i < res.size(); i++)
        sum += res.at(i);

    //записываем ответ в файл
    rw.writeInt(sum); //итоговый вес
    rw.writeInt(res.size()); //количество взятых камней
    rw.writeVector(res); //сами камни

    delete[] arr;
    return 0;
}