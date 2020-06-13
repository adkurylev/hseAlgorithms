#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> getBordersArray(int len, string& substring)
{
    vector<int> br(len);

    for (int i = 1; i < len; ++i)
    {
        int j = br[i - 1];

        while (j != 0 && substring[i] != substring[j])
            j = br[j - 1];

        if (substring[i] == substring[j])
            ++j;

        br[i] = j;
    }

    return br;
}

//Основная задача - реализовать данный метод
//Можно изменить передачу параметров на ссылки (&)
//Можно добавлять любое количество любых вспомогательных методов, структур и классов
void getSubstrings(string& source, string& substring, vector<int>& res)
{
    int len = substring.length();
    int k = 0;

    vector<int> br = getBordersArray(len, substring);

    for (int i = 0; i < source.length(); ++i)
    {
        while (k > 0 && source[i] != substring[k])
            k = br[k - 1];

        if (source[i] == substring[k])
            ++k;

        if (k == len)
        {
            res.push_back(i - len + 1);
            k = br[k - 1];
        }
    }
}

//Не изменять метод main без крайней необходимости
//ОБЯЗАТЕЛЬНО добавить в комментариях подробные пояснения и причины побудившие вас изменить код этого метода.
int main()
{
    string t;
    string p;
    vector<int> res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        getline(fin, t);
        getline(fin, p);
        fin.close();
    }

    getSubstrings(t, p, res);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res.size() << "\n";
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        fout << *i << "\n";
    fout.close();

    return 0;
}
