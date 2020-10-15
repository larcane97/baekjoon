#define _CRT_SECURE_NO_WARNIGNS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char mat[6600][6600];

void f(int n, int x, int y) {
	if (n == 1) {
		mat[x][y] = '*';
		return;
	}
	int nn = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1);
			else 
				f(nn, x + (i * nn), y + (j * nn));
			
		}
	}

}

int main() {
	memset(mat, ' ', sizeof(mat));
	int n;
	scanf("%d", &n);
	f(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
}