#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int price, s, kod, kolvo;
char naz;
int scan(int a) 
{


}
void main()
{
    while (kod != 0)
    {
        setlocale(LC_ALL, "Russian");
        printf("������� �����-���");
        scanf("%d", &kod);
        scan(kod);
        printf("%c - %d - %d", naz, price, kolvo);

    }


}