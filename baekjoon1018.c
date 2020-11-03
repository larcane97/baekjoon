#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXBOARDSIZE 8
char boardFirstW[MAXBOARDSIZE][MAXBOARDSIZE];
char boardFirstB[MAXBOARDSIZE][MAXBOARDSIZE];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int i, j;
	for (i = 0; i < MAXBOARDSIZE; i++) {
		for (j = 0; j < MAXBOARDSIZE; j++) {
			if ((i + j) % 2 == 0) {
				boardFirstB[i][j] = 'B';
				boardFirstW[i][j] = 'W';
			}
			else {
				boardFirstB[i][j] = 'W';
				boardFirstW[i][j] = 'B';
			}
		}
	}

	char** board = (char**)malloc(sizeof(char*) * (1+n));
	for (i = 0; i < n; i++) {
		board[i] = (char*)malloc(sizeof(char) * (1+m));
	}

	int flush;
	for (i = 0; i < n; i++) {
			scanf("%s", board[i]);

	}

	int err1, err2,minErr=10000;


	int k, l;
	for (k = 0; k <= n - MAXBOARDSIZE; k++) {
		for (l = 0; l <= m - MAXBOARDSIZE; l++) {

			err1 = err2 = 0;
			for (i = 0; i < MAXBOARDSIZE; i++) {
				for (j = 0; j < MAXBOARDSIZE; j++) {
					if (board[k+i][l+j] != boardFirstB[i][j])
						err1++;
					if (board[k+i][l+j] != boardFirstW[i][j])
						err2++;
				}
			}
			if (minErr > err1)
				minErr = err1;
			if(minErr > err2)
				minErr = err2;
		}
	}
	
	printf("%d\n", minErr);
}

