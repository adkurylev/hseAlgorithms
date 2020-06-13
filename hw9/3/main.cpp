#include "ReadWriter.h"
//vector, string, iostream, algorithm included in "ReadWriter.h"

//Можно добавлять любые вспомогательные методы и классы для решения задачи.

int cmp(const void* a, const void* b)
{
    std::pair<int, int> arg1 = *static_cast<const std::pair<int, int>*>(a);
    std::pair<int, int> arg2 = *static_cast<const std::pair<int, int>*>(b);

    double res1 = ((double)arg1.second) / arg1.first;
    double res2 = ((double)arg2.second) / arg2.first;

    if (res1 > res2)
        return -1;

    if (res1 < res2)
        return 1;

    if (arg1.first > arg2.first)
        return -1;

    if (arg1.first < arg2.first)
        return 1;

    return 0;
}

//Задача реализовать этот метод (жадный алгоритм)
//param N - количество предметов
//param W - ограничения на вес рюкзака
//param items - массив размера N, с предметами - first = вес, second = стоимость
//param res - вектор результатов (предметы, которые надо взять)
void solve(int N, int W, std::pair<int, int>* items, std::vector<std::pair<int, int>>& res)
{
	std::qsort(items, N, sizeof(items[0]), cmp);

	for (size_t i = 0; i < N; ++i)
    {
	    std::pair<int, int> item = items[i];
	    if (item.first <= W)
        {
	        res.push_back(item);
	        W -= item.first;
        }
    }
}

int main(int argc, const char * argv[])
{
    ReadWriter rw;
    int N = rw.readInt(); //количество предметов
    int W = rw.readInt(); //ограничения на вес рюкзака

    //структура массив pair выбрана, так как известно количество элементов, и у объекта всего 2 характеристики
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