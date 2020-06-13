#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, string>& left, const pair<int, string>& right)
{
    return left.second < right.second;
}

void dfs(vector<vector<bool>>& relations, vector<string>& names, vector<string>& result, vector<bool>& visited, int v)
{
    vector<pair<int, string>> order;

    for (int i = 0; i < relations[0].size(); ++i)
        if(relations[v][i] && !visited[v])
            order.emplace_back(i, names[i]);

    sort(order.begin(), order.end(), cmp);

    for (auto& i : order)
        dfs(relations, names, result, visited, i.first);

    if(!visited[v])
    {
        result.push_back(names[v]);
        visited[v] = true;
    }
}

vector<string> getList(vector<string>& names, vector<vector<bool>>& relation)
{
    int n = names.size();
    vector<pair<int, string>> order;
    vector<string> result;
    vector<bool> visited(n);

    for (int i = 0; i < n; i++)
    {
        bool flag = true;

        for (auto& j : relation)
            if (j[i])
                flag = false;

        if (flag)
            order.emplace_back(i, names[i]);
    }

    sort(order.begin(), order.end(), cmp);

    for (auto& i : order)
        dfs(relation, names, result, visited, i.first);

    reverse(result.begin(), result.end());

    return result;
}


int main()
{
    vector<string> names;
    vector<vector<bool>> relations;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        string str;
        getline(fin, str);
        while (str != "#")
        {
            names.emplace_back(str.substr(str.find(' ') + 1));
            getline(fin, str);
        }
        relations = vector<vector<bool>>(names.size());
        for (int i = 0; i < names.size(); i++)
        {
            relations[i] = vector<bool>(names.size());
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

    vector<string> res = getList(names, relations);

    fstream fout;
    fout.open("output.txt", ios::out);
    for (auto& re : res)
        fout << re << "\n";
    fout.close();
    return 0;
}