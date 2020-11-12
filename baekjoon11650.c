#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	int x;
	int y;
}point;

#define inf 1000000

void mergeX(point arr[], int p, int r) {
	int i, j, k;
	int q = (p + r) / 2;
	int n1 = q - p + 1;
	int n2 = r - q;
	point* L = (point*)malloc((n1 + 1) * sizeof(point));
	point* R = (point*)malloc((n2 + 1) * sizeof(point));
	for (i = 0; i < n1; i++) {
		L[i] = arr[p + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[q + j + 1];
	}
	L[n1].x = inf;
	R[n2].x = inf;
	L[n1].y = inf;
	R[n2].y = inf;
	i = j = 0;
	for (k = p; k < r + 1; k++) {
		if (L[i].x <= R[j].x) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
	}
	free(L); free(R);
}

void merge_sortX(point arr[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sortX(arr, p, q);
		merge_sortX(arr, q + 1, r);
		mergeX(arr, p, r);
	}
}

void mergeY(point arr[], int p, int r) {
	int i, j, k;
	int q = (p + r) / 2;
	int n1 = q - p + 1;
	int n2 = r - q;
	point* L = (point*)malloc((n1 + 1) * sizeof(point));
	point* R = (point*)malloc((n2 + 1) * sizeof(point));
	for (i = 0; i < n1; i++) {
		L[i] = arr[p + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[q + j + 1];
	}
	L[n1].x = inf;
	R[n2].x = inf;
	L[n1].y = inf;
	R[n2].y = inf;
	i = j = 0;
	for (k = p; k < r + 1; k++) {
		if (L[i].y <= R[j].y) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
	}
	free(L); free(R);
}

void merge_sortY(point arr[], int p, int r) {
	if (p < r) {
		int q = (p + r) / 2;
		merge_sortY(arr, p, q);
		merge_sortY(arr, q + 1, r);
		mergeY(arr, p, r);
	}
}

int main() {
	int i,n;
	scanf("%d", &n);
	point* a = (point*)malloc(sizeof(point) * n);
	for (i = 0; i < n; i++) {
		scanf("%d %d", &(a[i].x), &(a[i].y));
	}

	merge_sortY(a, 0, n - 1);
	merge_sortX(a, 0, n - 1);
	for (i = 0; i < n; i++) {
		printf("%d %d\n", a[i].x,a[i].y);
	}
	free(a);
	return 0;


}