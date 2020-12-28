#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0



void f(char check[],int ans[],int len, int n,int m,int index) {
	if (m > 0) {
		int i = 0;
		for (i = index; i < n; i++) {
			if (check[index]) {
				check[index] = false;
				ans[len++] = i + 1;
				f(check, ans, len, n, m - 1, i+ 1);
				check[index] = true;
				len--;
			}
		}
	}
	else{
		for (int i = 0; i < len; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
}

int main() {
	int n, m, i, j;
	scanf("%d %d", &n, &m);
	char* check = (char*)malloc(sizeof(char) * n);
	int* ans = (int*)malloc(sizeof(int) * n);
	int len = 0;
	for (i = 0; i < n; i++)
		check[i] = true;
	f(check, ans, 0, n, m,0);

}