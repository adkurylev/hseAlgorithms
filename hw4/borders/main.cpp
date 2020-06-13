#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

//Основная задача - реализовать данный метод
//Результат поместить в переменную res, она как раз доступна для изменения
//Можно добавлять любое количество любых вспомогательных методов, структур и классов
void getBorders(string& s, string& res)
{
    res = "";
    int len = s.length();

    for(int i = 0; i < len - 1; ++i)
        if (s.substr(0, i + 1) == s.substr(len - i - 1, i + 1))
            res += s.substr(0, i + 1) + "\n";
}

//Не изменять метод main без крайней необходимости
//ОБЯЗАТЕЛЬНО добавить в комментариях подробные пояснения и причины побудившие вас изменить код этого метода.
int main()
{
    string input;
    string res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open()) {
        getline(fin, input);
        fin.close();
    }

    getBorders(input, res);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();

    return 0;
}
