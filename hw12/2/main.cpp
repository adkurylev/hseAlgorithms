#include "ReadWriter.h"

void constructGraph(std::vector<std::vector<int>>& graph, std::vector<Edge>& edges, int N, int inf)
{
    for (auto& it : graph)
        it = std::vector<int>(N, inf);

    for (auto& it : edges)
    {
        graph[it.A][it.B] = it.W;
        graph[it.B][it.A] = it.W;
    }
}

void solve(int N, int M, std::vector<Edge>& edges, std::vector<Edge>& result)
{
    const int inf = 30001;
    std::vector<std::vector<int>> graph(N);
    std::vector<int> distances(N, inf);
    distances[0] = 0;
    std::vector<bool> visited(N);

    constructGraph(graph, edges, N, inf);

    for (int i = 0; i < N; ++i)
    {
        int u;
        int distance = inf;

        for (int j = 0; j < N; ++j)
        {
            if (!visited[j] && distances[j] < distance)
            {
                distance = distances[j];
                u = j;
            }
        }

        visited[u] = true;

        for (auto it : edges)
            if ((it.A == u || it.B == u) && it.W == distance)
                result.push_back(it);

        for (int j = 0; j < N; ++j)
            distances[j] = std::min(distances[j], graph[u][j]);
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