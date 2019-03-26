#include "funcs.c"

void main()
{
	setlocale(LC_ALL, "Russian");
	int raz;
	int count = 100;
	printf("Vvedite razm.");
	scanf("%d", &raz);
	Vector *testVector = (Vector*)malloc(count * sizeof(Vector));
	testVector = (Vector*)realloc(testVector, raz * sizeof(Vector));
	acos((x1*x2) / (d1*d2));

}