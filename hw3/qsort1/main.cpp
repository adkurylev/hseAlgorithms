#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

void quickSortRecursive(int* arr, int l, int r);
int takePivot(const int* arr, int l, int r);

void quickSort(int *numbers, int array_size)
{
    quickSortRecursive(numbers, 0, array_size - 1);
}

void quickSortRecursive(int* arr, int l, int r)
{
    int i = l;
    int j = r;
    int pivot = takePivot(arr, i, j);

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i <= j)
            std::swap(arr[i++], arr[j--]);
    }

    if (j > l)
        quickSortRecursive(arr, l, j);

    if (i < r)
        quickSortRecursive(arr, i, r);
}

int takePivot(const int* arr, int l, int r) { return arr[r]; }

int main()
{
    int *brr;
    int n;

    std::fstream fin;
    fin.open("input.txt",std::ios::in);
    if (fin.is_open())
	{
        fin >> n;
        brr = new int[n];
        for (int i = 0; i < n; i++)
            fin >> brr[i];

        fin.close();
    }
	quickSort(brr, n);
    std::fstream fout;
    fout.open("output.txt",std::ios::out);
    for (int i = 0; i < n; i++)
        fout << brr[i] << " ";

    fout.close();
    delete[] brr;
    return 0;
}