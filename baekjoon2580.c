#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 9
#define false 0
#define true 1

int print = false;
void f(int arr[SIZE + 1][SIZE + 1], int row[SIZE + 1][SIZE + 1],
	int col[SIZE + 1][SIZE + 1],
	int squre[SIZE + 1][SIZE + 1],int z) {
	if (z <= SIZE*SIZE) {
		int i, j,l;
		if (z % 9 == 0) {
			i = z / SIZE, j = 9;
		}
		else {
			i = z / SIZE + 1, j = z % SIZE;
		}
		l = ((z-1) % SIZE) / 3 + ((i - 1) / 3) * 3 + 1;
		if (arr[i][j]==0) {
			int k;
			for (k = 1; k <= SIZE; k++) {
				if (!row[i][k] && !col[j][k] && !squre[l][k]) {
					row[i][k] = col[j][k] = squre[l][k] = true;
					arr[i][j] = k;
					f(arr, row, col, squre, z + 1);
					row[i][k] = col[j][k] = squre[l][k] = false;
					arr[i][j] = 0;
				}
			}
		}
		else f(arr, row, col, squre, z + 1);
	}
	else {
		if (!print) {
			print = true;
			for (int i = 1; i <= SIZE; i++) {
				for (int j = 1; j <= SIZE; j++)
					printf("%d ", arr[i][j]);
				printf("\n");
			}
		}
	}
}

int main() {
	int i, j;
	int arr[SIZE + 1][SIZE + 1];
	int row[SIZE + 1][SIZE + 1];
	int col[SIZE + 1][SIZE + 1];
	int squre[SIZE + 1][SIZE + 1];

	for (i = 1; i <= SIZE; i++) {
		for (j = 1; j <= SIZE; j++) {
			row[i][j] = false;
			col[i][j] = false;
			squre[i][j] = false;
		}
	}
	for (i = 1; i <= SIZE; i++) {
		for (j = 1; j <= SIZE; j++) {
			scanf("%d", &arr[i][j]);
			row[i][arr[i][j]] = true;
			col[j][arr[i][j]] = true;
			
			squre[((i-1)/3)+((j-1)/3)+1 + ((i-1)/3)*2 ][arr[i][j]] = true;
		}
	}
	f(arr, row, col, squre, 1);
}
