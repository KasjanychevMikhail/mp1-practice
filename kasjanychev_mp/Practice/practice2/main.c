#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	int n, l, y = 0;
	int a[10], b[10], x[10];
	int i, m, j;
	int j, k, z = 0;
	printf("Vvedite dlinu zagadivaemogo chisla");
	scanf("%d", &n);
	srand((unsigned int)time(0));
	for (i = 0; i < n; i++)
		a[i] = i;
	for (l = 0; l < n; l++)
	{
		i = 9 / RAND_MAX*rand();
		b[l] = a[i];
		for (i = i; i < 10; i++)
			a[i] = a[i + 1];
	}
	while (z != n)
	{
        printf("Vvedite predpolozhitelnoe chislo");
	    scanf("%d", &y);
	    m = 10 * n;
	    for (i = 0; i < n; i++)
	    {
		    x[i] = y / m;
		    y = y % m;
		    m = m / 10;
	    }
	    for (i = 0; i < n; i++)
	    {
		    for (j = 0; j < n; j++)
		    {
		    	if ((x[i] == b[j]) && (i != j))
				k++;
	    		if ((x[i] == b[j]) && (i == j))
				z++;
	    	}
    	}
		printf("Kol-vo korov=%d", k);
		printf("Kol-vo bikov=%d", z);
	}
	printf("Chislo ugadano!");
}