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