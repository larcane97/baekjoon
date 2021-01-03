#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	while (n > 1) {
		int i;
		for (i = 2; i <=n; i++) {
			if (n % i == 0) {
				printf("%d\n", i);
				n = n / i;
				break;
			}
		}
	}
}