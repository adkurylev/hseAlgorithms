#include "ReadWriter.cpp"
#include <iostream>
#include <queue>
#include <algorithm>

typedef std::pair<unsigned int, Node*> intNodePair;

struct QueueComparer
{
    bool operator()(const intNodePair& a, const intNodePair& b)
    {
        return a.first == b.first ?
               a.second->name.compare(b.second->name) > 0 :
               a.first > b.first;
    }
};

//Задача - реализовать данный метод, решение должно быть в переменной result
void solve(std::vector<Node>& graph, int start, std::vector<std::string>& result)
{
    std::priority_queue<intNodePair , std::vector<intNodePair>, QueueComparer> queue;
    queue.push(std::make_pair(0, &graph[start]));
    queue.top().second->visited = true;

    while(!queue.empty())
    {
        intNodePair n = queue.top();
        queue.pop();
        result.push_back(n.second->name);
        for (Node* it : n.second->neighbours)
            if (!it->visited)
            {
                it->visited = true;
                queue.push(std::make_pair(n.first + 1, it));
            }
    }
}

int main()
{
    std::vector<Node> graph;
    std::vector<std::string> result;
    int start;

    ReadWriter rw;
    rw.readGraph(graph, start);
    solve(graph, start, result);
    rw.writeAnswer(result);
    return 0;
}
