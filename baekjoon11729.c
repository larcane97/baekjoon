#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi(int n, int from, int by, int to) {
	if (n == 1) {
		printf("%d %d\n", from, to);
	}
	else {
		hanoi(n - 1, from, to, by);
		printf("%d %d\n", from, to);
		hanoi(n - 1, by, from, to);
	}
}

void hanoiNum(int n, int from, int by, int to,int* k) {
	if (n == 1) {
		(*k)++;
	}
	else {
		hanoiNum(n - 1, from, to, by,k);
		(*k)++;
		hanoiNum(n - 1, by, from, to,k);
	}
}


int main() {
	int n, k = 0;
	scanf("%d", &n);
	hanoiNum(n, 1, 2, 3,&k);
	printf("%d\n", k);
	hanoi(n, 1, 2, 3);

}
