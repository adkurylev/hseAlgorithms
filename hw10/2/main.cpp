#include "ReadWriter.cpp"
#include <iostream>
#include <queue>
#include <algorithm>

bool cmp(const Node* a, const Node* b)
{
    return a->name.compare(b->name) < 0;
}

void dfs(Node& n, std::vector<std::string>& result)
{
    n.visited = true;
    result.push_back(n.name);

    for (Node* it : n.neighbours)
        if (!it->visited)
            dfs(*it, result);
}

//Задача - реализовать данный метод, решение должно быть в переменной result
void solve(std::vector<Node>& graph, int start, std::vector<std::string>& result)
{
    for (Node& it : graph)
        std::sort(it.neighbours.begin(), it.neighbours.end(), cmp);

    dfs(graph[start], result);
}


int main() {
    std::vector<Node> graph;
    std::vector<std::string> result;
    int start;

    ReadWriter rw;
    rw.readGraph(graph, start);
    solve(graph, start, result);
    rw.writeAnswer(result);
    return 0;
}
