#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void f(int i, int j, int num) {
	if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
		printf(" ");
	}
	else {
		if (num / 3 == 0)
			printf("*");
		else
			f(i, j, num / 3);
	}
}

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			f(i, j, num);
		printf("\n");
	}
}






//char mat[6600][6600];
//
//void f(int n, int x, int y) {
//	if (n == 1) {
//		mat[x][y] = '*';
//		return;
//	}
//	int nn = n / 3;
//	for (int i = 0; i < 3; i++) {
//		for (int j = 0; j < 3; j++) {
//			if (i == 1 && j == 1);
//			else 
//				f(nn, x + (i * nn), y + (j * nn));
//			
//		}
//	}
//
//}
//
//int main() {
//	memset(mat, ' ', sizeof(mat));
//	int n;
//	scanf("%d", &n);
//	f(n, 0, 0);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			printf("%c", mat[i][j]);
//		}
//		printf("\n");
//	}
//}