#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

void f(int n, int m, char check[], int ans[], int len) {
	if (m > 0) {
		for (int i = 0; i < n; i++) {
			ans[len] = i + 1;
			len++;
			f(n, m - 1, check, ans, len);
			len--;
		}
	}
	else {
		for (int i = 0; i < len; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
}


int main() {
	int i, n, m;
	scanf("%d %d", &n, &m);
	char* check = (char*)malloc(sizeof(char) * n);
	int ans = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		check[i] = true;
	f(n, m, check, ans, 0);
}