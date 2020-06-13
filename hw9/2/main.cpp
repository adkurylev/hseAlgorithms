#include "ReadWriter.h"
//vector, string, iostream included in "ReadWriter.h"

//Можно добавлять любые вспомогательные методы и классы для решения задачи.

void getResult(int i, int j, std::pair<int, int>* items, std::vector<std::vector<int>>& a, std::vector<std::pair<int, int>>& res)
{
    if (a[i][j] == 0)
        return;
    if (a[i - 1][j] == a[i][j])
        getResult(i - 1, j, items, a, res);
    else
    {
        getResult(i - 1, j - items[i - 1].first, items, a, res);
        res.push_back(items[i - 1]);
    }
}

//Задача реализовать этот метод
//param N - количество предметов
//param W - ограничения на вес рюкзака
//param items - массив размера N, с предметами - first = вес, second = стоимость
//param res - вектор результатов (предметы, которые надо взять)
void solve(int N, int W, std::pair<int, int>* items, std::vector<std::pair<int, int>>& res)
{
    std::vector<std::vector<int>> a(N + 1);

    for (int i = 0; i < N + 1; ++i)
        a[i] = std::vector<int>(W + 1);

    for (int i = 1; i < N + 1; ++i)
        for (int j = 1; j < W + 1; ++j)
            if (j >= items[i - 1].first)
                a[i][j] = std::max(a[i - 1][j], a[i - 1][j - items[i - 1].first] + items[i - 1].second);
            else
                a[i][j] = a[i - 1][j];

    getResult(N, W, items, a, res);
}

int main(int argc, const char* argv[])
{
    ReadWriter rw;
    int N = rw.readInt(); //количество предметов
    int W = rw.readInt(); //ограничения на вес рюкзака

    //структура массив pair выбрана, так как известно количество и у объекта всего 2 характеристики
    //first = вес(weight), second = стоимость (cost)
    //Можно переложить данные в любую другую удобную струтуру
    //Внимание(!) данные не упорядочены, но можно это сделать если вам требуется
    std::pair<int, int>* arr = new std::pair<int, int>[N];
    rw.readArr(arr, N);

    //структура вектор pair выбрана, так как неизвестно количество элементов, и у объекта всего 2 характеристики
    //результат, также first = вес(weight), second = стоимость (cost)
    std::vector<std::pair<int, int>> res;
    solve(N, W, arr, res);

    int sumCost = 0, sumWeight = 0;
    for (int i = 0; i < res.size(); i++)
    {
        sumWeight += res[i].first;
        sumCost += res[i].second;
    }
    //записываем ответ в файл
    rw.writeInt(sumCost);
    rw.writeInt(sumWeight);
    rw.writeInt(res.size());
    rw.writeVector(res);

    delete[] arr;
    return 0;
}