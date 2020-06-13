#include <iostream>
#include <fstream>
#include <vector>

const int N = 31;

int countMinSum(int seconds, std::vector<int>& values)
{
    std::vector<long long> longValues;
    int exp[N] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};

    longValues.reserve(N);
    for (int i = 0; i < N; ++i)
        longValues.push_back(values[i]);

    for (int i = 1; i < N; ++i)
        if (longValues[i] < longValues[i - 1] * 2)
            longValues[i] = longValues[i - 1] * 2;

    int cost = 0;
    for (int i = N - 1; i >= 0; --i)
    {
        if (longValues[i] <= seconds)
        {
            seconds -= longValues[i];
            cost += exp[i];
        }
    }

    if (seconds > 0)
        cost++;

    return cost;
}


int main()
{
    std::vector<int> values;
    int value = 0, seconds = 0;

    std::ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        fin >> seconds;
        for (int i = 0; i < N; i++)
        {
            fin>>value;
            values.push_back(value);
        }
        fin.close();
    }

    int res = countMinSum(seconds, values);

    std::fstream fout;
    fout.open("output.txt", std::ios::out);
    fout << res;
    fout.close();

    return 0;
}
