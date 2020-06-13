#include "ReadWriter.h"
//iostream, fstream включены в ReadWriter.h

int max(const int* a, int n);

// Функция сортировки подсчетом
void countingSort(int* numbers, int array_size)
{
    if (array_size == 0 || array_size == 1)
        return;

    int* b = new int[array_size];
    int k = max(numbers, array_size);
    int* c = new int[k + 1];

    for (int i = 0; i < k + 1; ++i)
        c[i] = 0;

    for (int i = 0; i < array_size; ++i)
        c[numbers[i]]++;

    for (int i = 1; i < k + 1; ++i)
        c[i] += c[i - 1];

    for (int i = array_size - 1; i >= 0; --i)
    {
        b[c[numbers[i]] - 1] = numbers[i];
        --c[numbers[i]];
    }

    for (int i = 0; i < array_size; ++i)
        numbers[i] = b[i];

    delete[] b;
    delete[] c;
}

int max(const int* a, int n)
{
    if (n == 0)
        return 0;

    int max = a[0];

    for (int i = 1; i < n; ++i)
        if (a[i] > max)
            max = a[i];

    return max;
}

//Не удалять и не изменять метод main без крайней необходимости.
//Необходимо добавить комментарии, если все же пришлось изменить метод main.
int main()
{
    //Объект для работы с файлами
    ReadWriter rw;

    int* brr = nullptr;
    int n;

    //Ввод из файла
    n = rw.readInt();

    brr = new int[n];
    rw.readArray(brr, n);

    //Запуск сортировки, ответ в том же массиве (brr)
    countingSort(brr, n);

    //Запись в файл
    rw.writeArray(brr, n);

    //освобождаем память
    delete[] brr;

    return 0;
}
