#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n,i,j,tmp;
	double avg;
	int mid, fre, range;
	j = 0;
	scanf("%d", &n);

	// counting sort
	// range : -4000 ~ 4000 -> 0 ~ 8000
	int* A = (int*)malloc(sizeof(int) * n);
	int* B = (int*)malloc(sizeof(int) * 8001);
	for (i = 0; i <= 8000; i++) {
		B[i] = 0;
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &tmp);
		B[tmp+4000]++;
	}

	// sw : variable for checking second frequent number.
	// freCount : variable for storing frequent number's index.
	int sw = 0;
	int freCount = 0;
	for (i = 0; i <= 8000; i++) {
		if (freCount < B[i]) {
			freCount = B[i];
			fre = i - 4000;
			sw = 0;
		}
		else if (freCount == B[i] && sw == 0) {
			fre = i - 4000;
			sw = 1;
		}
	}

	// tmp : variable to acumulately store each values for calculating average.
	tmp = 0;
	for (i = 0; i <= 8000; i++) {
		while (B[i] != 0) {
			A[j++] = i - 4000;
			B[i]--;
			tmp += i - 4000;
		}
	}
	mid = A[n / 2];
	range = A[n - 1] - A[0];
	avg = (double)tmp / n;

	printf("%.0f\n%d\n%d\n%d\n", avg, mid, fre, range);

}