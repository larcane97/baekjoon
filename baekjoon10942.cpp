#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

char isPalin[2001][2001];
int arr[2001];


char dp(int s, int e) {
	char& ret = isPalin[s][e];
	if (ret != -1) return ret;
	if (s == e) return ret = 1;
	if (s + 1 == e) return ret = (arr[s] == arr[e]) ? 1 : 0;
	return ret = (dp(s + 1, e - 1) && arr[s] == arr[e]) ? 1 : 0;

}

void solve() {
	memset(isPalin, -1, sizeof(isPalin));
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", dp(a, b));
	}
}

int main() {
	solve();
}