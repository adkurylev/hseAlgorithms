#include <fstream>
#include <vector>
#include <string>

static void get(long n, long m, long k, std::fstream& fout)
{
    std::vector<int> a(m);

    if (n > 1)
        for (long i = m - 1; k > 0; k /= n)
            a[i--] += k % n;

    for (long i = 0; i < m - 1; ++i)
        fout << a[i] + 1 << " ";

    fout << a[m - 1] + 1;
}

int main(int argc, const char* argv[])
{
    long n, m, k;

    std::fstream fin;
    std::fstream fout;

    fin.open("input.txt", std::ios::in);
    fout.open("output.txt", std::ios::out);

    if (fin.is_open())
    {
        std::string str;

        getline(fin, str);
        n = atol(str.c_str());

        getline(fin, str);
        m = atol(str.c_str());

        getline(fin, str);
        k = atol(str.c_str());

        get(n, m, k - 1, fout);

        fout.close();
        fin.close();
    }
    return 0;
}