#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int arr[5][5];
int ret[5][5];
int n;
ll b;
const int c = 1000;
void arr_mul(int A[5][5],int B[5][5]) {
	int C[5][5],D[5][5];
	copy(&A[0][0], &A[0][0] + 25, &C[0][0]);
	copy(&B[0][0], &B[0][0] + 25, &D[0][0]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int tmp = 0;
			for (int k = 0; k < n; k++)
				tmp = (tmp + ( (C[i][k]%c)  * (D[k][j]%c) )%c)%c;
			ret[i][j] = tmp;
		}
}

void arr_pow(ll b) {
	if (b == 0) return;
	if (b == 1) {
		arr_mul(ret,arr);
		return;
	}

	if (b % 2 == 0) {
		arr_pow(b / 2);
		arr_mul(ret, ret);
	}
	else {
		arr_pow(b / 2);
		arr_mul(ret, ret);
		arr_mul(arr, ret);
	}
	return;
}


void solve() {
	scanf("%d %lld", &n, &b);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &arr[i][j]);

	memset(ret, 0, sizeof(ret));
	for (int i = 0; i < n; i++)
		ret[i][i] = 1;

	arr_pow(b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d ", ret[i][j]);
		printf("\n");
			
	}
}

int main() {
	solve();
}