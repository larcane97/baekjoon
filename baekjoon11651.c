#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define inf 100001
typedef struct point {
	int x;
	int y;
}point;



void merge(point* arr, int p, int q, int r) {
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;
	point* L = (point*)malloc(sizeof(point) * (1 + n1));
	point* R = (point*)malloc(sizeof(point) * (1 + n2));
	for (i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[q + j + 1];
	point tmp = { inf,inf };
	L[i] = R[j] = tmp;
	i = j = 0;
	for (k = p; k <= r; k++) {
		if (L[i].y < R[j].y || (L[i].y == R[j].y && L[i].x < R[j].x)) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
	}
	return;
}

void merge_sort(point* arr, int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sort(arr, p, q);
		merge_sort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}


int main() {
	int i,j,n;
	scanf("%d", &n);
	point* p = (point*)malloc(sizeof(point) * n);
	for (i = 0; i < n; i++) {
		point a;
		scanf("%d %d", &(a.x), &(a.y));
		p[i] = a;
	}
	merge_sort(p, 0, n - 1);
	for (i = 0; i < n; i++) {
		printf("%d %d\n", p[i].x, p[i].y);
	}
}