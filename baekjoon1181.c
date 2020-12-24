#define _CRT_SECURE_NO_WARNINGS
#define MAXLEN 50

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Array {
	char string[MAXLEN];
	int len;
}Array;



void merge(Array* arr, int first, int mid,int end) {
	int i, j,k;
	int n1 = mid - first+1;
	int n2 = end - mid;
	Array* left = (Array*)malloc(sizeof(Array) * (n1 + 1));
	Array* right = (Array*)malloc(sizeof(Array) * (n2 + 1));
	for (i = 0; i < n1; i++) {
		left[i] = arr[i + first];
	}
	for (j = 0; j < n2; j++) {
		right[j] = arr[mid + 1 + j];
	}
	left[i].len = 20001;
	right[j].len = 20001;
	i = j = 0;
	for (k = first; k <= end; k++) {
		int c = 0;
		if (left[i].len < right[j].len) {
			arr[k] = left[i];
			i++;
			continue;
		}
		if (left[i].len > right[j].len) {
			arr[k] = right[j];
			j++;
			continue;
		}
		while (c < left[i].len && left[i].string[c] == right[j].string[c])
			c++;
		if (left[i].string[c] <=right[j].string[c]) {
			arr[k] = left[i];
			i++;
		}
		else if (left[i].string[c] > right[j].string[c]) {
			arr[k] = right[j];
			j++;
		}
	}
	free(left); free(right);
}

void merge_sort(Array* arr, int first, int end) {
	if (first < end) {
		int mid = (first + end) / 2;
		merge_sort(arr, first, mid);
		merge_sort(arr, mid + 1, end);
		merge(arr, first, mid, end);
	}
}


int main() {
	int n, i;
	scanf("%d", &n);
	Array* arr = (Array*)malloc(sizeof(Array) * n);
	for (i = 0; i < n; i++) {
		scanf("%s", arr[i].string);
		arr[i].len = strlen(arr[i].string);
	}
	merge_sort(arr, 0, n - 1);
	for (i = 0; i < n; i++) {
		if (i == 0 || strncmp(arr[i].string, arr[i - 1].string, arr[i].len))
			printf("%s\n", arr[i].string);
	}
	free(arr);
	return 0;
}