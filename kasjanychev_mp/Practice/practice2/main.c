#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int n, l, y = 0;
	int a[10], b[10], x[10], z[10];
	int i, m;
	int j = 0;
	int k = 0;
	int zz = 0;
	srand((unsigned int)time(0));
	do
	{
		printf("n = ");
		scanf("%d", &n);
	} while ((n <= 0) || (n > 10));
	i = n - 1;
	m = 9.0 / RAND_MAX * rand() + 1;
	a[0] = m;
	b[m] = -1;
	while (i > 0)
	{
		m = 10.0 / RAND_MAX * rand();
		if (a[m] != -1)
		{
			b[i] = a[m];
			b[m] = -1;
			i--;
		}
	}

	do {
		do
		{
			m = 0;
			printf("number = ");
			scanf("%d", &l);
			for (i = (n - 1); i >= 0; i--)
			{
				x[i] = l % 10;
				l = l / 10;
			}
			for (i = (n - 1); i >= 0; i--)
			{
				for (j = (i - 1); j >= 0; j--)
				{
					if (x[i] == x[j]) m++;
				}
			}
		} while (m != 0);
		for (i = (n - 1); i >= 0; i--)
		{
			for (j = (n - 1); j >= 0; j--)
			{
				if ((a[i] == x[j]) && (i == j)) zz++;
				if ((a[i] == x[j]) && (j != i)) k++;
			}
		}
		printf("Kol-vo korov=%d", k);
		printf("Kol-vo bikov=%d", zz);
	} while (zz != n);
	printf("Chislo ugadano!");
}