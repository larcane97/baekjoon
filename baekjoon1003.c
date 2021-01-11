#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}point;

point arr[41];

void f(int n) {
	if (n == 0) {
		point a = { 1,0 };
		arr[0] = a;
		return;
	}
	if (n == 1) {
		point a = { 0,1 };
		arr[1] = a;
		return;
	}
	else {
		point a = arr[n - 1];
		point b = arr[n - 2];
		point c = { arr[n-1].x + arr[n-2].x,arr[n-1].y + arr[n-2].y };
		arr[n] = c;
		return;
	}
}

int main() {
	for (int i = 0; i <= 40; i++) {
		f(i);
	}

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int w;
		scanf("%d", &w);
		printf("%d %d\n", arr[w].x, arr[w].y);
	}
}