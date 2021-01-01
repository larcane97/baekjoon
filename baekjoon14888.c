#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000000
#define MIN -1000000000

int max = MIN;
int min = MAX;

void f(int* arr,int* selected, int* object,int n,int i) {
	if (i < n-1) {
		for (int k = 0; k < 4; k++) {
			if (object[k] != 0) {
				selected[i] = k;
				object[k]--;
				f(arr, selected, object, n, i + 1);
				object[k]++;
			}
		}
	}
	else {
		int sum = arr[0];
		for (int k = 0; k < n-1; k++) {
			switch (selected[k]) {
			case 0 :
				sum += arr[k + 1];
				break;
			case 1 :
				sum -= arr[k + 1];
				break;
			case 2 :
				sum *= arr[k + 1];
				break;
			case 3:
				sum /= arr[k + 1];
				break;
			}
		}
		if (max < sum)
			max = sum;
		if (min > sum)
			min = sum;
	}
}

int main() {
	int i, n;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	int* selected = (int*)malloc(sizeof(int) * (n - 1));
	int object[4];
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < 4; i++)
		scanf("%d", &object[i]);
	f(arr, selected, object, n, 0);
	printf("%d\n%d\n", max, min);

}