#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int A[100][100];
int B[100][100];
int n, m, k;

void calc_one_row(int row) {
	for (int i = 0; i < k; i++) {
		int ret=0;
		for (int j = 0; j < m; j++)
			ret += A[row][j] * B[j][i];
		printf("%d ", ret);
	}
}

void solve() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &A[i][j]);
	scanf("%d %d", &m, &k);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++)
			scanf("%d", &B[i][j]);

	for (int i = 0; i < n; i++) {
		calc_one_row(i);
		printf("\n");
	}
}



int main() {
	solve();
}