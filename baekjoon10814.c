#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 101

typedef struct Array {
	int age;
	char name[MAXLEN];
}Array;

// couting sort
int main() {
	int n, i, j;
	scanf("%d", &n);
	Array* arr = (Array*)malloc(sizeof(Array) * n);
	Array* A = (Array*)malloc(sizeof(Array) * (n+1));
	int B[201];

	for (i = 1; i <= 200; i++)
		B[i] =0;
	for (i = 0; i < n; i++) {
		scanf("%d %s", &(arr[i].age), arr[i].name);
		B[arr[i].age]++;
	}
	for (i = 2; i <= 200; i++)
		B[i] = B[i - 1] + B[i];
	for (i = n - 1; i >= 0; i--) {
		A[B[arr[i].age]] = arr[i];
		B[arr[i].age]--;
	}

	for (i = 1; i <= n; i++) {
		printf("%d %s\n", A[i].age, A[i].name);
	}
	return 0;
}