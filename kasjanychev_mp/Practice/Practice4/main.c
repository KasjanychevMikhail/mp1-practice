#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 100
int price;
int kod = 1;
double s = 0;
double sale;
char naz, tov, skd;
char n[N];
double l[N];
int c[N];
double x[N];
int i, j, z = 0;
void scan(char a) 
{
    if (a == '1001') tov = "moloko";
    if (a == '1048') tov = "hl";
    if (a == '7301') tov = "kol";
    if (a == '6403') tov = "sr";
    if (a == '3746') tov = "sk";
}
void Tov(char b)
{
    if (b == "moloko")
    {
        naz = "Молоко";
        price = 50;
        sale = 0.25;
        skd = "25%";
    }
    if (b == "hl")
    {
        naz = "Хлеб";
        price = 25;
        sale = 0.5;
        skd = "50%";
    }
    if (b == "kol")
    {
        naz = "Колбаса";
        price = 100;
        sale = 0.35;
        skd = "35%";
    }
    if (b == "sr")
    {
        naz = "Сыр";
        price = 150;
        sale = 0.15;
        skd = "15%";
    }
    if (b == "sk")
    {
        naz = "Сок";
        price = 85;
        sale = 0.1;
        skd = "10%";
    }
}
void main()
{
    while (kod != 0)
    {
        setlocale(LC_ALL, "Russian");
        printf("Введите штрих-код\n");
        scanf("%d", &kod);
        scan(kod);
        Tov(tov);
        printf("%s - %d\n", naz, price);
        n[i] = naz;
        l[i] = price*sale;
        c[i] = 1;
        i++;
        for (j = 0; j < i; j++)
        {
            if (n[i] == n[j])
            {
                c[j]++;
                i--;
            }
        }
        z = i;
    }
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