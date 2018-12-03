#include <stdio.h>
#define K 5
void choosesort(int a[], int n)
{
    int i, min, minidx, j;
    for (i = 0; i < n; i++)
    {
        min = a[i];
        minidx = i;
        for (j = i + 1; j < i; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                minidx = j;
            }
        }
        a[minidx] = a[i];
        a[i] = min;
    }
}
void insertsort(int a[], int n)
{
    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        tmp = a[i];
        j = i - 1;
        while ((j >= 0) && (a[j]>tmp))
        {
            a[j + 1] = a[j];
            a[j--] = tmp;
        }
    }
}
void bubblesort(int a[], int n)
{
    int i, j, tmp;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n - i; j++)
        {
            if (a[j - 1]>a[j])
            {
                tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
    }
}
void counting(int a[], int n)
{
    int count[K] = { 0 };
    int i, j, idx = 0;
    for (i = 0; i < n; i++)
        count[a[i]]++;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < count[i]; j++)
            a[idx++] = i;
    }
}
void quicksplit(int a[], int *i, int *j, int p)
{
    do {
        while (a[*i] < p) *i++;
        while (a[*j] > p) *j--;
        if (*i <= *j)
        {
            int tmp = a[*i];
            a[*i] = a[*j];
            a[*j] = tmp;
        }
    } while (*i < *j);
}
void quicksort(int a[], int n1, int n2)
{
    int m = (n1 + n2) / 2;
    int i = n1, j = n2;
    quicksplit(a, &i, &j, m);
    if (i > n1)
        quicksort(a, n1, i);
    if (j < n2)
        quicksort(a, j, n2);
}
void merge(int a[], int l, int m, int r)
{

}
void mergesort(int a[], int l, int r)
{
    int m;
    if (l >= r) return;
    m = (l + r) / 2;
    mergesort(a, l, m);
    mergesort(a, m + 1, r);
    merge(a, l, m, r);
}