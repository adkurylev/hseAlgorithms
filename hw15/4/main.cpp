#include <fstream>
#include <vector>
#include <string>

static std::string vector_to_string(std::vector<int>& vector, int lastIndex)
{
    std::string res;

    for (int i = 0; i < lastIndex; ++i)
        res += std::to_string(vector[i]) + " ";

    return res + std::to_string(vector[lastIndex]);
}

static void find_k_m(int n, int& k, int& m)
{
    while(n >= 12)
    {
        k++;
        n -= 12;
    }

    m = n;
}

static int find_index(std::vector<int>& partition, int& last)
{
    for (int i = last - 1; i > 0; --i)
    {
        if ((partition[i - 1] > partition[i]))
            return i;
    }

    return 0;
}

static int find_sum(std::vector<int>& partition, int last, int k)
{
    int res = 0;

    for (int i = k; i <= last; ++i)
        res += partition[i];

    return res;
}

static std::string next_partition(std::vector<int>& partition, int& last, int n)
{
    int index = find_index(partition, last);
    partition[index]++;

    int sum = find_sum(partition, last, index + 1);

    for (int i = 1; i < sum; ++i)
        partition[index + i] = 1;

    last = index + sum - 1;

    return vector_to_string(partition, last);
}

static bool check_condition(std::vector<int>& partition, int last, int n, int m, int k)
{
    if (k == 0)
        return partition[0] != n;
    else if (m == 0)
        return partition[last] != 12;
    else
        return (last != k) || (partition[last] != m);
}

static void get(int n, std::fstream& fout)
{
    std::vector<int> partition = std::vector<int>(n, 1);
    int k = 0, m = 0;
    int last = n - 1;
    
    fout << vector_to_string(partition, last) << "\n";

    find_k_m(n, k, m);

    while (check_condition(partition, last, n, m, k))
        fout << next_partition(partition, last, n) << "\n";
}

int main(int argc, const char * argv[])
{
    int n;

    std::fstream fin;
    std::fstream fout;

    fin.open("input.txt", std::ios::in);
    fout.open("output.txt", std::ios::out);

    if(fin.is_open())
    {
        std::string str;

        getline(fin,str);
        n = atoi(str.c_str());

        get(n, fout);

        fout.close();
        fin.close();
    }

    return 0;
}