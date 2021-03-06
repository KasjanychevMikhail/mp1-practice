#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define K 100
#define SBUF 2048
void choosesort(int *a, ULONGLONG *size, int n)
{
	int i, j, tmp, ind;
	for (i = 0; i < n - 1; i++)
	{
		ind = i;
		for (j = i + 1; j < n; j++)
		{
			if (size[a[ind]] > size[a[j]])
				ind = j;
		}
		tmp = a[ind];
		a[ind] = a[i];
		a[i] = tmp;
	}
}
void insertsort(int *a, ULONGLONG *size, int n)
{
	int i, j, tmp;
	for (i = 1; i < n; i++)
	{
		tmp = a[i];
		j = i - 1;
		while ((j >= 0) && (size[a[j]] > size[tmp]))
		{
			a[j + 1] = a[j];
			a[j--] = tmp;
		}
	}
}
void bubblesort(int *a, ULONGLONG *size, int n)
{
	int i, j, tmp;
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n - i; j++)
		{
			if (size[a[j - 1]] > size[a[j]])
			{
				tmp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tmp;
			}
		}
	}
}
void counting(int *a, ULONGLONG *size, int n)
{
	int i, j, h = 0;
	int ind = 0;
	int *b = (int*)malloc(K * sizeof(int));
	for (i = 0; i < K; i++)
		b[i] = 0;
	for (i = 0; i < n; i++)
		b[size[a[i]]]++;
	for (i = 0; i < K; i++)
	{
		if (b[i] > 0)
		{
			h = 0;
			for (j = 0; j < b[i]; j++)
			{
				while (size[h] != i)
					h++;
				a[ind++] = h++;
			}
		}
	}
	free(b);
}
void quicksplit(int *a, ULONGLONG *size, int *i, int *j, ULONGLONG p)
{
	int tmp;
	do {
		while (size[a[(*i)]] < p)
			(*i)++;
		while (size[a[(*j)]] > p)
			(*j)--;
		if ((*i) <= (*j))
		{
			tmp = a[(*i)];
			a[(*i)] = a[(*j)];
			a[(*j)] = tmp;
			(*i)++;
			(*j)--;
		}
	} while ((*i) < (*j));
}
void quicksort(int *a, ULONGLONG *size, int n1, int n2)
{
	int m = (n1 + n2) / 2;
	int i = n1, j = n2;
	quicksplit(a, size, &i, &j, size[a[m]]);
	if (j > n1)
		quicksort(a, size, n1, j);
	if (i < n2)
		quicksort(a, size, i, n2);
}
void merge(int *a, ULONGLONG *size, int l, int m, int r)
{
	int i, j = m + 1, h, tmp;
	for (i = l; ((i < r) && (j <= r)); i++)
	{
		if (size[a[i]] > size[a[j]])
		{
			tmp = a[j];
			for (h = j; h > i; h--)
				a[h] = a[h - 1];
			a[i] = tmp;
			j++;
		}
	}

}
void mergesort(int *a, ULONGLONG *size, int l, int r)
{
	int m;
	if (l >= r) return;
	m = (l + r) / 2;
	mergesort(a, size, l, m);
	mergesort(a, size, m + 1, r);
	merge(a, size, l, m, r);
}
int ListDirectoryContents(const wchar_t *sDir, ULONGLONG **sizes, wchar_t ***names)
{
	WIN32_FIND_DATA fdFile;
	HANDLE hFind = NULL;
	wchar_t sPath[2048];

	wsprintf(sPath, L"%s\\*.*", sDir);
	if ((hFind = FindFirstFile(sPath, &fdFile)) == INVALID_HANDLE_VALUE)
	{
		wprintf(L"Path not found: [%s]\n", sDir);
		return 1;
	}

	do
	{
		if (wcscmp(fdFile.cFileName, L".") != 0 && wcscmp(fdFile.cFileName, L"..") != 0)
		{
			ULONGLONG fileSize = fdFile.nFileSizeHigh;
			fileSize <<= sizeof(fdFile.nFileSizeHigh) * 8;
			fileSize |= fdFile.nFileSizeLow;

			wsprintf(sPath, L"%s\\%s", sDir, fdFile.cFileName);
			wprintf(L"File: %s Size: %d\n", sPath, fileSize);
		}
	} while (FindNextFile(hFind, &fdFile));
	FindClose(hFind);
	return 0;
}
void input(wchar_t **dir)
{
	char *str;
	*dir = (wchar_t*)malloc(SBUF * sizeof(wchar_t));
	str = (char*)malloc(SBUF * sizeof(char));
	fgets(str, SBUF, stdin);
	str[strlen(str) - 1] = '\0';
	swprintf(*dir, SBUF, L"%hs", str);
	free(str);
}
void output(wchar_t **name, ULONGLONG *size, int *idx, int k)
{
	int i;
	for (i = 0; i < k; i++)
	{
		wprintf(L"����: %s ������: ", name[idx[i]]);
		printf("%lld ����", size[idx[i]]);
		printf("\n");
	}
}
void menu()
{
	printf("�������� ��� ����������:\n 1. ���������� �������\n 2. ���������� ���������\n 3. ����������� ����������\n 4. ���������� ���������\n 5. ���������� �����\n 6. ���������� ��������\n 0. ��������� ������ ���������\n");
}
void main()
{
	int i, k = 0;
	int z;
	int *idxs;
	wchar_t **names;
	ULONGLONG *sizes;
	clock_t start, finish;
	wchar_t *b = (wchar_t*)malloc(SBUF * sizeof(wchar_t));
	float ftime = 0.0f;
	setlocale(LC_ALL, "Russian");

	do {
		printf("������� �����: ");
		input(&b);
		k = ListDirectoryContents(b, &sizes, &names);
		if (k == -1) {
			printf("������� ������ �� ����������!"); continue;
		}
		if (k == 0) {
			printf("������ ����� �����!"); continue;
		}
	} while (k < 1);
	do {
		menu();
		idxs = (int*)malloc(k * sizeof(int));
		for (i = 0; i < k; i++)
			idxs[i] = i;
		scanf_s("%d", &z);
		start = clock();
		if (z == 1) choosesort(idxs, sizes, k);
		if (z == 2) insertsort(idxs, sizes, k);
		if (z == 3) bubblesort(idxs, sizes, k);
		if (z == 4) counting(idxs, sizes, k);
		if (z == 5) quicksort(idxs, sizes, 0, k - 1);
		if (z == 6) mergesort(idxs, sizes, 0, k - 1);
		finish = clock();
		ftime = (float)(finish - start) / CLOCKS_PER_SEC;
		output(idxs, names, sizes, k);
		printf("����� ����������: %.3f ������", ftime);
		free(idxs);
	} while (z != 0);
	for (i = 0; i < k; i++)
		free(names[i]);
	free(names);
	free(sizes);
	free(b);
}