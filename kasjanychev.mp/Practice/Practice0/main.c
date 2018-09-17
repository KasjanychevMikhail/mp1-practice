#include <stdio.h>
#include <math.h>
void main() {
	double a1, b1, a2, b2, r1, r2;
	printf("Vvedite a1,a2,b1,b2,r1,r2");
	scanf("%lf %lf %lf %lf %lf %lf", &a1, &a2, &b1, &b2, &r1, &r2);
	if ((a1 == a2) && (b1 == b2) && (r1 == r2)) {
		printf("Okruzhnosti sovpadayut");
		return;
	}
	if (sqrt((a1 - a2)*(a1 - a2) + (b1 - b2)*(b1 - b2)) < (r1 + r2)){
		printf("Okruzhnosti peresekayutsya");
	return;
    }
	if (sqrt((a1 - a2)*(a1 - a2) + (b1 - b2)*(b1 - b2)) == (r1 + r2)) {
		printf("Okruzhnosti kasayutsya vneshne");
		return;
	}
	if (sqrt((a1 - a2)*(a1 - a2) + (b1 - b2)*(b1 - b2)) > (r1 + r2)) {
		printf("Okruzhnosti ne peresekayutsya i ne lezhat drug v druge");
		return;
	}
	if ((sqrt((a1 - a2)*(a1 - a2) + (b1 - b2)*(b1 - b2)) < r1) || (sqrt((a1 - a2)*(a1 - a2) + (b1 - b2)*(b1 - b2)) < r2))
		printf("Okruzhnostilezhat drug v druge i ne kasayutsya drug druga");
	return;
	if ((sqrt((a1 - a2)*(a1 - a2) + (b1 - b2)*(b1 - b2)) + r1 == r2) || (sqrt((a1 - a2)*(a1 - a2) + (b1 - b2)*(b1 - b2)) + r2 == r1))
		printf("Okruzhnosti kasayutsya vntutri");
	return;
	}
}