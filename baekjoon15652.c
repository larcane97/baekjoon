#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

void f(int n, int m, int ans[],int len,int index) {
	if (m > 0) {
		for (int i = index; i < n; i++) {
			ans[len] = i + 1;
			len++;
			f(n, m - 1, ans, len, i);
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
	int i,n, m;
	scanf("%d %d", &n, &m);
	int ans = (int*)malloc(sizeof(int) * n);
	f(n, m, ans, 0,0);
}