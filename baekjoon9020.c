#define _CRT_SECURE_NO_WARNINGS
#define true 1
#define false 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main() {
	int T, n, i,p1,p2;
	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		int j;
		scanf("%d", &n);
		int* arr = (int*)malloc(sizeof(int) * (n + 1));

		//에라토스테네스의 체
		arr[0] = arr[1] = false;
		for (j = 2; j <= n; j++) arr[j] = true;
		for (j = 2; j <= sqrt(n); j++) {
			if (arr[j]) {
				for (int k = j + j; k <= n; k += j)
					arr[k] = false;
			}
		}

		p1 = p2 = (n / 2);

		while (1) {
			if (p1 + p2 == n && arr[p1] && arr[p2]) {
				printf("%d %d\n", p1, p2);
				break;
			}
			p1--;
			p2++;
		}
		free(arr);
	}
	
}