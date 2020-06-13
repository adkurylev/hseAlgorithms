#include "ReadWriter.h"
#include "MergeSort.h"
#include <vector>
//iostream, fstream включены в ReadWriter.h

//Не рекомендуется добавлять собственные вспомогательные классы и методы.
//Необходимо использовать уже имеющиеся классы и методы, добавив реализацию, соответствующую описанию.

//Описание методов на английском языке имеется в классе MergeSort, в файле MergeSort.h
void MergeSort::sort(int *arr, int length)
{
    divide_and_merge(arr, 0, length - 1);
}

void MergeSort::merge(int *arr, int first, int second, int end)
{
    int* L = new int[second - first + 1];
    int* R = new int [end - second];

    for (size_t i = 0; i <= second - first; i++)
        L[i] = arr[first + i];
    for (size_t j = 0; j < end - second; j++)
        R[j] = arr[second + 1+ j];

    int i = 0, j = 0, k = first;

    while (i <= second - first && j < end - second)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < second - first + 1)
        arr[k++] = L[i++];

    while (j < end - second)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void MergeSort::divide_and_merge(int *arr, int left, int right)
{
    if (left == right)
        return;

    divide_and_merge(arr, left, left + (right - left) / 2);
    divide_and_merge(arr, left + (right - left) / 2 + 1, right);
    merge(arr, left, left + (right - left) / 2, right);
}

int main()
{
    ReadWriter rw;

    int *brr = nullptr;
    int length;

    //Read data from file
    length = rw.readInt();

    brr = new int[length];
    rw.readArray(brr, length);

    //Start sorting
    MergeSort s;

    s.sort(brr, length);

    //Write answer to file
    rw.writeArray(brr, length);

    delete[] brr;

    return 0;
}
