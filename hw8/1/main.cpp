#include <iostream>
#include <fstream>
#include <string>

int removeBFromString(std::string& str)
{
    int count = 0;
    std::string newStr;

    for (auto& it : str)
    {
        if (it != 'B')
            newStr += it;
        else
            count++;
    }

    str = newStr;

    return count;
}

char changeState(char& currentState)
{
    return currentState == 'L' ? 'R' : 'L';
}

int countMaxCross(std::string& riverMap)
{
    int count = removeBFromString(riverMap);
    int length = riverMap.length();
    char state = 'L';

    for (int i = 0; i < length; ++i)
    {
        if (i == length - 1)
            if (riverMap[i] == state)
                if (state == 'R')
                {
                    count++;
                    continue;
                }
                else
                {
                    count++;
                    state = 'R';
                    continue;
                }
        if (riverMap[i] == state)
        {
            if (riverMap[i] == riverMap[i + 1])
            {
                state = changeState(state);
                count++;
            }
            else
            {
                count++;
            }
        }
    }

    if (state == 'L')
        count++;

    return count;
}


int main()
{
    std::string riverMap;
    int res;

    std::ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        std::getline(fin, riverMap);
        fin.close();
    }

    res = countMaxCross(riverMap);

    std::fstream fout;
    fout.open("output.txt", std::ios::out);
    fout << res;
    fout.close();

    return 0;
}
