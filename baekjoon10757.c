#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	char A[100000], B[100000];
	char C[100001];
	scanf("%s %s", A, B);
	int i = 0, j = 0 , k = 0;
	while (A[i] != NULL)
		i++;
	while (B[j] != NULL)
		j++;
	i--, j--;
	int sw = 0;
	int a;
	while (i>=0 || j>=0) {
		if(i>=0 && j>=0)
			a = (A[i] - 48) + (B[j] - 48);
		else {
			if (i < 0)
				a = B[j] - 48;
			if (j < 0)
				a = A[i] - 48;
		}

		if (sw) {
			a += 1;
			sw = 0;
		}

		if (a < 10) {
			C[k] = a;
		}
		else {
			C[k] = a % 10;
			sw = 1;
		}
		i--, j--, k++;
	}
	if (sw)
		C[k] = 1;
	else k--;

	for (k; k >= 0; k--)
		printf("%d", C[k]);
	
	return 0;

}