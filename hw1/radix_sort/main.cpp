#include "ReadWriter.h"
//iostream, fstream включены в ReadWriter.h

int max(const int *arr, int n);
void countingSort(int *arr, int n, int rank);
int const base = 256;

union U
{
    int i;
    unsigned char c[4];
};

// Функция цифровой сортировки
void radixSort(int *numbers, int array_size)
{
//    int m = max(numbers, array_size);

    for (int rank = 0; rank < 4; ++rank)
        countingSort(numbers, array_size, rank);
}

int max(const int *a, int n)
{
    if (n == 0)
        return 0;

    int max = a[0];

    for (int i = 1; i < n; ++i)
        if (a[i] > max)
            max = a[i];

    return max;
}

void countingSort(int *arr, int n, int rank)
{
    if (n == 0 || n == 1)
        return;

    U un;

    int *b = new int[n];
    int *c = new int[base];

    for (int i = 0; i < base; ++i)
        c[i] = 0;

    for (int i = 0; i < n; ++i)
    {
        un.i = arr[i];
        c[un.c[rank]]++;
    }

    for (int i = 1; i < base; ++i)
        c[i] += c[i - 1];

    for (int i = n - 1; i >= 0; --i)
    {
        un.i = arr[i];
        b[c[un.c[rank]] - 1] = arr[i];
        --c[un.c[rank]];
    }

    for (int i = 0; i < n; ++i)
        arr[i] = b[i];

    delete[] b;
    delete[] c;
}

//Не удалять и не изменять метод main без крайней необходимости.
//Необходимо добавить комментарии, если все же пришлось изменить метод main.
int main()
{
    //Объект для работы с файлами
    ReadWriter rw;

    int *brr = nullptr;
    int n;

    //Ввод из файла
    n = rw.readInt();

    brr = new int[n];
    rw.readArray(brr, n);

    //Запуск сортировки, ответ в том же массиве (brr)
    radixSort(brr, n);

    //Запись в файл
    rw.writeArray(brr, n);

    //освобождаем память
    delete[] brr;

    return 0;
}
