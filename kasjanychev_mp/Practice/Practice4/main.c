#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define N 100

void nums(char **kods, char **names)
{
    kods = (char**)malloc(sizeof(char*) * 5);
    kods[0] = (char*)malloc(sizeof(char) * 4);
    kods[0] = "4368";
    kods[1] = (char*)malloc(sizeof(char) * 4);
    kods[1] = "7436";
    kods[2] = (char*)malloc(sizeof(char) * 4);
    kods[2] = "6510";
    kods[3] = (char*)malloc(sizeof(char) * 4);
    kods[3] = "0137";
    kods[4] = (char*)malloc(sizeof(char) * 4);
    kods[4] = "6479";
    names = (char**)malloc(sizeof(char*) * 5);
    names[0] = (char*)malloc(sizeof(char) * 6);
    names[0] = "moloko";
    names[1] = (char*)malloc(sizeof(char) * 2);
    names[1] = "hl";
    names[2] = (char*)malloc(sizeof(char) * 3);
    names[2] = "kol";
    names[3] = (char*)malloc(sizeof(char) * 2);
    names[3] = "sr";
    names[4] = (char*)malloc(sizeof(char) * 2);
    names[4] = "sk";
}
void scan(char *a, char** kods, char** names, char* tov) 
{
    int i;
    for (i = 0; i < 5; i++)
    {
        if (strcmp(a, kods[i]) == 0) tov = names[i];
    }
}
void Tov(char *b, char* naz, char* skd, int* price, double* sale)
{
    if (strcmp(b, "moloko") == 0)
    {
        naz = "Молоко";
        price = 50;
        *sale = 0.25;
        skd = "25%";
    }
    if (strcmp(b, "hl") == 0)
    {
        naz = "Хлеб";
        price = 25;
        *sale = 0.5;
        skd = "50%";
    }
    if (strcmp(b, "kol") == 0)
    {
        naz = "Колбаса";
        price = 100;
       *sale = 0.35;
        skd = "35%";
    }
    if (strcmp(b, "sr") == 0)
    {
        naz = "Сыр";
        price = 150;
        *sale = 0.15;
        skd = "15%";
    }
    if (strcmp (b, "sk") == 0)
    {
        naz = "Сок";
        price = 85;
        *sale = 0.1;
        skd = "10%";
    }
}
void main()
{
    int price;
    char* kod = "1";
    double s = 0;
    double sale;
    char* naz, tov, skd;
    naz = (char*)malloc(sizeof(char) * 6);
    tov = (char*)malloc(sizeof(char) * 4);
    skd = (char*)malloc(sizeof(char) * 2);
    char** n = (char**)malloc(sizeof(char*) * N);
    double l[N];
    int c[N];
    double x[N];
    int i, j, z = 0;
    char **kods;
    char **names;
    i = 0;
    j = 0;
    setlocale(LC_ALL, "Russian");
    nums(kods, names);
    do
    {
        printf("Введите штрих-код\n");
        scanf("%s", &kod);
        scan(kod, kods, names, tov);
        Tov(tov, naz, skd, price, &sale);
        printf("%s - %d\n", naz, price);
        n[i] = naz;
        l[i] = price*sale;
        c[i] = 1;
        i++;
        for (j = 0; j < i; j++)
        {
            if (strcmp(n[i], n[j]) == 0)
            {
                c[j]++;
                i--;
            }
        }
        z = i;
    } while (strcmp(*kod, "0") != 0);
    for (i = 0; i <= z; i++)
    {
        x[i] = l[i] * c[i];
        s = s + x[i];
    }
    printf("Чек:\n");
    for (i = 0; i <= z; i++)
    {
        printf("%s - %lf - %d - %lf\n", n[i], l[i], c[i], x[i]);
    }
    printf("ИТОГО:\n %lf", s);
}