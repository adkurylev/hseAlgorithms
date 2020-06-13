#include <iostream>
#include <vector>

int main()
{
    std::string str;
    std::cin >> str;
    int n = str.length();
    std::vector<int> palindromes(n);

    int left = 0;
    int right = -1;

    for (int i = 0; i < n; ++i)
    {
        int min;

        if (i > right)
            min = 1;
        else
            min = std::min(palindromes[left + right - i], right - i + 1);

        while (i + min != n && i >= min && str[i + min] == str[i - min])
            ++min;

        palindromes[i] = min;

        if (i + min - 1 > right)
        {
            left = i - min + 1;
            right = i + min - 1;
        }
    }

    for (int i = 0; i < n; ++i)
        std:: cout << palindromes[i] * 2 - 1 << " ";

    return 0;
}
