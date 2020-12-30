#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define false 0
#define true 1

/*
void f(char** mat,int i,int n,int* count) {
	if (i < n) {
		int j = 0;
		for (j = 0; j < n; j++) {
			if (!mat[i][j]) {
				
				int k,l;
				//아래방향
				for (k = i + 1; k < n; k++)
					mat[k][j]++;
				//왼쪽아래 대각
				k = i + 1, l = j - 1;
				while (k <n && l >= 0) {
					mat[k][l]++;
					k++, l--;
				}
				//오른쪽아래 대각
				k = i + 1, l = j + 1;
				while(k < n&& l < n) {
					mat[k][l]++;
					k++, l++;
				}
				f(mat, i + 1, n,count);
				for (k = i + 1; k < n; k++)
					mat[k][j]--;
				//왼쪽아래 대각
				k = i + 1, l = j - 1;
				while (k<n && l >= 0) {
					mat[k][l]--;
					k++, l--;
				}
				//오른쪽아래 대각 
				k = i + 1, l = j + 1;
				while (k < n && l < n) {
					mat[k][l]--;
					k++, l++;
				}
			}
		}
	}
	else {
		(*count) += 1;
	}
}

int main() {
	int i,j,n;
	scanf("%d", &n);
	char** mat = (char**)malloc(sizeof(char*) * n);
	for (i = 0; i < n; i++) {
		mat[i] = (char*)malloc(sizeof(char) * n);
		for (j = 0; j < n; j++)
			mat[i][j] = 0;
	}

	int count = 0;
	f(mat, 0, n,&count);
	printf("%d", count);

}
*/

#include <math.h>

int ans = 0;

char check(char* B,int row,int col) {
	for (int k = 0; k < row; k++) {
		if (B[k] == col || abs(B[k] - col) == abs(k - row))
			return false;
	}
	return true;
}

void nQueen(char* B, int i,int row, int col) {
	if (i < row) {
		for (int j = 0; j <col; j++) {
			if (check(B,i,j)) {
				B[i] = j;
				nQueen(B, i + 1, row, col);
			}
		}

	}
	else ans++;

}


int main() {
	int n;
	scanf("%d", &n);
	char* B = (char*)malloc(sizeof(char) * n);
	nQueen(B, 0, n, n);
	printf("%d", ans);
}