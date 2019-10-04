#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<time.h>
#include <stdio.h> 
#define N 5

void Komanda()
{
	printf("\n1 - Scanirovanie \n");
	printf("2 - Pokazat opisanie \n");
	printf("3 - Dobavit tovar v check \n");
	printf("4 - Sforvirovat check \n");
	printf("5 - Podshitat summu \n");
}
void Gener(int a[], int n, double m)
{
	int i;
	srand((unsigned int)time(0));
	for (i = 0; i < n; i++)
		a[i] = m / RAND_MAX * rand() + 1;
}
int Scan(int* num, char** id)
{
	char tov[4];
	int temp, i;
	do
	{
		printf("Vvedite shtrihkod \n");
		scanf("%s", &tov);
		i = 0;
		while (strncmp(tov, id[i], 4) != 0)
		{
			i++;
		}
		temp = i;
	} while ((temp < 0) || (temp > N));
	*num = temp;
	do
	{
		printf("Vvedite kol-vo tovara \n");
		scanf("%d", &temp);
	} while ((temp < 0) || (temp > 1000));
	return temp;
}
void Opisanie(char** prod, int pr[], int opis[], int num, char** id)
{
	int i;
	printf("id ");
	for (i = 0; i < 4; i++)
		printf("%c", id[num][i]);
	printf(" %s cena %d opis %d \n", prod[num], pr[num], opis[num]);
}
void AddToCheck(int kol[], int num, int q)
{
	kol[num] += q;
	printf("Tovar dobavlen v check\n");
}
void Formir(int kol[], char** prod, int pr[], int opis[], char** id)
{
	int i, tov;
	int check = 0, total = 0;
	for (i = 0; i < N; i++)
	{
		if (kol[i] > 0)
		{
			Opisanie(prod, pr, opis, i, id);
			tov = kol[i] * pr[i] * (100 - opis[i]) / 100;
			printf("kol-vo %d total %d \n", kol[i], tov);
			check += (pr[i] * kol[i]);
			total += (pr[i] * kol[i] * (100 - opis[i]) / 100);
		}
	}
	if (check > 0)
	{
		i = (check - total) * 100 / check;
		printf("bez skidki %d skidka %d total %d \n", check, i, total);
	}
	else
		printf("Check pust\n");
}
void main()
{
	int num = 0, i, q;
	int kol[N] = { 0 }, pr[N], opis[N];
	char** prod = (char**)malloc(sizeof(char*) * N);
	char** id = (char**)malloc(sizeof(char*) * N);
	for (i = 0; i < N; i++)
	{
		switch (i % 10) {
		case 0:
			prod[i] = (char*)malloc(sizeof(char) * 4);
			prod[i] = "Packet";
			break;
		case 1:
			prod[i] = (char*)malloc(sizeof(char) * 4);
			prod[i] = "Moloko";
			break;
		case 2:
			prod[i] = (char*)malloc(sizeof(char) * 5);
			prod[i] = "Hleb";
			break;
		case 3:
			prod[i] = (char*)malloc(sizeof(char) * 3);
			prod[i] = "Jaitso";
			break;
		case 4:
			prod[i] = (char*)malloc(sizeof(char) * 5);
			prod[i] = "Kolbasa";
			break;
		case 5:
			prod[i] = (char*)malloc(sizeof(char) * 5);
			prod[i] = "Jabloko";
			break;
		case 6:
			prod[i] = (char*)malloc(sizeof(char) * 4);
			prod[i] = "Myaso";
			break;
		case 7:
			prod[i] = (char*)malloc(sizeof(char) * 4);
			prod[i] = "Riba";
			break;
		case 8:
			prod[i] = (char*)malloc(sizeof(char) * 4);
			prod[i] = "Orehi";
			break;
		case 9:
			prod[i] = (char*)malloc(sizeof(char) * 9);
			prod[i] = "Shokolad";
			break;
		}
		id[i] = (char*)malloc(sizeof(char) * 4);
		id[i][3] = i % 10 + '0';
		id[i][2] = (i / 10) % 10 + '0';
		id[i][1] = (i / 100) % 10 + '0';
		id[i][0] = (i / 1000) + '0';
	}
	Gener(pr, N, 1000.0);
	Gener(opis, N, 50.0);
	q = Scan(&num, id);
	do
	{
		Komanda();
		scanf("%d", &i);
		printf("\n");
		switch (i) {
		case 1:
			q = Scan(&num, id);
			break;
		case 2:
			Opisanie(prod, pr, opis, num, id);
			break;
		case 3:
			AddToCheck(kol, num, q);
			num++;
			break;
		case 4:
			Formir(kol, prod, pr, opis, id);
			break;
		case 5:
			Formir(kol, prod, pr, opis, id);
			break;
		default:
			printf("Nevernaya komanda\n");
		}
	} while (i != 5);
	for (i = 0; i < N; i++)
		free(prod[i]);
	free(prod);
	for (i = 0; i < N; i++)
		free(id[i]);
	free(id);
}