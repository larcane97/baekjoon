#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solve() {
	int n;
	scanf("%d", &n);
	priority_queue<int>pq;
	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		if (a != 0) {
			pq.push(-a);
		}
		else {
			if (pq.empty())
				printf("%d\n", 0);
			else {
				printf("%d\n", -pq.top());
				pq.pop();
			}
		}
	}
	return;
}

int main() {
	solve();
}