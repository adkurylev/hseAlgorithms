#include "ReadWriter.h"

bool cmp(const Edge& a, const Edge& b)
{
    return a.W < b.W;
}

void solve(int N, int M, std::vector<Edge>& edges, std::vector<Edge>& result)
{
    std::vector<int> vect(N);
    for (int i = 0; i < N; ++i)
        vect[i] = i;

    sort(edges.begin(), edges.end(), cmp);

    for (auto edge : edges)
        if (vect[edge.A] != vect[edge.B])
        {
            result.push_back(edge);
            int b = vect[edge.B];
            int a = vect[edge.A];
            for (auto& v : vect)
                if (v == b)
                    v = a;
        }
}

int main()
{
    ReadWriter rw;
    //Входные параметры
    //N - количество вершин, M - количество ребер в графе
    int N, M;
    rw.read2Ints(N, M);

    //Вектор ребер, каждое ребро представлено 3-мя числами (А, В, W), где A и B - номера вершин, которые оно соединяет, и W - вес ребра
    //Основной структурой выбран вектор, так как из него проще добавлять и удалять элементы (а такие операции могут понадобиться).
    std::vector<Edge> edges;
    rw.readEgdes(M, edges);

    //Основной структурой для ответа выбран вектор, так как в него проще добавлять новые элементы.
    //(а предложенные алгоритмы работают итеративно, увеличивая количество ребер входящих в решение на каждом шаге)
    std::vector<Edge> result;

    //Алгоритм решения задачи
    //В решение должны входить ребра из первоначального набора!
    solve(N, M, edges, result);

    //Выводим результаты
    rw.writeInt(result.size());
    rw.writeEdges(result);

    return 0;
}