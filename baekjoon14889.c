#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define false 0
#define true 1

int f(char** arr,char* check,int prev,int cur,int n,int count,int sum){
	static int result = 10000;
	if (count < n / 2) {
		check[cur] = true;
		if (count%2==1) {
			int k;
			for (k = 0; k < n; k++) {
				if (k != cur && !check[k]) {
					f(arr, check,cur,k, n,count+1,sum);
					check[k] = false;
				}
			}
		}
		else { // sw== true
			sum += arr[cur][prev];
			sum += arr[prev][cur];
			f(arr, check, prev, cur, n, count + 1, sum);
		}
	}
	else {
		
	}
}


int main() {
	int n, i, j, sum=0;
	scanf("%d", &n);
	char** arr = (char**)malloc(sizeof(char*) * n);
	char* check = (char*)malloc(sizeof(char) * n);
	for (i = 0; i < n; i++) {
		check[i]= false;
		arr[i] = (char*)malloc(sizeof(char) * n);
		for (j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			sum += arr[i][j];
		}
	}

}