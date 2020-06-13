#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

void dfs1(int v, std::vector<int>& post, std::vector<bool>& visited, std::vector<std::vector<bool>>& relations)
{
    visited[v] = true;

    for (int i = 0; i < relations.size(); ++i)
        if (relations[v][i] && !visited[i])
            dfs1(i, post, visited, relations);

    post.push_back(v);
}

void dfs2(int v, std::vector<int>& scc, std::vector<bool>& visited, std::vector<std::vector<bool>>& relations)
{
    visited[v] = true;
    scc.push_back(v);

    for (int i = 0; i < relations.size(); ++i)
        if (relations[i][v] && !visited[i])
            dfs2(i, scc, visited, relations);
}

void sort(std::vector<std::vector<std::string>>& res)
{
    for(auto& it : res)
        std::sort(it.begin(), it. end());

    std::sort(res.begin(), res.end());
}

std::vector<std::vector<std::string>> getList(std::vector<std::string> names, std::vector<std::vector<bool>> relations)
{
    int n = names.size();
    std::vector<bool> visited(n);
    std::vector<int> post, scc;
    std::vector<std::vector<std::string>> res;

    for (int i = 0; i < n; ++i)
        if (!visited[i])
            dfs1(i, post, visited, relations);

    visited.assign(n, false);

    for (int i = 0; i < n; ++i)
    {
        int v = post[n - 1 - i];
        if (!visited[v])
        {
            dfs2(v, scc, visited, relations);
            res.emplace_back();
            for(int j : scc)
                res.back().push_back(names[j]);
            scc.clear();
        }
    }

    sort(res);

    return res;
}

int main()
{
    std::vector<std::string> names = std::vector<std::string>();
    std::vector<std::vector<bool>> relations;

    std::ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        std::string str;
        getline(fin, str);

        while (str != "#")
        {
            names.emplace_back(str.substr(str.find(' ') + 1));
            getline(fin, str);
        }

        relations = std::vector<std::vector<bool>>(names.size());

        for (int i = 0; i < names.size(); i++)
        {
            relations[i] = std::vector<bool>(names.size());
            for (int j = 0; j < names.size(); j++)
                relations[i][j] = false;
        }

        getline(fin, str);

        while (fin)
        {
            int a = stoi(str.substr(0, str.find(' '))) - 1;
            int b = stoi(str.substr(str.find(' '))) - 1;
            relations[a][b] = true;
            getline(fin, str);
        }

        fin.close();
    }

    std::vector<std::vector<std::string>> res = getList(names, relations);

    std::fstream fout;
    fout.open("output.txt", std::ios::out);
    for (auto& re : res)
    {
        for (auto& j : re)
            fout << j << "\n";
        fout << "\n";
    }
    fout.close();

    return 0;
}
