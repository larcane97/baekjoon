#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int i, j = 0;
	short tmp;
	short* c = (short*)malloc(sizeof(short) * (10001));
	for (i = 0; i < 10001; i++)
		c[i] = 0;

	for (i = 0; i < n; i++) {
		scanf("%hd", &tmp);
		c[tmp]++;
	}
	
	for (i = 0; i < 10001; i++) {
		while (c[i] != 0) {
			printf("%d\n",i);
			c[i]--;
		}
	}
	return 0;

}