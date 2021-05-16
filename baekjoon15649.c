#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define false 0
#define true 1
#define MAXLEN 9

int ans[MAXLEN];
int len;

void f(int* arr, int n, int m) {
	if (m >= 1) {
		for (int i = 1; i <= n; i++) {
			if (arr[i]) {
				arr[i] = false;
				ans[len++] = i;
				//printf("%d ", i);
				f(arr, n, m - 1);
				len--;
				arr[i] = true;
			}
		}
	}
	else {
		for (int i = 0; i < len; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
}

int main() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	int* arr = (int*)malloc(sizeof(int) * (n + 1));
	for (i = 1; i <= n; i++)
		arr[i] = true;
	f(arr,n, m);
}