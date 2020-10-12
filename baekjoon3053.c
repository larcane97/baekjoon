#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int R;
	scanf("%d", &R);
	double area1 = M_PI * R * R;
	double area2 = (4 * R * R) / (double)2;
	printf("%f\n%f\n", area1, area2);
	return 0;
}