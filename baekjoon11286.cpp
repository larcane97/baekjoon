#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	priority_queue<pair<int, int>>pq;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a != 0) {
			int type = a > 0 ? -1 : 1;
			pq.push(make_pair(-abs(a), type));
		}
		else {
			if (pq.empty())
				printf("%d\n", 0);
			else {
				printf("%d\n", pq.top().first * pq.top().second);
				pq.pop();
			}
		}
	}
}

int main() {
	solve();
}