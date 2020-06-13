#include <fstream>
#include <vector>
#include <string>

static void get(long n, long k, std::fstream& fout)
{
    std::vector<long> a(n);
    a[n - 1] = (k - 1) % n;
    k /= n;

    if (n > 1)
        for (long i = n - 1; k > 0; k /= i--)
            a[i - 1] = k % i;

    for (long i = 0; i < n - 1; ++i)
        fout << a[i] + 1 << " ";

    fout << a[n - 1] + 1;
}

int main(int argc, const char * argv[])
{
    long n;
    long k;

    std::fstream fin;
    std::fstream fout;

    fin.open("input.txt", std::ios::in);
    fout.open("output.txt", std::ios::out);

    if(fin.is_open()) {
        std::string str;

        getline(fin,str);
        n = stol(str);

        getline(fin,str);
        k = stol(str);

        get(n, k, fout);

        fout.close();
        fin.close();
    }

    return 0;
}